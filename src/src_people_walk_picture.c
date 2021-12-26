#include <allegro.h>
#include "header_value_walk.h"
#include "header_S_value.h"

#ifndef Character
	typedef struct struct_character{
		BITMAP *character1;
		BITMAP *character2;
		BITMAP *character3;
		BITMAP *character4;
	}Character;
#endif

void people_walk_map (int Map[2], BITMAP *BIGMAP, BITMAP *Sq_MAP, BITMAP *butter)
{
//1.將整個大地圖(BIGMAP)分為九部分，以邊界到1/2畫面為界線切割
//2.i = 大地圖(BIGMAP)的X貼點;j = 大地圖(BIGMAP)的Y貼點;k = 方塊(butter)的X貼點;l = 方塊(butter)的Y貼點
//4.Map[0] = 人物可活動範圍(中心)的X點;Map[1] = 人物可活動範圍(中心)的Y點;MAP[2]之值介於SQ_SIDE/2至BIGMAP - SQ_SIDE/2

	BITMAP *buff = create_bitmap (SCREEN_W, SCREEN_H);	//暫存器，先貼大地圖(BIGMAP)，再貼中間的方塊(butter)

	int i = 0,j = 0;
	int k = 0,l = 0;

	if (Map[Y] >= 0 && Map[Y] <= SCREEN_H/2)			//貼大地圖;分九部分來貼圖(分界點為大地圖邊界 - 視窗大小/2)
	{j = 0;}
	else if (Map[Y] > SCREEN_H/2 && Map[Y] < BIGMAP->h - SCREEN_H/2)
	{j = Map[Y] - SCREEN_H/2;}
	else if (Map[Y] >= BIGMAP->h - SCREEN_H/2 && Map[Y] <= BIGMAP->h)
	{j = BIGMAP->h - SCREEN_H;}

	if (Map[X] >= 0 && Map[X] <= SCREEN_W/2)
	{i = 0;}
	else if (Map[X] > SCREEN_W/2 && Map[X] < BIGMAP->w - SCREEN_W/2)
	{i = Map[X] - SCREEN_W/2;}
	else if (Map[X] >= BIGMAP->w - SCREEN_W/2 && Map[X] <= BIGMAP->w)
	{i = BIGMAP->w - SCREEN_W;}


	if (Map[Y] >= SQ_SIDE/2 && Map[Y] <= SCREEN_H/2)			//貼行走地圖;分九部分來貼圖(分界點為大地圖邊界 - 視窗大小/2)
	{l = Map[Y] - SQ_SIDE/2;}
	else if (Map[1] > SCREEN_H/2 && Map[Y] <= BIGMAP->h - SCREEN_H/2)
	{l = SCREEN_H/2 - SQ_SIDE/2;}
	else if (Map[Y] > BIGMAP->h - SCREEN_H/2 && Map[Y] <= BIGMAP->h - SQ_SIDE/2)
	{l = SCREEN_H - (BIGMAP->h - Map[Y]) - SQ_SIDE/2;}


	if (Map[X] >= SQ_SIDE/2 && Map[X] <= SCREEN_W/2)
	{k = Map[X] - SQ_SIDE/2;}
	else if (Map[X] > SCREEN_W/2 && Map[X] <= BIGMAP->w - SCREEN_W/2)
	{k = SCREEN_W/2 - SQ_SIDE/2;}
	else if (Map[X] > BIGMAP->w - SCREEN_W/2 && Map[X] <= BIGMAP->w - SQ_SIDE/2)
	{k = SCREEN_W - (BIGMAP->w - Map[X]) - SQ_SIDE/2;}


	blit (BIGMAP, buff, i, j, 0, 0, SCREEN_W, SCREEN_H);

//if (key[KEY_Q]){blit (Sq_MAP, buff, 0, 0, k, l, SQ_SIDE, SQ_SIDE);}

	masked_blit (Sq_MAP, buff, 0, 0, k, l, SQ_SIDE, SQ_SIDE);

//	blit (buff, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (buff, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	destroy_bitmap (buff);
}



void people_walk_sq (int Char[4][4], Character role, BITMAP *Sq_MAP,int n,int KEY)
{
	if ( KEY == not )
	{n = 1;}
	masked_blit (role.character4, Sq_MAP, PeopleW*(n%3), PeopleH*Char[3][Direction], Char[3][X] - PeopleW/2, Char[3][Y] - PeopleH/2, PeopleW, PeopleH);
	masked_blit (role.character3, Sq_MAP, PeopleW*(n%3), PeopleH*Char[2][Direction], Char[2][X] - PeopleW/2, Char[2][Y] - PeopleH/2, PeopleW, PeopleH);
	masked_blit (role.character2, Sq_MAP, PeopleW*(n%3), PeopleH*Char[1][Direction], Char[1][X] - PeopleW/2, Char[1][Y] - PeopleH/2, PeopleW, PeopleH);
	masked_blit (role.character1, Sq_MAP, PeopleW*(n%3), PeopleH*Char[0][Direction], Char[0][X] - PeopleW/2, Char[0][Y] - PeopleH/2, PeopleW, PeopleH);
}
