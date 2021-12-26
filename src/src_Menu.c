#include <allegro.h>
#include "header_System.h"
#include "header_S_value.h"
#include "header_value_walk.h"
int Start (int Map[2],int Char[4][4],int people[4]);

PALETTE pal;

int Main_Menu ()
{
	int Choose = 1;
	int OVER = yes;
	int map_number = BigMap;
	int Char[4][4] = {{SQ_SIDE-16,SQ_SIDE-16,UP,-1},{SQ_SIDE-16,SQ_SIDE-16,UP,-1},{SQ_SIDE-16,SQ_SIDE-16,UP,-1},{SQ_SIDE-16,SQ_SIDE-16,UP,-1}};//X.Y.面向.輸入的指令(下一個面向)
	int Map[2] = {42*32-16,10*32-16};//{1920-16,1600 - SQ_SIDE/2};
	int people[4] = {captain,NoOne,NoOne,NoOne};
	int EvenMain[EvenALL];
//	SAMPLE *Music_Main;
//	Music_Main = load_sample( "VOICE/02 - zero-project - 02 - Touch of serenity.wav"); 
//	play_sample( Music_Main, 255, 0, 1000, 1);


	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *Menu_W = load_bitmap("image\\system\\NUK.bmp",NULL);
	BITMAP *Menu_R = load_bitmap("image\\system\\NUK02.bmp",NULL);

	blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (Menu_R, butter, 0, Main_menu, 0, Main_menu, SCREEN_W, Main_menu_choose);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	rest(100);
	while (!key[KEY_SPACE])
	{
		rest(50);
		if (key[KEY_UP])
		{
			Choose = Choose - 1;
			if (Choose < 1)
			{Choose = 1;}
		}
		if (key[KEY_DOWN])
		{
			Choose = Choose + 1;
			if (Choose > 3)
			{Choose = 3;}
		}
		if((key[KEY_F10]) || (close_button_pressed == TRUE )){
			exit(0);
		}
//		if (key[KEY_P])
//		{save_bitmap("dump.bmp", screen, pal);}
		blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		blit (Menu_R, butter, 0, Main_menu + Main_menu_choose * (Choose - 1), 0, Main_menu + Main_menu_choose * (Choose - 1), SCREEN_W, Main_menu_choose);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	}
//	stop_sample(Music_Main);
//	destroy_sample (Music_Main);
	switch(Choose)
	{
		case 1:
			EvenMain_init (EvenMain);
			OVER = Start (Map,Char,people);
			if (OVER == WIN)
			{map_change(&map_number,Map,Char,people,EvenMain);}
			else
			{OVER = yes;}
			break;
		case 2:
			Load (&map_number,Map,Char,people,EvenMain);
			map_change(&map_number,Map,Char,people,EvenMain);
			break;
		case 3:
			OVER = no;
			break;
	}
	return OVER;
}


int Menu (int map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{
	int OVER = no;
	int Choose = 1;
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *Menu_W = load_bitmap("image\\system\\menu.bmp",NULL);
	BITMAP *Menu_R = load_bitmap("image\\system\\menu02.bmp",NULL);

	blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (Menu_R, butter, 0, Sub_menu, 0, Sub_menu, SCREEN_W, Sub_menu_choose);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	while (!key[KEY_SPACE])
	{
		rest(50);
		if (key[KEY_UP])
		{
			Choose = Choose - 1;
			if (Choose < 1)
			{Choose = 1;}
		}
		if (key[KEY_DOWN])
		{
			Choose = Choose + 1;
			if (Choose > 4)
			{Choose = 4;}
		}
		if((key[KEY_F10]) || (close_button_pressed == TRUE )){
			exit(0);
		}
//		if (key[KEY_P])
//		{save_bitmap("dump.bmp", screen, pal);}
		blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		blit (Menu_R, butter, 0, Sub_menu + Sub_menu_choose * (Choose - 1), 0, Sub_menu + Sub_menu_choose * (Choose - 1), SCREEN_W, Sub_menu_choose);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	}
	switch(Choose)
	{
		case 1:
			break;			//Back;
		case 2:
			Save (map_number,Map,Char,people,EvenMain);
			break;
		case 3:
			Load (&map_number,Map,Char,people,EvenMain);
			OVER = map_number;
			break;
		case 4:
			OVER = yes;
			break;
	}
	return OVER;
}
