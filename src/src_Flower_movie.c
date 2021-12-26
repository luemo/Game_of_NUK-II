#include <allegro.h>
#include "header_S_value.h"
#include "header_value_flower.h"

void flower_our_movie (int Our[4], int KEY)//我方移動
{
	if (KEY == RIGHT)
	{
		Our[X] = Our[X] + FP_PW;
		if (Our[X] >= SCREEN_W)
		{Our[X] = SCREEN_W - FP_PW/2;}
	}
	else if (KEY == LEFT)
	{
		Our[X] = Our[X] - FP_PW;
		if (Our[X] <= 0)
		{Our[X] = 0 + FP_PW/2;}
	}

}
void flower_fall (int FLOWER[3])//開始落花
{
	if (FLOWER[life] != LIVE)
	{
		FLOWER[X] = rand()%(SCREEN_W/FP_PW)*FP_PW+FP_PW/2;
		FLOWER[Y] = 0 - rand()%SCREEN_H - FP_PH;
		FLOWER[life] = LIVE;
	}
}

void flower_movie (int FLOWER[30][3])//花落下來
{
	int i;
	for (i = 0; i < 30; i++)
	{
		if (FLOWER[i][Y] >= SCREEN_H)
		{
			FLOWER[i][X] = DEAD;
			FLOWER[i][Y] = DEAD;
			FLOWER[i][life] = DEAD;
		}
		if (FLOWER[i][life] != DEAD)
		{
			FLOWER[i][Y] = FLOWER[i][Y] + 10;
		}
	}
}
