/*
 * src_game_new_start.c
 *
 *  Created on: 2012/12/13
 *      Author: Lue
 */

#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"
#include "header_value_walk.h"
#include "header_Walk.h"
#include "header_Cfont.h"

int Start (int Map[2],int Char[4][4],int people[4])
{
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap ("image\\MAP\\BIGMAP.bmp",NULL);//°¨¸ô
	BITMAP *Not = load_bitmap ("image\\MAP\\BIGMAPRED.bmp",NULL);//»ÙÃªª«
	FILE *speak_source = fopen("Speak\\Start.txt","r");
	Character role;
	peoplework_chang (people,&role);
	int KEY[55] = {UP,LEFT,LEFT,LEFT,LEFT,
			LEFT,LEFT,LEFT,LEFT,LEFT,
			LEFT,LEFT,LEFT,LEFT,LEFT,
			LEFT,LEFT,LEFT,LEFT,LEFT,
			LEFT,LEFT,LEFT,LEFT,LEFT,
			LEFT,LEFT,LEFT,LEFT,LEFT,
			LEFT,LEFT,LEFT,LEFT,LEFT,
			DOWN,DOWN,DOWN,DOWN,DOWN,
			DOWN,DOWN,DOWN,DOWN,DOWN,
			DOWN,DOWN,LEFT,LEFT,LEFT,
			LEFT,RIGHT,RIGHT,RIGHT,RIGHT
	};
	int i = 0;
	int OVER = WIN;
	printf("Start\n");
	fflush(stdout);

	for (i = 0;i < 3;i++)
	{
		clear_to_color(butter,makecol(0,0,0));
		print_cfont(speak_source,butter,150,200,255,255,255,i);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		while (!key[KEY_SPACE]){}
		rest(250);
	}
	Speak_function (40);

	while (!key[KEY_SPACE]){}
	for (i = 0;i < 11;i++)
	{
		rest(50);
		Walking(Map,Char,role,background,Not,KEY[i]);
	}

	OVER = Dog_GoToLEFT(people);
	if (OVER == WIN)
	{
		for (;i < 51;i++)
		{
			rest(50);
			Walking(Map,Char,role,background,Not,KEY[i]);
		}
		people[1] = EE;
		Speak_function (41);
		for (;i < 55;i++)
		{
			rest(50);
			Walking(Map,Char,role,background,Not,KEY[i]);
		}
		OVER = Dog(people);
	}


	destroy_bitmap (butter);
	destroy_bitmap (background);
	destroy_bitmap (Not);

	return OVER;
}
