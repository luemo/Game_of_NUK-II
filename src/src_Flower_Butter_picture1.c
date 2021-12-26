#include <allegro.h>
#include "header_value_flower.h"
#include "header_S_value.h"

void flower_butter_picture_flower(int FLOWER[30][3], BITMAP *butter)//R = 255,G = 第幾朵花,B = 0
{
	BITMAP *butter2 = create_bitmap(F_MW,F_MH);

	int i;
	for ( i = 0 ; i < 30 ; i++)
	{
		if(FLOWER[i][life] != DEAD)
		{
			clear_to_color(butter2,makecol(255,i,0));//RGB
			blit (butter2, butter, 0, 0, FLOWER[i][X] - F_MW/2, FLOWER[i][Y] - F_MH/2, F_MW, F_MH);
		}
	}
	destroy_bitmap (butter2);
}
void flower_butter_picture_bamb(int BAMB[30][3], BITMAP *butter)//R = 50,G = 第幾個大便的攻擊,B = 50
{
	int i;
	BITMAP *butter2 = create_bitmap(F_MBW,F_MBH);
	for ( i = 0 ; i < 30 ; i++)
	{
		if(BAMB[i][life] != DEAD)
		{
			clear_to_color(butter2,makecol(50,i,50));//RGB
			blit (butter2, butter, 0, 0, BAMB[i][X] - F_MBW/2, BAMB[i][Y] - F_MBH/2, F_MBW, F_MBH);
		}
	}
	destroy_bitmap (butter2);
}
