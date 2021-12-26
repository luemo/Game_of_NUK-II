#include <allegro.h>
#include "header_value_walk.h"
#include "header_S_value.h"

#ifndef Character
	typedef struct struct_character{
		BITMAP *character1;
		BITMAP *character2;
		BITMAP *character3;
		BITMAP *character4;
	}Character;
#endif

void people_walk_map (int Map[2], BITMAP *BIGMAP, BITMAP *Sq_MAP, BITMAP *butter)
{
//1.�N��Ӥj�a��(BIGMAP)�����E�����A�H��ɨ�1/2�e�����ɽu����
//2.i = �j�a��(BIGMAP)��X�K�I;j = �j�a��(BIGMAP)��Y�K�I;k = ���(butter)��X�K�I;l = ���(butter)��Y�K�I
//4.Map[0] = �H���i���ʽd��(����)��X�I;Map[1] = �H���i���ʽd��(����)��Y�I;MAP[2]���Ȥ���SQ_SIDE/2��BIGMAP - SQ_SIDE/2

	BITMAP *buff = create_bitmap (SCREEN_W, SCREEN_H);	//�Ȧs���A���K�j�a��(BIGMAP)�A�A�K���������(butter)

	int i = 0,j = 0;
	int k = 0,l = 0;

	if (Map[Y] >= 0 && Map[Y] <= SCREEN_H/2)			//�K�j�a��;���E�����ӶK��(�����I���j�a����� - �����j�p/2)
	{j = 0;}
	else if (Map[Y] > SCREEN_H/2 && Map[Y] < BIGMAP->h - SCREEN_H/2)
	{j = Map[Y] - SCREEN_H/2;}
	else if (Map[Y] >= BIGMAP->h - SCREEN_H/2 && Map[Y] <= BIGMAP->h)
	{j = BIGMAP->h - SCREEN_H;}

	if (Map[X] >= 0 && Map[X] <= SCREEN_W/2)
	{i = 0;}
	else if (Map[X] > SCREEN_W/2 && Map[X] < BIGMAP->w - SCREEN_W/2)
	{i = Map[X] - SCREEN_W/2;}
	else if (Map[X] >= BIGMAP->w - SCREEN_W/2 && Map[X] <= BIGMAP->w)
	{i = BIGMAP->w - SCREEN_W;}


	if (Map[Y] >= SQ_SIDE/2 && Map[Y] <= SCREEN_H/2)			//�K�樫�a��;���E�����ӶK��(�����I���j�a����� - �����j�p/2)
	{l = Map[Y] - SQ_SIDE/2;}
	else if (Map[1] > SCREEN_H/2 && Map[Y] <= BIGMAP->h - SCREEN_H/2)
	{l = SCREEN_H/2 - SQ_SIDE/2;}
	else if (Map[Y] > BIGMAP->h - SCREEN_H/2 && Map[Y] <= BIGMAP->h - SQ_SIDE/2)
	{l = SCREEN_H - (BIGMAP->h - Map[Y]) - SQ_SIDE/2;}


	if (Map[X] >= SQ_SIDE/2 && Map[X] <= SCREEN_W/2)
	{k = Map[X] - SQ_SIDE/2;}
	else if (Map[X] > SCREEN_W/2 && Map[X] <= BIGMAP->w - SCREEN_W/2)
	{k = SCREEN_W/2 - SQ_SIDE/2;}
	else if (Map[X] > BIGMAP->w - SCREEN_W/2 && Map[X] <= BIGMAP->w - SQ_SIDE/2)
	{k = SCREEN_W - (BIGMAP->w - Map[X]) - SQ_SIDE/2;}


	blit (BIGMAP, buff, i, j, 0, 0, SCREEN_W, SCREEN_H);

//if (key[KEY_Q]){blit (Sq_MAP, buff, 0, 0, k, l, SQ_SIDE, SQ_SIDE);}

	masked_blit (Sq_MAP, buff, 0, 0, k, l, SQ_SIDE, SQ_SIDE);

//	blit (buff, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (buff, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	destroy_bitmap (buff);
}



void people_walk_sq (int Char[4][4], Character role, BITMAP *Sq_MAP,int n,int KEY)
{
	if ( KEY == not )
	{n = 1;}
	masked_blit (role.character4, Sq_MAP, PeopleW*(n%3), PeopleH*Char[3][Direction], Char[3][X] - PeopleW/2, Char[3][Y] - PeopleH/2, PeopleW, PeopleH);
	masked_blit (role.character3, Sq_MAP, PeopleW*(n%3), PeopleH*Char[2][Direction], Char[2][X] - PeopleW/2, Char[2][Y] - PeopleH/2, PeopleW, PeopleH);
	masked_blit (role.character2, Sq_MAP, PeopleW*(n%3), PeopleH*Char[1][Direction], Char[1][X] - PeopleW/2, Char[1][Y] - PeopleH/2, PeopleW, PeopleH);
	masked_blit (role.character1, Sq_MAP, PeopleW*(n%3), PeopleH*Char[0][Direction], Char[0][X] - PeopleW/2, Char[0][Y] - PeopleH/2, PeopleW, PeopleH);
}
