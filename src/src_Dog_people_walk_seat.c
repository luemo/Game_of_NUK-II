#include <allegro.h>
#include "header_S_value.h"
#include "header_value_walk.h"

void dog_people_walk_seat (int Map[2],int We[2],int Char[4], BITMAP *BIGMAP)//�N�Z����m�P�Ĥ@�H��m���X
{
//1.�N��Ӥj�a��(BIGMAP)�����E�����A�H��ɨ�1/2�e�����ɽu����
//2.i = �j�a��(BIGMAP)��X�K�I;j = �j�a��(BIGMAP)��Y�K�I;k = ���(butter)��X�K�I;l = ���(butter)��Y�K�I
//4.Map[0] = �H���i���ʽd��(����)��X�I;Map[1] = �H���i���ʽd��(����)��Y�I;MAP[2]���Ȥ���SQ_SIDE/2��BIGMAP - SQ_SIDE/2

	int k = 0,l = 0;

	if (Map[1] >= SQ_SIDE/2 && Map[1] <= SCREEN_H/2)			//�K�樫�a��;���E�����ӶK��(�����I���j�a����� - �����j�p/2)
	{l = Map[1] - SQ_SIDE/2;}
	else if (Map[1] > SCREEN_H/2 && Map[1] <= BIGMAP->h - SCREEN_H/2)
	{l = SCREEN_H/2 - SQ_SIDE/2;}
	else if (Map[1] > BIGMAP->h - SCREEN_H/2 && Map[1] <= BIGMAP->h - SQ_SIDE/2)
	{l = SCREEN_H - (BIGMAP->h - Map[1]) - SQ_SIDE/2;}

	if (Map[0] >= SQ_SIDE/2 && Map[0] <= SCREEN_W/2)
	{k = Map[0] - SQ_SIDE/2;}
	else if (Map[0] > SCREEN_W/2 && Map[0] <= BIGMAP->w - SCREEN_W/2)
	{k = SCREEN_W/2 - SQ_SIDE/2;}
	else if (Map[0] > BIGMAP->w - SCREEN_W/2 && Map[0] <= BIGMAP->w - SQ_SIDE/2)
	{k = SCREEN_W - (BIGMAP->w - Map[0]) - SQ_SIDE/2;}

	We[0] = k + Char[0];
	We[1] = l + Char[1];

}