#include <allegro.h>
#include "header_value_dog.h"
#include "header_S_value.h"

void dog_butter_picture_del_our(int Our[4], BITMAP *butter, int *num, int *over,int Char_Back[4][4])
{	int A,B,i = 0;

	for (i = 0; i<4; i++)
	{
		for (A = -D_PW/2; A < D_PW/2; A++)
		{
		for (B = -D_PH/2; B < D_PH/2; B++)
		{
			if (butter->line[Our[Y] + Char_Back[i][Y] +B][(Our[X] + Char_Back[i][X] +A)*3+2] == 255)//BGR
			{
				*over = Dog_Kill;
				*num = butter->line[Our[Y] + Char_Back[i][Y] +B][(Our[X] + Char_Back[i][X] +A)*3+1];
			}
			if ( *num != DEAD )
			{break;}

		}
			if ( *num != DEAD )
			{break;}
		}
		if ( *num != DEAD )
		{break;}
	}
}
void dog_butter_picture_del_weapon(int WEAPON[4], BITMAP *butter, int *num)
{
	int A;
	int B;

	if(WEAPON[life] != DEAD && WEAPON[X] >= 0 && WEAPON[X] <= SCREEN_W && WEAPON[Y] >= 0 && WEAPON[Y] <= SCREEN_H && *num == DEAD)
	{
		for (A = - D_WeaponW/2; A < D_WeaponW/2; A++)
		{
		for (B = - D_WeaponH/2; B < D_WeaponH/2; B++)
		{
			if (butter->line[WEAPON[Y]+B][(WEAPON[X]+A)*3+2] == 255)//BGR
			{
				WEAPON[life] = 2;
				*num = butter->line[WEAPON[Y]+B][(WEAPON[X]+A)*3+1];
			}
			if ( *num != DEAD )
			{break;}
		}
			if ( *num != DEAD )
			{break;}
		}
	}
}

void dog_butter_picture_del_bamb(int BAMB[30][3], BITMAP *butter, int *over)
{
	int i,A,B,j=0;

	for ( i = 0 ; i < 30 ; i++)
	{
		if(BAMB[i][life] != DEAD && BAMB[i][X] >= 0)
		{
			for (A = -D_MBW/2; A < D_MBW/2; A++)
			{
			for (B = -D_MBH/2; B < D_MBH/2; B++)
			{
				if (butter->line[BAMB[i][Y]+B][(BAMB[i][X]+A)*3+0] == 0)//BGR
				{
					*over = i;
				}
				if ( *over != DEAD )
				{break;}
			}
				if ( *over != DEAD )
				{break;}
			}
		}
		if ( *over != DEAD )
		{break;}
	}
}
