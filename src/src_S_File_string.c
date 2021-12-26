/*
 * src_S_File_string.c
 *
 *  Created on: 2012/10/2
 *      Author: Lue
 */
#include "header_S_value.h"
#include "header_System.h"
#include "header_value_walk.h"
#include "header_S_File_string.h"
#include "header_Walk.h"

void Load_Save (int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);

PALETTE pal;

int Change_MAP_NUM (int MAP_NUM)
{
	int map = -1;
	switch(MAP_NUM)
	{
		case BigMap:
			map = bigmap;
			break;
		case CO1:
			map = co1;
			break;
		case CO1_4:
			map = co1_4;
			break;
		case CO1_4flab:
			map = co1_4flab;
			break;
		case CO1_b1:
			map = co1_b1;
			break;
		case CO2:
			map = co2;
			break;
		case BO1:
			map = bo1;
			break;
		case BO1_R:
			map = bo1_r;
			break;
		case LO1:
			map = lo1;
			break;
		case LO1_2:
			map = lo1_2;
			break;
		case LO1_3:
			map = lo1_3;
			break;
		case principleOffice:
			map = lo1_principleOffice;
			break;
		case LO2:
			map = lo2;
			break;
		case LO2Class:
			map = lo2Class;
			break;
		case MO1:
			map = mo1;
			break;
		case HO1:
			map = ho1;
			break;
	}
	return map;
}
int room_change_funcuion (int map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{
	int OVER = WIN;
	int map_num = -1;
	int this_map_number = map_number;
//	printf ("IN\n");
//	fflush(stdout);
	map_num = Change_MAP_NUM(map_number);
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap (BACKGROUND[map_num],NULL);//馬路
	BITMAP *Not = load_bitmap (BACKGROUND_MASK[map_num],NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\system\\NOT.bmp",NULL);//障礙物
	FILE *map = fopen(SWITCH_THE_MAP[map_num],"r");
	FILE *story = fopen(EDIT_PLOT[map_num],"r");
	FILE *Picture_People = fopen(PICTURE_PEOPLE[map_num],"r");
	Character role;
	peoplework_chang (people,&role);
	map_number = no;
	int KEY = -1;
//	printf("Map_People_Paste\n");
//	fflush(stdout);

	Map_People_Paste (background,Not,Picture_People,EvenMain);

	do
	{
		rest(50);
		KEY = Read_Key ();
		Walking(Map,Char,role,background,Not,KEY);

		OVER = Map_Blue_Change (Not,map,&map_number,Map,Char,people,EvenMain);

		if (map_number == no && OVER == WIN)
		{
			OVER = Map_Green_Change (Not,story, KEY,&map_number,Map,Char,people,EvenMain);
		}
		if (OVER != WIN)
		{
			map_number = yes;
		}

		if (key[KEY_ESC])
		{map_number = Menu (this_map_number,Map,Char,people,EvenMain);}
		else if (key[KEY_Q])
		{Save (this_map_number,Map,Char,people,EvenMain);}
		else if (key[KEY_W])
		{Load (&map_number,Map,Char,people,EvenMain);}
		else
		{Load_Save(&map_number,Map,Char,people,EvenMain);}
//		else if (key[KEY_P])
//		{save_bitmap("dump.bmp", screen, pal);}

		if((key[KEY_F10]) || (close_button_pressed == TRUE ))
		{
			exit(0);
		}
	}while (map_number == no);
	if (map_number == yes)
	{map_number = no;}

	destroy_bitmap (butter);
	destroy_bitmap (background);
	destroy_bitmap (Not);
	destroy_bitmap (Not2);
	fclose (map);
	fclose (story);
	fclose (Picture_People);
	fflush(stdout);
	return map_number;
}

void map_change(int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{

//	printf("map changing!\n");
//	fflush(stdout);

	do{
		*map_number = room_change_funcuion (*map_number,Map,Char,people,EvenMain);
	}while(*map_number != no);

}
