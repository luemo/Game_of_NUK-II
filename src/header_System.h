#include <allegro.h>
#include <stdio.h>
#include "header_S_value.h"
//#include "header_value_walk.h"
typedef struct struct_char{
	int map_number;
	int Char_1[4];
	int Char_2[4];
	int Char_3[4];
	int Char_4[4];
	int Map[2];
	int people[4];
}CharacterA;

void Init();
void Exit();

int Read_Key ();//3�W0�U1��2�k//����V�� - �M�w��V - �S������^��-1

void Time_Delay (float time);

int Time_After (float *T1, float T2);

int Main_Menu ();
int Menu (int map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);

void map_change(int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);

void Walk_init (int Char[4][4], int M_X, int M_Y, int M_Face);
//int people_site_CO1(int Map[2],int Char[4][4]);

void EvenMain_init (int EvenMain[EvenALL]);
int People_site_Green (int Map[2],int Char[4],int Site_X,int Site_Y,BITMAP *Not);

void Save (int map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);
void Load(int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);

/////////////�a�Ϥ����A��
int Map_Blue_Change (BITMAP *Mask,FILE *map,int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);
/////////////�ƥ�Ĳ�o�A��
int Map_Green_Change (BITMAP *Mask,FILE *map,int KEY,int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL]);
/////////////�H���K�ϾA��
int Map_People_Paste (BITMAP *P_MAP,BITMAP *Mask,FILE *map,int EvenMain[EvenALL]);
