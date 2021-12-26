/*
 * src_Story_function.c
 *
 *  Created on: 2012/9/24
 *      Author: Lue
 */
#include <stdio.h>
#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"

int Story_choose (int event,int EvenMain[EvenALL]);

int Map_Green_Change (BITMAP *Mask,FILE *map,int KEY, int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{
	int OVER = WIN;
	int i,j;
	int Map_num,Map_X,Map_Y,Dir;
	int S_Cur,S_Next;
	int people0,people1,people2,people3;

	rewind(map);
	fscanf (map,"%d\n", &j);
/*	printf("\nS_j %d\n", j);
	fflush(stdout);*/
//	printf ("%d %d %d %d\n", i, j, *map_number,Char[0][0]);
//	fflush(stdout);

	for (i = 0; i < j; i++)
	{

		fscanf (map,"\n");
		fscanf (map,"MapCode  %d	Site (%d,%d)	Key %d\n", &Map_num, &Map_X, &Map_Y, &Dir);
		fscanf (map,"Completed(Yes/No) (%d,%d)\n", &S_Cur, &S_Next);
		fscanf (map,"PeopleChange (%d,%d,%d,%d)\n", &people0, &people1, &people2, &people3);

/*		printf("i %d\n", i);
		printf ("%d %d %d %d\n", Map_num, Map_X, Map_Y, Dir);
		printf ("%d %d\n", S_Cur, S_Next);
		printf ("%d %d %d %d\n", people0, people1, people2, people3);
		fflush(stdout);
*/
		if (KEY == Dir && (EvenMain[S_Cur] == yes || S_Cur == not) && EvenMain[S_Next] == no && People_site_Green (Map,Char[0],Map_X,Map_Y,Mask) == yes)//BGR
		{//如果說S_Cur輸入not(-1)的話就是表示前面不用達成什麼條件;反之為上一步驟所需資條件
			*map_number = Map_num;
			EvenMain[S_Next] = yes;
			if (people0 != -1)//如果說輸入-1的話就是表示各數值不變動;其餘改值
			{people[0] = people0;}
			if (people1 != -1)
			{people[1] = people1;}
			if (people2 != -1)
			{people[2] = people2;}
			if (people3 != -1)
			{people[3] = people3;}
//			printf ("Event Go\n");
//			fflush(stdout);
			OVER = Story_choose(S_Next,EvenMain);
			break;
		}
		else if (Dir == not && EvenMain[S_Next] == no)//條件滿足則自動觸發
		{//開啟S_Next的條件，people0與people1均須開啟，且people2與people3填not(-1)，此外且people2或people3不為not則也須開啟
		 //Dir == not(-1)的話，為自動啟動
			if (EvenMain[people0] == yes && EvenMain[people1] == yes && (EvenMain[people2] == yes || people2 == not ) && (EvenMain[people3] == yes || people3 == not ))
			{
				*map_number = Map_num;
				EvenMain[S_Next] = yes;
//				printf ("Event AUTO_Go\n");
//				fflush(stdout);
				OVER = Story_choose(S_Next,EvenMain);
				break;
			}
			else if (EvenMain[S_Cur] == yes)//條件滿足則自動觸發
			{
				*map_number = Map_num;
				EvenMain[S_Next] = yes;
				if (people0 != -1)//如果說輸入-1的話就是表示各數值不變動;其餘改值
				{people[0] = people0;}
				if (people1 != -1)
				{people[1] = people1;}
				if (people2 != -1)
				{people[2] = people2;}
				if (people3 != -1)
				{people[3] = people3;}
//				printf ("Event AUTO_Go_SOMEONE_LEFT_OR_COME\n");
//				fflush(stdout);
				OVER = Story_choose(S_Next,EvenMain);
				break;
			}
		}
	}
	return OVER;
}


