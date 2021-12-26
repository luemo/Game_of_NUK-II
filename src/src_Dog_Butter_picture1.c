#include <allegro.h>
#include "header_value_dog.h"
#include "header_S_value.h"

void dog_butter_picture_dog(int DOG[30][3], BITMAP *butter)//R = 255,G = 第幾隻狗,B = 0
{
	BITMAP *butter2 = create_bitmap(D_MW,D_MH);

	int i;
	for ( i = 0 ; i < 30 ; i++)
	{
		if(DOG[i][life] != DEAD)
		{
			clear_to_color(butter2,makecol(255,i,0));//RGB
			blit (butter2, butter, 0, 0, DOG[i][X] - D_MW/2, DOG[i][Y] - D_MH/2, D_MW, D_MH);
		}
	}
	destroy_bitmap (butter2);
}

void dog_butter_picture_our(int Our[4], BITMAP *butter,int Char_Back[4][4])//R = 0,G = 255,B = 0
{
	int i = 0;
	BITMAP *butter2 = create_bitmap(D_PW,D_PH);
	clear_to_color(butter2,makecol(0,255,0));//RGB

	for ( i = 0 ; i <4 ; i++ )
	{blit (butter2, butter, 0, 0, Our[X] + Char_Back[i][X] - D_PW/2, Our[Y] + Char_Back[i][Y] - D_PH/2, D_PW, D_PH);}
	destroy_bitmap (butter2);
}

void dog_butter_picture_weapon(int WEAPON[4], BITMAP *butter)//R = 0,G = 255,B = 255
{
	BITMAP *butter2 = create_bitmap(D_WeaponW,D_WeaponH);
	clear_to_color(butter2,makecol(0,255,255));//RGB

	if (WEAPON[life] != DEAD && WEAPON[X] >= 0 && WEAPON[X] <= SCREEN_W && WEAPON[Y] >= 0 && WEAPON[Y] <= SCREEN_H)
	{blit (butter2, butter, 0, 0, WEAPON[X] - D_WeaponW/2, WEAPON[Y] - D_WeaponH/2, D_WeaponW, D_WeaponH);}
	destroy_bitmap (butter2);
}

void dog_butter_picture_bamb(int BAMB[30][3], BITMAP *butter)//R = 50,G = 第幾隻狗的攻擊,B = 50
{
	int i;
	BITMAP *butter2 = create_bitmap(D_MBW,D_MBH);
	for ( i = 0 ; i < 30 ; i++)
	{
		if(BAMB[i][life] != DEAD)
		{
			clear_to_color(butter2,makecol(50,i,50));//RGB
			blit (butter2, butter, 0, 0, BAMB[i][X] - D_MBW/2, BAMB[i][Y] - D_MBH/2, D_MBW, D_MBH);
		}
	}
	destroy_bitmap (butter2);
}

