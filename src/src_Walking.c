#include <allegro.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
//#include "header_Dog.h"
#include "header_Walk.h"
#include "header_value_walk.h"
#include "header_System.h"

void Walking(int Map[2], int Char[4][4], Character role, BITMAP *BIGMAP, BITMAP *barrier,int KEY)
{//�@�먫�����{��((���t�����p��P���ʶK��
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);

	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);


	int n = 0;

	People_Walking (Map,Char,role, BIGMAP, barrier, Sq_MAP,KEY);//3�W0�U1��2�k
		for ( n=0; n <= 3 ; n++ ) 
		{
			people_walk_sq (Char, role, Sq_MAP,n,KEY);
//////////////////�K�ϳ����F�����خ�/////////////////////////
			people_walk_map (Map, BIGMAP, Sq_MAP,butter);
/////////////////�K�ϳ����F�����خ�//////////////////////////
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//			rest (25);
		}
	destroy_bitmap (butter);
	destroy_bitmap (Sq_MAP);
}
