#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"


void dog_comeback (int DOG[30][3],float T_Replacement_Dog[13])//判別同列狗死亡均死亡
{
	int i = 0;
	int Replacement_Dog = 0;
////////////////////////狗跑回來/////////////////////////////////////
		for (i=0;i<13;i++)
		{
			if (DOG[i][life] == DEAD && DOG[i+13][life] == DEAD)
			{
				Replacement_Dog = Time_After (&T_Replacement_Dog[i],5);//同一列兩隻狗均死亡後5秒鐘回來
				if (Replacement_Dog == 1)
				{
					DOG[i][life] = LIVE;
					DOG[i+13][life] = LIVE;
					Replacement_Dog = 0;
				}
			}
		}
}
void dog_comeback_movie (int DOG[30][3])//狗跑回來
{
	int i;

	for ( i = 0 ; i < 7 ; i++ )
	{
		if (DOG[i][X] > 640-64+16)
		{DOG[i][X] = DOG[i][X] - 2;}
	}
	for ( i = 7 ; i < 13 ; i++ )
	{
		if (DOG[i][X] > 640-64-64+16)
		{DOG[i][X] = DOG[i][X] - 2;}
	}
	for ( i = 13 ; i < 20 ; i++ )
	{
		if (DOG[i][X] > 640-64-64-64+16)
		{DOG[i][X] = DOG[i][X] - 2;}
	}
	for ( i = 20 ; i < 26 ; i++ )
	{
		if (DOG[i][X] > 640-64-64-64-64+16)
		{DOG[i][X] = DOG[i][X] - 2;}
	}
}

void dog_comeback_movie_left (int DOG[30][3])//狗跑回來
{
	int i;

	for ( i = 0 ; i < 7 ; i++ )
	{
		if (DOG[i][X] < 64+16)
		{DOG[i][X] = DOG[i][X] + 2;}
	}
	for ( i = 7 ; i < 13 ; i++ )
	{
		if (DOG[i][X] < 64+64+16)
		{DOG[i][X] = DOG[i][X] + 2;}
	}
	for ( i = 13 ; i < 20 ; i++ )
	{
		if (DOG[i][X] < 64+64+64+16)
		{DOG[i][X] = DOG[i][X] + 2;}
	}
	for ( i = 20 ; i < 26 ; i++ )
	{
		if (DOG[i][X] < 64+64+64+64+16)
		{DOG[i][X] = DOG[i][X] + 2;}
	}
}
