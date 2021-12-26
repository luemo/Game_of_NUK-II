#include <allegro.h>
#include "header_S_value.h"
#include "header_value_walk.h"

void dog_people_walk_seat (int Map[2],int We[2],int Char[4], BITMAP *BIGMAP)//將武器位置與第一人位置重合
{
//1.將整個大地圖(BIGMAP)分為九部分，以邊界到1/2畫面為界線切割
//2.i = 大地圖(BIGMAP)的X貼點;j = 大地圖(BIGMAP)的Y貼點;k = 方塊(butter)的X貼點;l = 方塊(butter)的Y貼點
//4.Map[0] = 人物可活動範圍(中心)的X點;Map[1] = 人物可活動範圍(中心)的Y點;MAP[2]之值介於SQ_SIDE/2至BIGMAP - SQ_SIDE/2

	int k = 0,l = 0;

	if (Map[1] >= SQ_SIDE/2 && Map[1] <= SCREEN_H/2)			//貼行走地圖;分九部分來貼圖(分界點為大地圖邊界 - 視窗大小/2)
	{l = Map[1] - SQ_SIDE/2;}
	else if (Map[1] > SCREEN_H/2 && Map[1] <= BIGMAP->h - SCREEN_H/2)
	{l = SCREEN_H/2 - SQ_SIDE/2;}
	else if (Map[1] > BIGMAP->h - SCREEN_H/2 && Map[1] <= BIGMAP->h - SQ_SIDE/2)
	{l = SCREEN_H - (BIGMAP->h - Map[1]) - SQ_SIDE/2;}

	if (Map[0] >= SQ_SIDE/2 && Map[0] <= SCREEN_W/2)
	{k = Map[0] - SQ_SIDE/2;}
	else if (Map[0] > SCREEN_W/2 && Map[0] <= BIGMAP->w - SCREEN_W/2)
	{k = SCREEN_W/2 - SQ_SIDE/2;}
	else if (Map[0] > BIGMAP->w - SCREEN_W/2 && Map[0] <= BIGMAP->w - SQ_SIDE/2)
	{k = SCREEN_W - (BIGMAP->w - Map[0]) - SQ_SIDE/2;}

	We[0] = k + Char[0];
	We[1] = l + Char[1];

}