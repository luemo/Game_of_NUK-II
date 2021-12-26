#include <allegro.h>
#include "header_Flower.h"
#include "header_S_value.h"
#include "header_value_flower.h"

PALETTE pal;

void flower_butter_picture(int FLOWER[30][3],int Our[4],int BAMB[30][3],int *num, int *over)//幕後作業畫面
{
//BITMAP *butter1 = create_bitmap(SCREEN_W, SCREEN_H);
//clear_to_color(butter1,makecol(0,0,0));//RGB→黑

	BITMAP *butter = create_bitmap(SCREEN_W, SCREEN_H);
	clear_to_color(butter,makecol(0,0,0));//RGB→黑


	flower_butter_picture_flower(FLOWER,butter);//R = 255,G = 第幾朵花,B = 0

	flower_butter_picture_bamb(BAMB,butter);//R = 50,G = 第幾個大便的攻擊,B = 50

	flower_butter_picture_catch_flower (Our,butter,num,over);

	flower_butter_picture_catch_bamb (Our,butter,num,over);



//while(key[KEY_T])	{masked_blit (butter, butter1, 0, 0, 0, 0, butter->w, butter->h);blit (butter1, screen, 0, 0, 0, 0, butter->w, butter->h);}

	destroy_bitmap (butter);
//destroy_bitmap (butter1);
}


void flower_picture(int FLOWER[30][3],int Our[4],int BAMB[30][3],int flower)//貼圖於畫面
{
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap ("image/FLOWER/FLOWERBACK.bmp",NULL);//背景
	BITMAP *FLOWERP = load_bitmap ("image/FLOWER/FLOW_Flower.bmp",NULL);
	BITMAP *FLOWERP2 = load_bitmap ("image/character/WL.bmp",NULL);
	BITMAP *FLOWERP3 = load_bitmap ("image/FLOWER/HEART.bmp",NULL);
//	BITMAP *FLOWERP3 = create_bitmap (DP_WeaponW, DP_WeaponH);
	BITMAP *FLOWERP4 = load_bitmap ("image/FLOWER/FLOW_Hit.bmp",NULL);

	blit (background, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	int i;
	for ( i = 0 ; i < 30 ; i++)
	{
		if (FLOWER[i][life] != DEAD)
		{masked_blit (FLOWERP, butter, 0, 0, FLOWER[i][X] - FP_MW/2, FLOWER[i][Y] - FP_MH/2, FP_MW, FP_MH);}
//		{masked_blit (FLOWERP, butter, 0, 0, FLOWER[i][X] - 20/2, FLOWER[i][Y] - 20/2, 20, 20);}
//		{masked_blit (FLOWERP, butter, 0, 0, FLOWER[i][X] - FP_MW/2, FLOWER[i][Y] - FP_MH/2, FP_MW, FP_MH);}
	}
/*	if(WEAPON[life] != DEAD)
	{masked_blit (DOGP3, butter, 0, 0, WEAPON[X] - DP_WeaponW/2, WEAPON[Y] - DP_WeaponH/2, DP_WeaponW, DP_WeaponH);}*/
	masked_blit (FLOWERP2, butter, FP_PW*(1%3), FP_PH*UP, Our[X] - FP_PW/2, Our[Y] - FP_PH/2, FP_PW, FP_PH);

	for ( i = 0 ; i < 30 ; i++)
	{
		if (BAMB[i][life] != DEAD)
		{masked_blit (FLOWERP4, butter, 0, 0, BAMB[i][X] - FP_MBW/2, BAMB[i][Y] - FP_MBH/2, FP_MBW, FP_MBH);}
	}

//	masked_blit (DOGP3, butter, 0, 0, 0, 0, DP_WeaponW, DP_WeaponH);//左上角圖示
	for ( i = 0 ; i < Our[life] ; i++)
	{
		masked_blit (FLOWERP3, butter, 0, 0, FP_HeartW*(i), 0, FP_HeartW, FP_HeartH);//左上角圖示
	}
	for ( i = 0 ; i < flower ; i++)
	{
		masked_blit (FLOWERP3, butter, 0, 0, FP_HeartW*(i), FP_HeartH, FP_HeartW, FP_HeartH);//左上角圖示
	}
	blit (butter, screen, 0, 0, 0, 0, butter->w, butter->h);

//	if (key[KEY_P])
//	{save_bitmap("dump.bmp", screen, pal);}

	destroy_bitmap (FLOWERP);
	destroy_bitmap (FLOWERP2);
	destroy_bitmap (FLOWERP3);
	destroy_bitmap (FLOWERP4);

	destroy_bitmap (butter);
	destroy_bitmap (background);

}
