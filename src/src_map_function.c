/*
 * src_map_function.c
 *
 *  Created on: 2012/9/22
 *      Author: Lue
 */
#include <stdio.h>
#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"
#include "header_value_walk.h"
int Story_choose (int event,int EvenMain[EvenALL]);

int Map_Blue_Change (BITMAP *Mask,FILE *map,int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{
	int OVER = WIN;
	int i,j;
	int mapR,mapB,mapG,Dir;
	int Map_num,Map_X,Map_Y;
	int Char_X,Char_Y,Char_Face;
	int people0,people1,people2,people3;

	rewind(map);
	fscanf (map,"%d\n", &j);
/*	printf("\nj %d\n", j);
	fflush(stdout);*/
//	printf ("%d %d %d %d\n", i, j, *map_number,Char[0][0]);
//	fflush(stdout);

	for (i = 0; i < j; i++)
	{

		fscanf (map,"\n");
		fscanf (map,"%d %d %d %d\n", &mapR, &mapG, &mapB, &Dir);
		fscanf (map,"%d %d %d\n", &Map_num, &Map_X, &Map_Y);
		fscanf (map,"%d %d %d\n", &Char_X, &Char_Y, &Char_Face);
		fscanf (map,"%d %d %d %d\n", &people0, &people1, &people2, &people3);

/*		printf("i %d\n", i);
		printf ("%d %d %d %d\n", mapR, mapG, mapB, Dir);
		printf ("%d %d %d\n", Map_num, Map_X, Map_Y);
		printf ("%d %d %d\n", Char_X, Char_Y, Char_Face);
		printf ("%d %d %d %d\n", people0, people1, people2, people3);
		fflush(stdout);*/

		if (Dir == -2 && EvenMain[Map_X] == yes && EvenMain[Map_Y] == no && Mask->line[Map[Y]+Char[0][Y]-SQ_SIDE/2][(Map[X]+Char[0][X]-SQ_SIDE/2)*3] == mapB && Mask->line[Map[Y]+Char[0][Y]-SQ_SIDE/2][(Map[X]+Char[0][X]-SQ_SIDE/2)*3+1] == mapG && Mask->line[Map[Y]+Char[0][Y]-SQ_SIDE/2][(Map[X]+Char[0][X]-SQ_SIDE/2)*3+2] == mapR)//BGR
		{//Char_X = S_Cur,Char_Y = S_Next;//條件滿足則自動觸發
				*map_number = Map_num;
				EvenMain[Map_Y] = yes;
				if (people0 != -1)//如果說輸入-1的話就是表示各數值不變動;其餘改值
				{people[0] = people0;}
				if (people1 != -1)
				{people[1] = people1;}
				if (people2 != -1)
				{people[2] = people2;}
				if (people3 != -1)
				{people[3] = people3;}
//				printf ("MAP_EVENT Go\n");
//				fflush(stdout);
				OVER = Story_choose (Map_Y,EvenMain);
				break;
		}
		else if ((Dir == Char[0][3] || Dir == -1) && Mask->line[Map[Y]+Char[0][Y]-SQ_SIDE/2][(Map[X]+Char[0][X]-SQ_SIDE/2)*3] == mapB && Mask->line[Map[Y]+Char[0][Y]-SQ_SIDE/2][(Map[X]+Char[0][X]-SQ_SIDE/2)*3+1] == mapG && Mask->line[Map[Y]+Char[0][Y]-SQ_SIDE/2][(Map[X]+Char[0][X]-SQ_SIDE/2)*3+2] == mapR)//BGR
		{
			*map_number = Map_num;
			if (Char_X == -1)			//如果說輸入-1的話就是表示各數值不變動;若是輸入負數，就是表示數值變動為減掉那個負數
			{Char_X = Char[0][X];}
			if (Char_Y == -1)
			{Char_Y = Char[0][Y];}
			else if (Char_Y < -1)
			{Char_Y = Char[0][Y] - Char_Y;}
			Walk_init (Char,Char_X,Char_Y,Char_Face);
			if (Map_X != -1)
			{Map[X] = Map_X;}
			if (Map_Y != -1)
			{Map[Y] = Map_Y;}
//			printf ("MAP Change\n");
//			fflush(stdout);
			break;
		}
	}
	return OVER;

//	fclose (map2);
}
