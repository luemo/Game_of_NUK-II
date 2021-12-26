#include <allegro.h>
#include <stdio.h>
#include "header_value_walk.h"
#include "header_S_value.h"

//中間方塊取障礙與移動


void people_walk_sq_red (int Map[2], int Char[4], BITMAP *barrier, BITMAP *butter_red)
{//取中間方塊障礙
//Map[2] = 中間方塊的貼點，Char[4] = 第一人物的貼點，barrier = 大地圖的障礙物，butter_red = 中間方塊的障礙物
//1.取出中間方塊障礙物
//2.i = 大地圖的障礙物(barrier)的X貼點;j = 大地圖的障礙物(barrier)的Y貼點
//3.Map[0] = 人物可活動範圍(中心)的X點;Map[0] = 人物可活動範圍(中心)的Y點
//4.回傳方塊障礙物

	int i = 0,j = 0;

		if (Map[Y] >= 0 && Map[Y] <= SQ_SIDE/2)			//分九格來取圖(分界點為大地圖邊界 - 方塊大小/2)
		{j = 0;}
		else if (Map[Y] > SQ_SIDE/2 && Map[Y] < barrier->h - SQ_SIDE/2)
		{j = Map[Y] - SQ_SIDE/2;}
		else if (Map[Y] >= barrier->h - SQ_SIDE/2 && Map[Y] <= barrier->h)
		{j = barrier->h - SQ_SIDE;}

		if (Map[X] >= 0 && Map[X] <= SQ_SIDE/2)
		{i = 0;}
		else if (Map[X] > SQ_SIDE/2 && Map[X] < barrier->w - SQ_SIDE/2)
		{i = Map[X] - SQ_SIDE/2;}
		else if (Map[X] >= barrier->w - SQ_SIDE/2 && Map[X] <= barrier->w)
		{i =barrier->w - SQ_SIDE;}

		blit (barrier, butter_red, i - PeopleW, j - PeopleH, 0, 0, SQ_SIDE + PeopleW*2, SQ_SIDE + PeopleH*2);	//可回傳的方塊障礙物
}

void people_walk_sq_movie (int Map[2], int Char[4], BITMAP *BIGMAP)
{
	if (Char[Direction] == UP)
	{
		Map[Y] = Map[Y] - PeopleH;

		if (Map[Y] < SQ_SIDE/2)//如果超過上邊界則設為最上
		{Map[Y] = SQ_SIDE/2;}
	}	//end of key[KEY_UP]

	if (Char[Direction] == DOWN)
	{
		Map[Y] = Map[Y] + PeopleH;

		if (Map[Y] > BIGMAP->h - SQ_SIDE/2)//如果超過下邊界則設為最下 - 方塊高/2
		{Map[Y] = BIGMAP->h - SQ_SIDE/2;}
	}	//end of key[KEY_DOWN]

	if (Char[Direction] == LEFT)
	{
		Map[X] = Map[X] - PeopleW;

		if (Map[X] < SQ_SIDE/2)//如果超過左邊界則設為最左
		{Map[X] = SQ_SIDE/2;}
	}	//end of key[KEY_LEFT]
	if (Char[Direction] == RIGHT)
	{
		Map[X] = Map[X] + PeopleW;

		if (Map[X] > BIGMAP->w - SQ_SIDE/2)//如果超過右邊界則設為最右 - 方塊寬/2
		{Map[X] = BIGMAP->w - SQ_SIDE/2;}
	}	//end of key[KEY_RIGHT]
}