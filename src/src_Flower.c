#include <allegro.h>
#include "header_Flower.h"
#include "header_System.h"
#include "header_S_value.h"
#include "header_value_flower.h"

int Flower()
{//接花程式((此函式可獨立運作(如果下面函式都在變可)
	int KEY = -1;int Catch_Flower_Num = 0;
	int We[4] = {SCREEN_W - FP_PW/2,SCREEN_H - FP_PH/2,3,1};//第一個人位置X.Y,命,攻擊模式
	int FLOWER[30][3];//隻數;X,Y,死活
	int OVER = -1;	int num = DEAD;	int over = DEAD;
	float T1 = 0;float T2 = 0;int ACT = 0;int ACT_NUM = -1;int ACT_NUM_ALL = -1;int counter = 0;//落花時間
	int BAMB[30][3];//攻擊的隻數;X,Y,死活

	flower_place (FLOWER);//初始化
	flower_bamb_place (BAMB);//初始化

	while ( OVER != WIN )//|| OVER == LOOSE)
	{
		rest(50);
		KEY = Read_Key ();

		flower_our_movie (We,KEY);//我方移動

		ACT = Time_After (&T1,3);
		if (ACT == yes)													//3秒落花一次
		{
			ACT_NUM_ALL = rand()%4;									//1~4朵花落下
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%30;									//隨機的花落下
				flower_fall (FLOWER[ACT_NUM]);
			}
			ACT = no;
		}
		ACT = Time_After (&T2,3);
		if (ACT == yes)													//3秒落怪物一次
		{
			ACT_NUM_ALL = rand()%4;									//1~4隻怪物落下
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%30;									//隨機的怪物落下
				flower_fall (BAMB[ACT_NUM]);
			}
			ACT = no;
		}

		flower_movie (FLOWER);//花落下來

		flower_movie (BAMB);//怪物落下來

		flower_butter_picture (FLOWER,We,BAMB,&num,&over);//幕後作業畫面

		flower_del_our (BAMB,We,&num,&over);//我方接到大便

		flower_del_catch (FLOWER,We,&Catch_Flower_Num,&num,&over);//我方接到花

		flower_picture(FLOWER,We,BAMB,Catch_Flower_Num);//貼圖於畫面

		OVER = flower_end (Catch_Flower_Num,We);//結束

		if (key[KEY_ESC] || OVER == LOOSE)
		{break;}
	}
	return OVER;
}