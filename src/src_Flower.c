#include <allegro.h>
#include "header_Flower.h"
#include "header_System.h"
#include "header_S_value.h"
#include "header_value_flower.h"

int Flower()
{//����{��((���禡�i�W�߹B�@(�p�G�U���禡���b�ܥi)
	int KEY = -1;int Catch_Flower_Num = 0;
	int We[4] = {SCREEN_W - FP_PW/2,SCREEN_H - FP_PH/2,3,1};//�Ĥ@�ӤH��mX.Y,�R,�����Ҧ�
	int FLOWER[30][3];//����;X,Y,����
	int OVER = -1;	int num = DEAD;	int over = DEAD;
	float T1 = 0;float T2 = 0;int ACT = 0;int ACT_NUM = -1;int ACT_NUM_ALL = -1;int counter = 0;//����ɶ�
	int BAMB[30][3];//����������;X,Y,����

	flower_place (FLOWER);//��l��
	flower_bamb_place (BAMB);//��l��

	while ( OVER != WIN )//|| OVER == LOOSE)
	{
		rest(50);
		KEY = Read_Key ();

		flower_our_movie (We,KEY);//�ڤ貾��

		ACT = Time_After (&T1,3);
		if (ACT == yes)													//3����@��
		{
			ACT_NUM_ALL = rand()%4;									//1~4���Ḩ�U
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%30;									//�H�����Ḩ�U
				flower_fall (FLOWER[ACT_NUM]);
			}
			ACT = no;
		}
		ACT = Time_After (&T2,3);
		if (ACT == yes)													//3���Ǫ��@��
		{
			ACT_NUM_ALL = rand()%4;									//1~4���Ǫ����U
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%30;									//�H�����Ǫ����U
				flower_fall (BAMB[ACT_NUM]);
			}
			ACT = no;
		}

		flower_movie (FLOWER);//�Ḩ�U��

		flower_movie (BAMB);//�Ǫ����U��

		flower_butter_picture (FLOWER,We,BAMB,&num,&over);//����@�~�e��

		flower_del_our (BAMB,We,&num,&over);//�ڤ豵��j�K

		flower_del_catch (FLOWER,We,&Catch_Flower_Num,&num,&over);//�ڤ豵���

		flower_picture(FLOWER,We,BAMB,Catch_Flower_Num);//�K�ϩ�e��

		OVER = flower_end (Catch_Flower_Num,We);//����

		if (key[KEY_ESC] || OVER == LOOSE)
		{break;}
	}
	return OVER;
}