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
{//打狗程式((此函式可獨立運作(如果下面函式都在變可)，注意：必須與行走一同用
	int Char[4][4] = {{16,16,RIGHT,-1},{16,16,RIGHT,-1},{16,16,RIGHT,-1},{16,16,RIGHT,-1}};//X.Y.面向.輸入的指令(下一個面向)
	int Map[2] = {SQ_SIDE/2,480/2};
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap ("image\\DOG\\DOGBACK.bmp",NULL);//馬路
	BITMAP *Not = load_bitmap ("image\\DOG\\DOGBACKbarrier.bmp",NULL);//障礙物

	Character role;
	peoplework_chang (People,&role);

	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);

BITMAP *buff = create_bitmap (32, 32);clear_to_color(buff,makecol(255,255,255));

	int KEY = -1;int n = 0;
	int We[4] = {Map[X] - SQ_SIDE/2 + Char[0][X],Map[Y] - SQ_SIDE/2 + Char[0][Y],2,1};//第一個人位置X.Y,命,攻擊模式
	int DOG[30][3];//隻數;X,Y,死活
	int WEAPON[4] = {-1,-1,-1,0};//X,Y,死活,方向
	int Del = -1;	int OVER = -1;	int num = DEAD;	int over = DEAD;
	float T1 = 0;int ACT = 0;int ACT_NUM = -1;int ACT_NUM_ALL = -1;int counter = 0;
	int BAMB[30][3];//攻擊的隻數;X,Y,死活
	float T_Replacement_Dog[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};//同列狗均死亡且復活的瞬間 = 1

	dog_place (DOG);//初始化
	dog_bamb_place (BAMB);//初始化

	while ( OVER != WIN )//|| OVER == LOOSE)
	{
		rest(50);
		KEY = Read_Key ();

		People_Walking (Map,Char,role, background, Not, Sq_MAP,KEY);//3上0下1左2右

		dog_people_walk_seat (Map,We,Char[0], background);//武器攻擊初始位置

//while (key[KEY_P]){	blit (buff, screen, 0, 0, We[X]-16, We[Y]-16, 32, 32);}//test：人物位置與武器初始位置

		dog_our_act (We,WEAPON,KEY);//我方發動攻擊與其種類

		dog_weapon_direction (Char[0][life],WEAPON);//我方第一人面向與子彈發射位置

		dog_weapon_movie (WEAPON);//我方子彈移動

		dog_butter_picture(DOG,We,WEAPON,BAMB,&num,&over,Map,Char);//幕後作業畫面

		dog_del_our (BAMB,We,&over);//我方死亡

//		bee_bamb_act (Bee[1],Bamb[1]);//一隻狗攻擊

		ACT = Time_After (&T1,3);
		if (ACT == yes)													//3秒攻擊一次
		{
			ACT_NUM_ALL = rand()%4+1;									//1~4隻狗攻擊
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%15+1;									//隨機的狗做攻擊
				dog_bamb_act (DOG[ACT_NUM],BAMB[ACT_NUM]);
			}
			ACT = no;
		}

		dog_comeback(DOG,T_Replacement_Dog);	//狗復活

		dog_comeback_movie (DOG);				//狗跑回來

		dog_bamb_movie (BAMB);					//敵方炸彈移動

		dog_del_dog (DOG,WEAPON,&num);			//狗死亡
		

		for ( n=0; n <= 3 ; n++ ) 
		{
			people_walk_sq (Char, role, Sq_MAP,n,KEY);
//////////////////貼圖部分；中央框框/////////////////////////
			people_walk_map (Map, background, Sq_MAP,butter);
/////////////////貼圖部分；中央框框//////////////////////////
			dog_picture(DOG,We,WEAPON,BAMB,butter);	//貼圖
		}

		OVER = dog_end (DOG,We);				//遊戲結束


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
{//打狗程式((此函式可獨立運作(如果下面函式都在變可)，注意：必須與行走一同用
	int Char[4][4] = {{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1},{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1},{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1},{SQ_SIDE-16,SQ_SIDE-16,LEFT,-1}};//X.Y.面向.輸入的指令(下一個面向)
	int Map[2] = {SCREEN_W-SQ_SIDE/2,480/2};
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background = load_bitmap ("image\\DOG\\DOGBACK.bmp",NULL);//馬路
	BITMAP *Not = load_bitmap ("image\\DOG\\DOGBACKbarrier.bmp",NULL);//障礙物

	Character role;
	peoplework_chang (People,&role);

	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);

