#include <allegro.h>
#include "header_value_dog.h"
#include "header_S_value.h"

void dog_our_act (int Our[4],int WEAPON[4], int KEY)//�ڤ�o�ʧ����P�����
{
	if (KEY == SPACE && WEAPON[life] == DEAD)
	{
		WEAPON[X] = Our[X];
		WEAPON[Y] = Our[Y];
		WEAPON[life] = LIVE;
	}
	else if (KEY == TAB && WEAPON[life] == DEAD)
	{
		if (Our[category] < ACT_category)
		{Our[category] = Our[category] + 1;}
		else
		{Our[category] = 1;}
	}
}
void dog_weapon_direction (int Face,int WEAPON[4])//�ڤ�Ĥ@�H���V�P�l�u�o�g��m
{
	if (WEAPON[life] == DEAD)
	{WEAPON[WEAPON_Direction] = Face;}
}

void dog_bamb_act (int DOG[3],int BAMB[3])//�Ĥ�����}�l
{
	if (DOG[life] == LIVE && BAMB[life] != LIVE)
	{
		BAMB[X] = DOG[X];
		BAMB[Y] = DOG[Y];
		BAMB[life] = LIVE;
	}
}
