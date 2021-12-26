#include <allegro.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "header_Dog.h"
#include "header_S_value.h"
#include "header_Walk.h"
#include "header_value_walk.h"
#include "header_System.h"

int Dog(int People[4])
{//�����{��((���禡�i�W�߹B�@(�p�G�U���禡���b�ܥi)�A�`�N�G�����P�樫�@�P��
	int Char[4][4] = {{16,16,RIGHT,-1},{16,16,RIGHT,-1},{16,16,RIGHT,-1},{16,16,RIGHT,-1}};//X.Y.���V.��J�����O(�U�@�ӭ��V)
	int Map[2] = {SQ_SIDE/2,480/2};
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap ("image\\DOG\\DOGBACK.bmp",NULL);//����
	BITMAP *Not = load_bitmap ("image\\DOG\\DOGBACKbarrier.bmp",NULL);//��ê��

	Character role;
	peoplework_chang (People,&role);

	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);

BITMAP *buff = create_bitmap (32, 32);clear_to_color(buff,makecol(255,255,255));

	int KEY = -1;int n = 0;
	int We[4] = {Map[X] - SQ_SIDE/2 + Char[0][X],Map[Y] - SQ_SIDE/2 + Char[0][Y],2,1};//�Ĥ@�ӤH��mX.Y,�R,�����Ҧ�
	int DOG[30][3];//����;X,Y,����
	int WEAPON[4] = {-1,-1,-1,0};//X,Y,����,��V
	int Del = -1;	int OVER = -1;	int num = DEAD;	int over = DEAD;
	float T1 = 0;int ACT = 0;int ACT_NUM = -1;int ACT_NUM_ALL = -1;int counter = 0;
	int BAMB[30][3];//����������;X,Y,����
	float T_Replacement_Dog[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};//�P�C�������`�B�_�������� = 1

	dog_place (DOG);//��l��
	dog_bamb_place (BAMB);//��l��

	while ( OVER != WIN )//|| OVER == LOOSE)
	{
		rest(50);
		KEY = Read_Key ();

		People_Walking (Map,Char,role, background, Not, Sq_MAP,KEY);//3�W0�U1��2�k

		dog_people_walk_seat (Map,We,Char[0], background);//�Z��������l��m

//while (key[KEY_P]){	blit (buff, screen, 0, 0, We[X]-16, We[Y]-16, 32, 32);}//test�G�H����m�P�Z����l��m

		dog_our_act (We,WEAPON,KEY);//�ڤ�o�ʧ����P�����

		dog_weapon_direction (Char[0][life],WEAPON);//�ڤ�Ĥ@�H���V�P�l�u�o�g��m

		dog_weapon_movie (WEAPON);//�ڤ�l�u����

		dog_butter_picture(DOG,We,WEAPON,BAMB,&num,&over,Map,Char);//����@�~�e��

		dog_del_our (BAMB,We,&over);//�ڤ覺�`

//		bee_bamb_act (Bee[1],Bamb[1]);//�@��������

		ACT = Time_After (&T1,3);
		if (ACT == yes)													//3������@��
		{
			ACT_NUM_ALL = rand()%4+1;									//1~4��������
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%15+1;									//�H������������
				dog_bamb_act (DOG[ACT_NUM],BAMB[ACT_NUM]);
			}
			ACT = no;
		}

		dog_comeback(DOG,T_Replacement_Dog);	//���_��

		dog_comeback_movie (DOG);				//���]�^��

		dog_bamb_movie (BAMB);					//�Ĥ謵�u����

		dog_del_dog (DOG,WEAPON,&num);			//�����`
		

		for ( n=0; n <= 3 ; n++ ) 
		{
			people_walk_sq (Char, role, Sq_MAP,n,KEY);
//////////////////�K�ϳ����F�����خ�/////////////////////////
			people_walk_map (Map, background, Sq_MAP,butter);
/////////////////�K�ϳ����F�����خ�//////////////////////////
			dog_picture(DOG,We,WEAPON,BAMB,butter);	//�K��
		}

		OVER = dog_end (DOG,We);				//�C������


		if (key[KEY_ESC] || OVER == LOOSE)
		{break;}
	}

	destroy_bitmap (butter);
	destroy_bitmap (background);
	destroy_bitmap (Not);
	destroy_bitmap (Sq_MAP);

	destroy_bitmap (buff);

	return OVER;
}

