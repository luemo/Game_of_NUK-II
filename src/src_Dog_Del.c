#include <allegro.h>
#include "header_value_dog.h"
#include "header_S_value.h"

void dog_del_our (int BAMB[30][3],int Our[3],int *del)//我方死亡
{
	if (*del == Dog_Kill)
	{	Our[life] = Our[life] - 1;
		*del = DEAD;
	}
	else if (*del != DEAD)
	{
		BAMB[*del][X] = DEAD;
		BAMB[*del][Y] = DEAD;
		BAMB[*del][life] = DEAD;
		Our[life] = Our[life] - 1;
		*del = DEAD;
	}
}
void dog_del_dog (int DOG[30][3],int WEAPON[3],int *del)//敵方死亡
{
	if (*del != DEAD)
	{
		DOG[*del][X] = DOG[*del][X] +64+64+64+64+64+64+64+16;
		DOG[*del][life] = DEAD;
		if (WEAPON[life] == 2)
		{
			WEAPON[X] = DEAD;
			WEAPON[Y] = DEAD;
			WEAPON[life] = DEAD;
		}
		*del = DEAD;
	}
}
void dog_del_dog_left (int DOG[30][3],int WEAPON[3],int *del)//敵方死亡
{
	if (*del != DEAD)
	{
		DOG[*del][X] = DOG[*del][X] -64-64-64-64-64-64-64-16;
		DOG[*del][life] = DEAD;
		if (WEAPON[life] == 2)
		{
			WEAPON[X] = DEAD;
			WEAPON[Y] = DEAD;
			WEAPON[life] = DEAD;
		}
		*del = DEAD;
	}
}

int dog_end (int DOG[30][3],int Our[3])//結束
{
	int i,last = 0;
	for (i = 0; i < 30; i++)
	{
		if (DOG[i][life] == LIVE)
		{break;}
		if (i == 29 && DOG[29][life] == DEAD)
		{return WIN;}
	}
	if ( Our[X] >= SCREEN_W - DP_PW)
	{
		return WIN;
	}
	if ( Our[life] == DEAD)
	{
		return LOOSE;
	}
	return not;
}

int dog_end_left (int DOG[30][3],int Our[3])//結束
{
	int i,last = 0;
	for (i = 0; i < 30; i++)
	{
		if (DOG[i][life] == LIVE)
		{break;}
		if (i == 29 && DOG[29][life] == DEAD)
		{return WIN;}
	}
	if ( Our[X] <= DP_PW)
	{
		return WIN;
	}
	if ( Our[life] == DEAD)
	{
		return LOOSE;
	}
	return not;
}