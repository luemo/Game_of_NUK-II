#include <allegro.h>
#include "header_Flower.h"
#include "header_S_value.h"

void flower_place (int FLOWER[30][3])//���w�Ĥ誺�y��(��l��)
{
	int i;
	for ( i = 0 ; i < 30 ; i++ )
	{
		FLOWER[i][X] = -1;
		FLOWER[i][Y] = -1;
		FLOWER[i][life] = DEAD;
	}
}

void flower_bamb_place (int BAMB[30][3])//���u��l�]�w����DEAD(��l��)
{
	int i;
	for (i = 0; i < 30; i++)
	{
		BAMB[i][X] = -1;
		BAMB[i][Y] = -1;
		BAMB[i][life] = DEAD;
	}
}