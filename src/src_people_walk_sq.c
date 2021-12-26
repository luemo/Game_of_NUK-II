#include <allegro.h>
#include <stdio.h>
#include "header_value_walk.h"
#include "header_S_value.h"

//�����������ê�P����


void people_walk_sq_red (int Map[2], int Char[4], BITMAP *barrier, BITMAP *butter_red)
{//�����������ê
//Map[2] = ����������K�I�AChar[4] = �Ĥ@�H�����K�I�Abarrier = �j�a�Ϫ���ê���Abutter_red = �����������ê��
//1.���X���������ê��
//2.i = �j�a�Ϫ���ê��(barrier)��X�K�I;j = �j�a�Ϫ���ê��(barrier)��Y�K�I
//3.Map[0] = �H���i���ʽd��(����)��X�I;Map[0] = �H���i���ʽd��(����)��Y�I
//4.�^�Ǥ����ê��

	int i = 0,j = 0;

		if (Map[Y] >= 0 && Map[Y] <= SQ_SIDE/2)			//���E��Ө���(�����I���j�a����� - ����j�p/2)
		{j = 0;}
		else if (Map[Y] > SQ_SIDE/2 && Map[Y] < barrier->h - SQ_SIDE/2)
		{j = Map[Y] - SQ_SIDE/2;}
		else if (Map[Y] >= barrier->h - SQ_SIDE/2 && Map[Y] <= barrier->h)
		{j = barrier->h - SQ_SIDE;}

		if (Map[X] >= 0 && Map[X] <= SQ_SIDE/2)
		{i = 0;}
		else if (Map[X] > SQ_SIDE/2 && Map[X] < barrier->w - SQ_SIDE/2)
		{i = Map[X] - SQ_SIDE/2;}
		else if (Map[X] >= barrier->w - SQ_SIDE/2 && Map[X] <= barrier->w)
		{i =barrier->w - SQ_SIDE;}

		blit (barrier, butter_red, i - PeopleW, j - PeopleH, 0, 0, SQ_SIDE + PeopleW*2, SQ_SIDE + PeopleH*2);	//�i�^�Ǫ������ê��
}

void people_walk_sq_movie (int Map[2], int Char[4], BITMAP *BIGMAP)
{
	if (Char[Direction] == UP)
	{
		Map[Y] = Map[Y] - PeopleH;

		if (Map[Y] < SQ_SIDE/2)//�p�G�W�L�W��ɫh�]���̤W
		{Map[Y] = SQ_SIDE/2;}
	}	//end of key[KEY_UP]

	if (Char[Direction] == DOWN)
	{
		Map[Y] = Map[Y] + PeopleH;

		if (Map[Y] > BIGMAP->h - SQ_SIDE/2)//�p�G�W�L�U��ɫh�]���̤U - �����/2
		{Map[Y] = BIGMAP->h - SQ_SIDE/2;}
	}	//end of key[KEY_DOWN]

	if (Char[Direction] == LEFT)
	{
		Map[X] = Map[X] - PeopleW;

		if (Map[X] < SQ_SIDE/2)//�p�G�W�L����ɫh�]���̥�
		{Map[X] = SQ_SIDE/2;}
	}	//end of key[KEY_LEFT]
	if (Char[Direction] == RIGHT)
	{
		Map[X] = Map[X] + PeopleW;

		if (Map[X] > BIGMAP->w - SQ_SIDE/2)//�p�G�W�L�k��ɫh�]���̥k - ����e/2
		{Map[X] = BIGMAP->w - SQ_SIDE/2;}
	}	//end of key[KEY_RIGHT]
}