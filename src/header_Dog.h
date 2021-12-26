#include <allegro.h>

int Dog(int People[4]);
int Dog_GoToLEFT(int People[4]);
////////////////////////////////初始化/////////////////////////////////////

void dog_place (int DOG[30][3]);//指定敵方的座標(初始化)
void dog_bamb_place (int BAMB[30][3]);//炸彈初始設定全為DEAD(初始化)
void dog_place_left (int DOG[30][3]);//指定敵方的座標(初始化)

////////////////////////////////初始化/////////////////////////////////////

///////////////////////////////攻擊相關////////////////////////////////////

void dog_people_walk_seat (int Map[2],int We[2],int Char[4], BITMAP *BIGMAP);//將武器位置與第一人位置重合

void dog_our_act (int Our[4],int WEAPON[4], int KEY);//我方發動攻擊與其種類

void dog_weapon_direction (int Face,int WEAPON[4]);//我方第一人面向與子彈發射位置

void dog_weapon_movie (int WEAPON[4]);//我方子彈移動

void dog_bamb_act (int DOG[3],int BAMB[3]);//敵方攻擊開始

void dog_bamb_movie (int BAMB[30][3]);//敵方炸彈移動
void dog_bamb_movie_left (int BAMB[30][3]);//敵方炸彈移動

///////////////////////////////攻擊相關////////////////////////////////////

/////////////////////////////背景作業相關//////////////////////////////////

void dog_butter_picture(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],int *num, int *over,int MAP[2],int Char[4][4]);//幕後作業畫面//Char為人物在中央框框中的位置

void dog_butter_picture_Char(int Char[4][4], int Char_Back[4][4]);//所有人與第一人之位置差

///////////////////////////////butter1////////////////////////////////////

void dog_butter_picture_dog(int DOG[30][3], BITMAP *butter);//R = 255,G = 第幾隻狗,B = 0

void dog_butter_picture_our(int Our[4], BITMAP *butter,int Char_Back[4][4]);//R = 0,G = 255,B = 0

void dog_butter_picture_weapon(int WEAPON[4], BITMAP *butter);//R = 0,G = 255,B = 255

void dog_butter_picture_bamb(int BAMB[30][3], BITMAP *butter);//R = 50,G = 第幾隻狗的攻擊,B = 50

///////////////////////////////butter1////////////////////////////////////

///////////////////////////////butter2////////////////////////////////////

void dog_butter_picture_del_our(int Our[4], BITMAP *butter, int *num, int *over,int Char_Back[4][4]);

void dog_butter_picture_del_weapon(int WEAPON[4], BITMAP *butter, int *num);

void dog_butter_picture_del_bamb(int BAMB[30][3], BITMAP *butter, int *over);

///////////////////////////////butter2////////////////////////////////////

/////////////////////////////背景作業相關//////////////////////////////////

///////////////////////////////死亡相關////////////////////////////////////

void dog_del_our (int BAMB[30][3],int Our[3],int *del);//我方死亡

void dog_del_dog (int DOG[30][3],int WEAPON[3],int *del);//敵方死亡
void dog_del_dog_left (int DOG[30][3],int WEAPON[3],int *del);//敵方死亡

///////////////////////////////死亡相關////////////////////////////////////

//////////////////////////////狗回來相關///////////////////////////////////

void dog_comeback (int DOG[30][3],float T_Replacement_Dog[13]);//判別同列狗死亡均死亡

void dog_comeback_movie (int DOG[30][3]);//狗跑回來
void dog_comeback_movie_left (int DOG[30][3]);//狗跑回來

//////////////////////////////狗回來相關///////////////////////////////////

///////////////////////////////貼圖相關////////////////////////////////////

void dog_picture(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],BITMAP *butter);//貼圖於畫面
void dog_picture_left(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],BITMAP *butter);//貼圖於畫面

void dog_picture_ACT(int Our[4],BITMAP *DOGP);//更換武器貼圖

///////////////////////////////貼圖相關////////////////////////////////////

int dog_end (int DOG[30][3],int Our[3]);//結束
int dog_end_left (int DOG[30][3],int Our[3]);//結束
