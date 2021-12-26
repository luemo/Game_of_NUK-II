#include <allegro.h>
#include "header_Dog.h"
#include "header_value_dog.h"
#include "header_S_value.h"

PALETTE pal;

void dog_butter_picture(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],int *num, int *over,int MAP[2],int Char[4][4])//幕後作業畫面//Char為人物在中央框框中的位置
{
//	BITMAP *butter = create_bitmap(ScreenW,ScreenH);
//	clear_to_color(butter,makecol(0,0,0));//RGB→黑

	BITMAP *butter1 = create_bitmap(SCREEN_W, SCREEN_H);
	BITMAP *butter2 = create_bitmap(SCREEN_W, SCREEN_H);
	clear_to_color(butter1,makecol(0,0,0));//RGB→黑
	clear_to_color(butter2,makecol(255,0,255));//RGB→紫/**/

	int Char_Back[4][4] = {{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}};

	dog_butter_picture_Char(Char,Char_Back);

	dog_butter_picture_dog(DOG,butter1);//R = 255,G = 第幾隻狗,B = 0

	dog_butter_picture_our(Our,butter2,Char_Back);//R = 0,G = 255,B = 0

	dog_butter_picture_weapon(WEAPON,butter2);//R = 0,G = 255,B = 255

	dog_butter_picture_bamb(BAMB,butter1);//R = 50,G = 第幾隻狗的攻擊,B = 50


	dog_butter_picture_del_our(Our,butter1,num,over,Char_Back);

	dog_butter_picture_del_weapon(WEAPON,butter1,num);

	dog_butter_picture_del_bamb(BAMB,butter2,over);
//	if (key[KEY_O])
//	{save_bitmap("dump2.bmp", butter2, pal);}
//	if (key[KEY_I])
//	{save_bitmap("dump1.bmp", butter1, pal);}
//	masked_blit (butter1, butter, 0, 0, 0, 0, butter->w, butter->h);
//	masked_blit (butter2, butter, 0, 0, 0, 0, butter->w, butter->h);
//	blit (butter, screen, 0, 0, 0, 0, butter->w, butter->h);

//	destroy_bitmap (butter);
	destroy_bitmap (butter1);
	destroy_bitmap (butter2);
}
void dog_butter_picture_Char(int Char[4][4], int Char_Back[4][4])//所有人與第一人之位置差
{
	int i = 0;

	for (i = 0; i < 4; i++)
	{
		Char_Back[i][X] = Char[i][X] - Char[0][X];
		Char_Back[i][Y] = Char[i][Y] - Char[0][Y];
	}
}
void dog_picture(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],BITMAP *butter)//貼圖於畫面
{
	BITMAP *DOGP = load_bitmap ("image\\DOG\\DOG.bmp",NULL);
	BITMAP *DOGP2 = load_bitmap ("image\\DOG\\HEART.bmp",NULL);
	BITMAP *DOGP3 = create_bitmap (DP_WeaponW, DP_WeaponH);
	BITMAP *DOGP4 = load_bitmap ("image\\DOG\\DOG_ACT.bmp",NULL);

	dog_picture_ACT (Our,DOGP3);

	int i;
	for ( i = 0 ; i < 30 ; i++)
	{
		if (DOG[i][life] != DEAD)
		{masked_blit (DOGP, butter, 0, 0, DOG[i][X] - DP_MW/2, DOG[i][Y] - DP_MH/2, DP_MW, DP_MH);}
	}
	if(WEAPON[life] != DEAD)
	{masked_blit (DOGP3, butter, 0, 0, WEAPON[X] - DP_WeaponW/2, WEAPON[Y] - DP_WeaponH/2, DP_WeaponW, DP_WeaponH);}

	for ( i = 0 ; i < 30 ; i++)
	{
		if (BAMB[i][life] != DEAD)
		{masked_blit (DOGP4, butter, 0, 0, BAMB[i][X] - DP_MBW/2, BAMB[i][Y] - DP_MBH/2, DP_MBW, DP_MBH);}
	}

	masked_blit (DOGP3, butter, 0, 0, 0, 0, DP_WeaponW, DP_WeaponH);//左上角圖示
	for ( i = 0 ; i < Our[life] ; i++)
	{
		masked_blit (DOGP2, butter, 0, 0, DP_WeaponW*(i+1), 0, DP_WeaponW, DP_WeaponH);//左上角圖示
	}
	blit (butter, screen, 0, 0, 0, 0, butter->w, butter->h);

//	if (key[KEY_P])
//	{save_bitmap("dump.bmp", screen, pal);}

	destroy_bitmap (DOGP);
	destroy_bitmap (DOGP2);
	destroy_bitmap (DOGP3);
	destroy_bitmap (DOGP4);
}
void dog_picture_left(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],BITMAP *butter)//貼圖於畫面
{
	BITMAP *DOGP = load_bitmap ("image\\DOG\\DOG_left.bmp",NULL);
	BITMAP *DOGP2 = load_bitmap ("image\\DOG\\HEART.bmp",NULL);
	BITMAP *DOGP3 = create_bitmap (DP_WeaponW, DP_WeaponH);
	BITMAP *DOGP4 = load_bitmap ("image\\DOG\\DOG_ACT_left.bmp",NULL);

	dog_picture_ACT (Our,DOGP3);

	int i;
	for ( i = 0 ; i < 30 ; i++)
	{
		if (DOG[i][life] != DEAD)
		{masked_blit (DOGP, butter, 0, 0, DOG[i][X] - DP_MW/2, DOG[i][Y] - DP_MH/2, DP_MW, DP_MH);}
	}
	if(WEAPON[life] != DEAD)
	{masked_blit (DOGP3, butter, 0, 0, WEAPON[X] - DP_WeaponW/2, WEAPON[Y] - DP_WeaponH/2, DP_WeaponW, DP_WeaponH);}

	for ( i = 0 ; i < 30 ; i++)
	{
		if (BAMB[i][life] != DEAD)
		{masked_blit (DOGP4, butter, 0, 0, BAMB[i][X] - DP_MBW/2, BAMB[i][Y] - DP_MBH/2, DP_MBW, DP_MBH);}
	}

	masked_blit (DOGP3, butter, 0, 0, 0, 0, DP_WeaponW, DP_WeaponH);//左上角圖示
	for ( i = 0 ; i < Our[life] ; i++)
	{
		masked_blit (DOGP2, butter, 0, 0, DP_WeaponW*(i+1), 0, DP_WeaponW, DP_WeaponH);//左上角圖示
	}
	blit (butter, screen, 0, 0, 0, 0, butter->w, butter->h);

//	if (key[KEY_P])
//	{save_bitmap("dump.bmp", screen, pal);}

	destroy_bitmap (DOGP);
	destroy_bitmap (DOGP2);
	destroy_bitmap (DOGP3);
	destroy_bitmap (DOGP4);
}
void dog_picture_ACT(int Our[4],BITMAP *DOGP)//更換武器貼圖
{
	BITMAP *DOGP_ACT;
	if (Our[category] == 1)
	{DOGP_ACT = load_bitmap ("image\\DOG\\ACT1.bmp",NULL);}
	else if (Our[category] == 2)
	{DOGP_ACT = load_bitmap ("image\\DOG\\ACT2.bmp",NULL);}
	else if (Our[category] == 3)
	{DOGP_ACT = load_bitmap ("image\\DOG\\ACT3.bmp",NULL);}
	blit (DOGP_ACT, DOGP, 0, 0, 0, 0, DP_WeaponW, DP_WeaponH);
	destroy_bitmap (DOGP_ACT);
}
