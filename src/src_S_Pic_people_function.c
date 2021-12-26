/*
 * src_S_Pic_people_function.c
 *
 *  Created on: 2012/9/26
 *      Author: Lue
 */
#include <stdio.h>
#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"
#include "header_value_walk.h"

void Load_Picture_character (int People,BITMAP *character);
void Load_Picture_things (int People,BITMAP *character);

int Map_People_Paste (BITMAP *P_MAP,BITMAP *Mask,FILE *map,int EvenMain[EvenALL])
{
//	printf("Map_People_PasteIN\n");
//	fflush(stdout);
	int i,j;
	int People,People_X,People_Y,People_Face;
	int S_Start,S_End;
	int Dirc[4];
	BITMAP *Not2 = load_bitmap ("image\\system\\NOT.bmp",NULL);//障礙物
	BITMAP *character = create_bitmap(PeopleW*3, PeopleH*4);

	rewind(map);
	fscanf (map,"%d\n", &j);
//	printf("\nS_j %d\n", j);
//	fflush(stdout);
//	printf ("%d %d %d %d\n", i, j, *map_number,Char[0][0]);
//	fflush(stdout);
	for (i = 0; i < j; i++)
	{
		fscanf (map,"\n");
		fscanf (map,"%d\t%d\t%d\t%d\t", &People, &People_X, &People_Y, &People_Face);
		fscanf (map,"%d\t%d\t", &S_Start, &S_End);
		fscanf (map,"%d\t%d\t%d\t%d\n", &Dirc[0], &Dirc[1], &Dirc[2], &Dirc[3]);
		clear_to_color(character,makecol(255,0,255));//RGB→紫/**/

/*		printf("i %d\n", i);
		printf ("%d\t%d\t%d\t%d\n", People, People_X, People_Y, People_Face);
		printf ("%d\t%d\n", S_Start, S_End);
		printf ("%d\t%d\t%d\t%d\n", Dirc[0], Dirc[1], Dirc[2], Dirc[3]);
		fflush(stdout);*/

		if ((EvenMain[S_Start] == yes || S_Start == not) && (EvenMain[S_End] == no || S_End == not))
		{
			if (People == not)//People == not(-1)貼物品或是空白
			{
				Load_Picture_things (S_End,character);
			}
			else
			{
				Load_Picture_character (People,character);
			}

			if (Dirc[DOWN] == yes)//yes ==1
			{//blit (Not2, P_MAP, PeopleW*1, PeopleH*0, PeopleW*(People_X), PeopleH*(People_Y-1), PeopleW, PeopleH);
			blit (Not2, Mask, PeopleW*1, PeopleH*0, PeopleW*(People_X), PeopleH*(People_Y-1), PeopleW, PeopleH);}
			if (Dirc[LEFT] == yes)//yes ==1
			{//blit (Not2, P_MAP, PeopleW*2, PeopleH*1, PeopleW*(People_X+1), PeopleH*(People_Y), PeopleW, PeopleH);
			blit (Not2, Mask, PeopleW*2, PeopleH*1, PeopleW*(People_X+1), PeopleH*(People_Y), PeopleW, PeopleH);}
			if (Dirc[RIGHT] == yes)//yes ==1
			{//blit (Not2, P_MAP, PeopleW*0, PeopleH*1, PeopleW*(People_X-1), PeopleH*(People_Y), PeopleW, PeopleH);
			blit (Not2, Mask, PeopleW*0, PeopleH*1, PeopleW*(People_X-1), PeopleH*(People_Y), PeopleW, PeopleH);}
			if (Dirc[UP] == yes)//yes ==1
			{//blit (Not2, P_MAP, PeopleW*1, PeopleH*2, PeopleW*(People_X), PeopleH*(People_Y+1), PeopleW, PeopleH);
			blit (Not2, Mask, PeopleW*1, PeopleH*2, PeopleW*(People_X), PeopleH*(People_Y+1), PeopleW, PeopleH);}

			//blit (Not2, P_MAP, PeopleW*1, PeopleH*1, PeopleW*People_X, PeopleH*People_Y, PeopleW, PeopleH);
			blit (Not2, Mask, PeopleW*1, PeopleH*1, PeopleW*People_X, PeopleH*People_Y, PeopleW, PeopleH);

			masked_blit (character, P_MAP, PeopleW*1, PeopleH*People_Face, PeopleW*People_X, PeopleH*People_Y, PeopleW, PeopleH);
		}

	}

	destroy_bitmap (Not2);
	destroy_bitmap (character);
	return 0;
}
void Load_Picture_things (int thing,BITMAP *character)
{
	BITMAP *characterA;
	switch (thing)
	{
		case EvenThingsToAPIBM:
			characterA =  load_bitmap ("image\\Things\\ThingForAPIBM.bmp",NULL);//亞太的衛星導航
			break;
		case EvenThingsToCS:
			characterA = load_bitmap ("image\\Things\\ThingForCS.bmp",NULL);//資工的燈
			break;
		case EvenLO1:
			characterA = create_bitmap(PeopleW, PeopleH);
			clear_to_color(character,makecol(255,0,255));//RGB→紫/**/
			break;

//		default:
//			printf ("could not find thing number:%d\n",thing);
//			fflush(stdout);
	}
	if (characterA != NULL)
	{
		blit (characterA, character, 0, 0, PeopleW, 0, characterA->w, characterA->h);
	}
	else
	{
//		printf ("characterA bitmap file can find!\n");
//		exit(-1);
	}
}
void Load_Picture_character (int People,BITMAP *character)
{
	BITMAP *characterA;
	switch (People)
	{
		case AC:
		characterA = load_bitmap ("image\\character\\AC.bmp",NULL);//應化
		break;
		case AM:
		characterA = load_bitmap ("image\\character\\AM.bmp",NULL);//應數
		break;
		case AP:
		characterA = load_bitmap ("image\\character\\AP.bmp",NULL);//應物
		break;
		case APIBM:
		characterA = load_bitmap ("image\\character\\APIBM.bmp",NULL);//亞太
		break;
		case CEE:
		characterA = load_bitmap ("image\\character\\CEE.bmp",NULL);//土環
		break;
		case CM:
		characterA = load_bitmap ("image\\character\\CM.bmp",NULL);//化材
		break;
		case CS:
		characterA = load_bitmap ("image\\character\\CS.bmp",NULL);//資工
		break;
		case DKHL:
		characterA = load_bitmap ("image\\character\\DKHL.bmp",NULL);//運健休
		break;
		case ECON:
		characterA = load_bitmap ("image\\character\\ECON.bmp",NULL);//應經
		break;
		case EE:
		characterA = load_bitmap ("image\\character\\EE.bmp",NULL);//電機
		break;
		case EFL:
		characterA = load_bitmap ("image\\character\\EFL.bmp",NULL);//財法
		break;
		case EL:
		characterA = load_bitmap ("image\\character\\EL.bmp",NULL);//東語
		break;
		case FIM:
		characterA = load_bitmap ("image\\character\\FIM.bmp",NULL);//金管
		break;
		case GL:
		characterA = load_bitmap ("image\\character\\GL.bmp",NULL);//政法
		break;
		case IM:
		characterA = load_bitmap ("image\\character\\IM.bmp",NULL);//資管
		break;
		case LAW:
		characterA = load_bitmap ("image\\character\\LAW.bmp",NULL);//法律
		break;
		case LS:
		characterA = load_bitmap ("image\\character\\LS.bmp",NULL);//生科
		break;
		case TCCD:
		characterA = load_bitmap ("image\\character\\TCCD.bmp",NULL);//傳設
		break;
		case WL:
		characterA = load_bitmap ("image\\character\\WL.bmp",NULL);//西語
		break;
//		default:
//			printf ("could not find People number:%d\n",People);
//			fflush(stdout);
	}
	if (characterA != NULL)
	{
		blit (characterA, character, 0, 0, 0, 0, characterA->w, characterA->h);
	}
	else
	{
//		printf ("characterA bitmap file can find!\n");
//		exit(-1);
	}
}
