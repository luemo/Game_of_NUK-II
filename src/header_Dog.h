#include <allegro.h>

int Dog(int People[4]);
int Dog_GoToLEFT(int People[4]);
////////////////////////////////��l��/////////////////////////////////////

void dog_place (int DOG[30][3]);//���w�Ĥ誺�y��(��l��)
void dog_bamb_place (int BAMB[30][3]);//���u��l�]�w����DEAD(��l��)
void dog_place_left (int DOG[30][3]);//���w�Ĥ誺�y��(��l��)

////////////////////////////////��l��/////////////////////////////////////

///////////////////////////////��������////////////////////////////////////

void dog_people_walk_seat (int Map[2],int We[2],int Char[4], BITMAP *BIGMAP);//�N�Z����m�P�Ĥ@�H��m���X

void dog_our_act (int Our[4],int WEAPON[4], int KEY);//�ڤ�o�ʧ����P�����

void dog_weapon_direction (int Face,int WEAPON[4]);//�ڤ�Ĥ@�H���V�P�l�u�o�g��m

void dog_weapon_movie (int WEAPON[4]);//�ڤ�l�u����

void dog_bamb_act (int DOG[3],int BAMB[3]);//�Ĥ�����}�l

void dog_bamb_movie (int BAMB[30][3]);//�Ĥ謵�u����
void dog_bamb_movie_left (int BAMB[30][3]);//�Ĥ謵�u����

///////////////////////////////��������////////////////////////////////////

/////////////////////////////�I���@�~����//////////////////////////////////

void dog_butter_picture(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],int *num, int *over,int MAP[2],int Char[4][4]);//����@�~�e��//Char���H���b�����خؤ�����m

void dog_butter_picture_Char(int Char[4][4], int Char_Back[4][4]);//�Ҧ��H�P�Ĥ@�H����m�t

///////////////////////////////butter1////////////////////////////////////

void dog_butter_picture_dog(int DOG[30][3], BITMAP *butter);//R = 255,G = �ĴX����,B = 0

void dog_butter_picture_our(int Our[4], BITMAP *butter,int Char_Back[4][4]);//R = 0,G = 255,B = 0

void dog_butter_picture_weapon(int WEAPON[4], BITMAP *butter);//R = 0,G = 255,B = 255

void dog_butter_picture_bamb(int BAMB[30][3], BITMAP *butter);//R = 50,G = �ĴX����������,B = 50

///////////////////////////////butter1////////////////////////////////////

///////////////////////////////butter2////////////////////////////////////

void dog_butter_picture_del_our(int Our[4], BITMAP *butter, int *num, int *over,int Char_Back[4][4]);

void dog_butter_picture_del_weapon(int WEAPON[4], BITMAP *butter, int *num);

void dog_butter_picture_del_bamb(int BAMB[30][3], BITMAP *butter, int *over);

///////////////////////////////butter2////////////////////////////////////

/////////////////////////////�I���@�~����//////////////////////////////////

///////////////////////////////���`����////////////////////////////////////

void dog_del_our (int BAMB[30][3],int Our[3],int *del);//�ڤ覺�`

void dog_del_dog (int DOG[30][3],int WEAPON[3],int *del);//�Ĥ覺�`
void dog_del_dog_left (int DOG[30][3],int WEAPON[3],int *del);//�Ĥ覺�`

///////////////////////////////���`����////////////////////////////////////

//////////////////////////////���^�Ӭ���///////////////////////////////////

void dog_comeback (int DOG[30][3],float T_Replacement_Dog[13]);//�P�O�P�C�����`�����`

void dog_comeback_movie (int DOG[30][3]);//���]�^��
void dog_comeback_movie_left (int DOG[30][3]);//���]�^��

//////////////////////////////���^�Ӭ���///////////////////////////////////

///////////////////////////////�K�Ϭ���////////////////////////////////////

void dog_picture(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],BITMAP *butter);//�K�ϩ�e��
void dog_picture_left(int DOG[30][3],int Our[4],int WEAPON[4],int BAMB[30][3],BITMAP *butter);//�K�ϩ�e��

void dog_picture_ACT(int Our[4],BITMAP *DOGP);//�󴫪Z���K��

///////////////////////////////�K�Ϭ���////////////////////////////////////

int dog_end (int DOG[30][3],int Our[3]);//����
int dog_end_left (int DOG[30][3],int Our[3]);//����
