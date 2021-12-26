#include <allegro.h>
#include "header_S_value.h"

void dog_place (int DOG[30][3])//指定敵方的座標(初始化)
{
	int i;
	int j = 64-16;
	for ( i = 0 ; i < 7 ; i++ )
	{
		j = j;
		DOG[i][X] = 640-64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	j = 64+32-16;
	for ( i = 7 ; i < 13 ; i++ )
	{
		j = j;
		DOG[i][X] = 640-64-64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	j = 64-16;
	for ( i = 13 ; i < 20 ; i++ )
	{
		j = j;
		DOG[i][X] = 640-64-64-64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	j = 64+32-16;
	for ( i = 20 ; i < 26 ; i++ )
	{
		j = j;
		DOG[i][X] = 640-64-64-64-64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	for (; i < 30 ; i++ )
	{
		DOG[i][X] = 0;
		DOG[i][Y] = 0;
		DOG[i][life] = DEAD;
	}
}

void dog_bamb_place (int BAMB[30][3])//炸彈初始設定全為DEAD(初始化)
{
	int i;
	for (i = 0; i < 30; i++)
	{
		BAMB[i][X] = -1;
		BAMB[i][Y] = -1;
		BAMB[i][life] = DEAD;
	}
}

void dog_place_left (int DOG[30][3])//指定敵方的座標(初始化)
{
	int i;
	int j = 64-16;
	for ( i = 0 ; i < 7 ; i++ )
	{
		j = j;
		DOG[i][X] = 64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	j = 64+32-16;
	for ( i = 7 ; i < 13 ; i++ )
	{
		j = j;
		DOG[i][X] = 64+64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	j = 64-16;
	for ( i = 13 ; i < 20 ; i++ )
	{
		j = j;
		DOG[i][X] = 64+64+64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	j = 64+32-16;
	for ( i = 20 ; i < 26 ; i++ )
	{
		j = j;
		DOG[i][X] = 64+64+64+64+16;
		DOG[i][Y] = j;
		DOG[i][life] = LIVE;
		j = j + 64;
	}
	for (; i < 30 ; i++ )
	{
		DOG[i][X] = 0;
		DOG[i][Y] = 0;
		DOG[i][life] = DEAD;
	}
}