BITMAP *buff = create_bitmap (32, 32);clear_to_color(buff,makecol(255,255,255));

	int KEY = -1;int n = 0;
	int We[4] = {Map[X] - SQ_SIDE/2 + Char[0][X],Map[Y] - SQ_SIDE/2 + Char[0][Y],2,1};//第一個人位置X.Y,命,攻擊模式
	int DOG[30][3];//隻數;X,Y,死活
	int WEAPON[4] = {-1,-1,-1,0};//X,Y,死活,方向
	int Del = -1;	int OVER = -1;	int num = DEAD;	int over = DEAD;
	float T1 = 0;int ACT = 0;int ACT_NUM = -1;int ACT_NUM_ALL = -1;int counter = 0;
	int BAMB[30][3];//攻擊的隻數;X,Y,死活
	float T_Replacement_Dog[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};//同列狗均死亡且復活的瞬間 = 1

	dog_place_left (DOG);//初始化
	dog_bamb_place (BAMB);//初始化

	while ( OVER != WIN )//|| OVER == LOOSE)
	{
		rest(50);
		KEY = Read_Key ();

		People_Walking (Map,Char,role, background, Not, Sq_MAP,KEY);//3上0下1左2右

		dog_people_walk_seat (Map,We,Char[0], background);//武器攻擊初始位置

//while (key[KEY_P]){	blit (buff, screen, 0, 0, We[X]-16, We[Y]-16, 32, 32);}//test：人物位置與武器初始位置

		dog_our_act (We,WEAPON,KEY);//我方發動攻擊與其種類

		dog_weapon_direction (Char[0][life],WEAPON);//我方第一人面向與子彈發射位置

		dog_weapon_movie (WEAPON);//我方子彈移動

		dog_butter_picture(DOG,We,WEAPON,BAMB,&num,&over,Map,Char);//幕後作業畫面

		dog_del_our (BAMB,We,&over);//我方死亡

//		bee_bamb_act (Bee[1],Bamb[1]);//一隻狗攻擊

		ACT = Time_After (&T1,3);
		if (ACT == yes)													//3秒攻擊一次
		{
			ACT_NUM_ALL = rand()%4+1;									//1~4隻狗攻擊
			for (counter = 0; counter <= ACT_NUM_ALL; counter++)
			{
				ACT_NUM = rand()%15+1;									//隨機的狗做攻擊
				dog_bamb_act (DOG[ACT_NUM],BAMB[ACT_NUM]);
			}
			ACT = no;
		}

		dog_comeback(DOG,T_Replacement_Dog);	//狗復活

		dog_comeback_movie_left (DOG);			//狗跑回來

		dog_bamb_movie_left (BAMB);					//敵方炸彈移動

		dog_del_dog_left (DOG,WEAPON,&num);			//狗死亡
		

		for ( n=0; n <= 3 ; n++ ) 
		{
			people_walk_sq (Char, role, Sq_MAP,n,KEY);
//////////////////貼圖部分；中央框框/////////////////////////
			people_walk_map (Map, background, Sq_MAP,butter);
/////////////////貼圖部分；中央框框//////////////////////////
			dog_picture_left(DOG,We,WEAPON,BAMB,butter);	//貼圖
		}

		OVER = dog_end_left (DOG,We);				//遊戲結束

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
