#include <allegro.h>
#include "header_value_dog.h"
#include "header_S_value.h"

void dog_weapon_movie (int WEAPON[4])//我方子彈移動
{
	if (WEAPON[X] <= 0 || WEAPON[X] >= SCREEN_W || WEAPON[Y] <= 0 || WEAPON[Y] >= SCREEN_H)
	{
		WEAPON[X] = DEAD;
		WEAPON[Y] = DEAD;
		WEAPON[life] = DEAD;
	}
	if (WEAPON[life] != DEAD)
	{
		if (WEAPON[WEAPON_Direction] == UP)
		{WEAPON[Y] = WEAPON[Y] - D_mWeaponH;}
		else if (WEAPON[WEAPON_Direction] == DOWN)
		{WEAPON[Y] = WEAPON[Y] + D_mWeaponH;}
		else if (WEAPON[WEAPON_Direction] == RIGHT)
		{WEAPON[X] = WEAPON[X] + D_mWeaponW;}
		else if (WEAPON[WEAPON_Direction] == LEFT)
		{WEAPON[X] = WEAPON[X] - D_mWeaponW;}
	}
}

void dog_bamb_movie (int BAMB[30][3])//敵方炸彈移動
{
	int i;
	for (i = 0; i < 30; i++)
	{
		if (BAMB[i][X] <= 0)
		{
			BAMB[i][X] = -1;
			BAMB[i][life] = DEAD;
		}
		if (BAMB[i][life] != DEAD)
		{
			BAMB[i][X] = BAMB[i][X] - 10;
		}
	}
}
void dog_bamb_movie_left (int BAMB[30][3])//敵方炸彈移動
{
	int i;
	for (i = 0; i < 30; i++)
	{
		if (BAMB[i][X] >= SCREEN_W)
		{
			BAMB[i][X] = -1;
			BAMB[i][life] = DEAD;
		}
		if (BAMB[i][life] != DEAD)
		{
			BAMB[i][X] = BAMB[i][X] + 10;
		}
	}
}