int Dog_GoToLEFT(int People[4])
{//�����{��((���禡�i�W�߹B�@(�p�G�U���禡���b�ܥi)�A�`�N�G�����P�樫�@�P��
	int Char[4][4] = {{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1},{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1},{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1},{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1}};//X.Y.���V.��J�����O(�U�@�ӭ��V)
	int Map[2] = {SCREEN_W-SQ_SIDE/2,480/2};
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap ("image\\DOG\\DOGBACK.bmp",NULL);//����
	BITMAP *Not = load_bitmap ("image\\DOG\\DOGBACKbarrier.bmp",NULL);//��ê��

	Character role;
	peoplework_chang (People,&role);

	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);

BITMAP *buff = create_bitmap (32, 32);clear_to_color(buff,makecol(255,255,255));

	int KEY = -1;int n = 0;
	int We[4] = {Map[X] - SQ_SIDE/2 + Char[0][X],Map[Y] - SQ_SIDE/2 + Char[0][Y],2,1};//�Ĥ@�ӤH��mX.Y,�R,�����Ҧ�
	int DOG[30][3];//����;X,Y,����
	int WEAPON[4] = {-1,-1,-1,0};//X,Y,����,��V
	int Del = -1;	int OVER = -1;	int num = DEAD;	int over = DEAD;
	float T1 = 0;int ACT = 0;int ACT_NUM = -1;int ACT_NUM_ALL = -1;int counter = 0;
	int BAMB[30][3];//����������;X,Y,����
	float T_Replacement_Dog[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};//�P�C�������`�B�_�������� = 1

	dog_place_left (DOG);//��l��
	dog_bamb_place (BAMB);//��l��

	while ( OVER != WIN )//|| OVER == LOOSE)
	{
		rest(50);
		KEY = Read_Key ();

		People_Walking (Map,Char,role, background, Not, Sq_MAP,KEY);//3�W0�U1��2�k

		dog_people_walk_seat (Map,We,Char[0], background);//�Z��������l��m

//while (key[KEY_P]){	blit (buff, screen, 0, 0, We[X]-16, We[Y]-16, 32, 32);}//test�G�H����m�P�Z����l��m

		dog_our_act (We,WEAPON,KEY);//�ڤ�o�ʧ����P�����

		dog_weapon_direction (Char[0][life],WEAPON);//�ڤ�Ĥ@�H���V�P�l�u�o�g��m

		dog_weapon_movie (WEAPON);//�ڤ�l�u����

		dog_butter_picture(DOG,We,WEAPON,BAMB,&num,&over,Map,Char);//����@�~�e��

		dog_del_our (BAMB,We,&over);//�ڤ覺�`

//		bee_bamb_act (Bee[1],Bamb[1]);//�@��������

		ACT = Time_After (&T1,3);
		if (ACT == yes)													//3������@��
		{
			ACT_NUM_ALL = rand()%4+1;									//1~4��������
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%15+1;									//�H������������
				dog_bamb_act (DOG[ACT_NUM],BAMB[ACT_NUM]);
			}
			ACT = no;
		}

		dog_comeback(DOG,T_Replacement_Dog);	//���_��

		dog_comeback_movie_left (DOG);			//���]�^��

		dog_bamb_movie_left (BAMB);					//�Ĥ謵�u����

		dog_del_dog_left (DOG,WEAPON,&num);			//�����`
		

		for ( n=0; n <= 3 ; n++ ) 
		{
			people_walk_sq (Char, role, Sq_MAP,n,KEY);
//////////////////�K�ϳ����F�����خ�/////////////////////////
			people_walk_map (Map, background, Sq_MAP,butter);
/////////////////�K�ϳ����F�����خ�//////////////////////////
			dog_picture_left(DOG,We,WEAPON,BAMB,butter);	//�K��
		}

		OVER = dog_end_left (DOG,We);				//�C������

		if (key[KEY_ESC] || OVER == LOOSE)
		{break;}
	}

	destroy_bitmap (butter);
	destroy_bitmap (background);
	destroy_bitmap (Not);
	destroy_bitmap (Sq_MAP);

	destroy_bitmap (buff);

	return OVER;
}
