#include <allegro.h>
//#include <stdio.h>
//#include "header_Flower.h"
#include "header_S_value.h"
#include "header_value_flower.h"

void flower_butter_picture_catch_flower (int Our[4], BITMAP *butter, int *num, int *over)
{	int A,B;

	for (A = -F_PW/2; A < F_PW/2; A++)
	{
		if ( *num != DEAD )
		{break;}
	for (B = -F_PH/2; B < F_PH/2; B++)
	{
		if (butter->line[Our[Y]+B][(Our[X]+A)*3+2] == 255)//BGR
		{
			*over = Flower_Catch;
			*num = butter->line[Our[Y]+B][(Our[X]+A)*3+1];
		}
		if ( *num != DEAD )
		{break;}
	}
	}
}
void flower_butter_picture_catch_bamb (int Our[4], BITMAP *butter, int *num, int *over)
{	int A,B;

	for (A = -F_PW/2; A < F_PW/2; A++)
	{
		if ( *num != DEAD )
		{break;}
	for (B = -F_PH/2; B < F_PH/2; B++)
	{
		if (butter->line[Our[Y]+B][(Our[X]+A)*3+2] == 50)//BGR
		{
			*over = Stoll_Catch;
			*num = butter->line[Our[Y]+B][(Our[X]+A)*3+1];
		}
		if ( *num != DEAD )
		{break;}
	}
	}
}
/**/
void flower_del_our (int BAMB[30][3],int Our[4],int *num,int *del)//我方接到大便
{
	if (*del == Stoll_Catch)
	{
		Our[Y] = Our[Y] - 32;
		Our[life] = Our[life] - 1;
		BAMB[*num][X] = DEAD;
		BAMB[*num][Y] = DEAD;
		BAMB[*num][life] = DEAD;
		*del = DEAD;
		*num = DEAD;
	}
	else {Our[Y] = SCREEN_H - FP_PH/2;}//正常位置
}
void flower_del_catch (int FLOWER[30][3],int Our[4],int *flower,int *num,int *del)//我方接到花
{
	if (*del == Flower_Catch)
	{
		Our[Y] = Our[Y] - 16;
		*flower = *flower + 1;
		FLOWER[*num][X] = DEAD;
		FLOWER[*num][Y] = DEAD;
		FLOWER[*num][life] = DEAD;
		*del = DEAD;
		*num = DEAD;
	}
//	else {Our[Y] = SCREEN_H - FP_PH/2;}//正常位置→再跑一圈時就會回來，所以這裡不設，接到大便那邊會判斷
}
int flower_end (int flower,int Our[4])//結束
{
	if (flower >= 10)
	{return WIN;}

	if (Our[life] < 0)
	{return LOOSE;}

	return not;
}