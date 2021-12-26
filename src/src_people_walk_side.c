#include <allegro.h>
#include "header_value_walk.h"
#include "header_S_value.h"

//����������ʮ�
//��H���b�����������ɮ�

int people_walk_side (int Char[4][4], BITMAP *butter)
{
//�Ҧ��H�Ʀ����u�B���Y�H�b������^��W_PSide(=100)((���ᤣ���ʧ@((�Ҧ��H���V��m����
//���Y�H�b����������|�����s,�̤��P����m�^�Ǥ��P����W_PSide01,W_PSide02,W_PSide03 = {10.20.30}
//���b��ɦ^��no(=0)
////////////////////////////////////////////////////////////////////////////////////////////
//�P���V�B�ƪ��u�����ʧ@
//���b��ɦ^��W_PSide(=100)
	if (Char[0][Direction] == Char[1][Direction] && Char[0][Direction] == Char[2][Direction] && Char[0][Direction] == Char[3][Direction])
	{
		if (Char[0][X] == Char[1][X] && Char[0][X] == Char[2][X] && Char[0][X] == Char[3][X])
		{
			if (Char[0][Y] < PeopleH && Char[0][Direction] == UP && Char[0][N_Direction] == UP)
			{return W_PSide;}
			else if (Char[0][Y] > butter->h - PeopleH && Char[0][Direction] == DOWN && Char[0][N_Direction] == DOWN)
			{return W_PSide;}
		}
		else if (Char[0][Y] == Char[1][Y] && Char[0][Y] == Char[2][Y] && Char[0][Y] == Char[3][Y])
		{
			if (Char[0][X] < PeopleW && Char[0][Direction] == LEFT && Char[0][N_Direction] == LEFT)
			{return W_PSide;}
			else if (Char[0][X] > butter->w - PeopleW && Char[0][Direction] == RIGHT && Char[0][N_Direction] == RIGHT)
			{return W_PSide;}
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////////////////////*/
//���Y�H�b����������|�����s

	if (Char[0][Y] == Char[1][Y])//�W�U
	{
		if (Char[0][Y] < PeopleH && Char[0][Direction] == UP)
		{return W_PSide01;}
		else if (Char[0][Y] > butter->h - PeopleH && Char[0][Direction] == DOWN)
		{return W_PSide01;}
	}

	if (Char[1][Y] == Char[2][Y])
	{
		if (Char[0][Y] < PeopleH && Char[0][Direction] == UP)
		{return W_PSide02;}
		else if (Char[0][Y] > butter->h - PeopleH && Char[0][Direction] == DOWN)
		{return W_PSide02;}
	}	

	if (Char[2][Y] == Char[3][Y])
	{
		if (Char[0][Y] < PeopleH && Char[0][Direction] == UP)
		{return W_PSide03;}
		else if (Char[0][Y] > butter->h - PeopleH && Char[0][Direction] == DOWN)
		{return W_PSide03;}
	}
	if (Char[0][X] == Char[1][X])//���k
	{
		if (Char[0][X] < PeopleW && Char[0][Direction] == LEFT)
		{return W_PSide01;}
		else if (Char[0][X] > butter->w - PeopleW && Char[0][Direction] == RIGHT)
		{return W_PSide01;}
	}
	
	if (Char[1][X] == Char[2][X])
	{
		if (Char[0][X] < PeopleW && Char[0][Direction] == LEFT)
		{return W_PSide02;}
		else if (Char[0][X] > butter->w - PeopleW && Char[0][Direction] == RIGHT)
		{return W_PSide02;}
	}	

	if (Char[2][X] == Char[3][X])
	{
		if (Char[0][X] < PeopleW && Char[0][Direction] == LEFT)
		{return W_PSide03;}
		else if (Char[0][X] > butter->w - PeopleW && Char[0][Direction] == RIGHT)
		{return W_PSide03;}
	}	

	return no;
}


void people_walk_side_all (int Char[4][4], int S)
{
//�b�������~��
//��int people_walk_side (int Char[4][4], BITMAP *butter)���^�ǭ�(S)����

	int i = -1,j = -1,k = 0;
	int o = 0,p = 0,q = 0;

	if (S == 10)
	{
		if (Char[0][Y] == Char[1][Y])//�W�U
		{
			i = X;
			j = Y ;
			if (Char[0][Direction] == UP)
			{o = o + PeopleH;}
			else if (Char[0][Direction] == DOWN)
			{o = o - PeopleH;}

			if (Char[2][Direction] == DOWN)
			{q = q - PeopleH;}
			else if (Char[2][Direction] == UP)
			{q = q + PeopleH;}
		}
		if (Char[0][X] == Char[1][X])//���k
		{
			i = Y;
			j = X;
			if (Char[0][Direction] == LEFT)
			{o = o + PeopleW;}
			else if (Char[0][Direction] == RIGHT)
			{o = o - PeopleW;}

			if (Char[2][Direction] == LEFT)
			{q = q + PeopleW;}
			else if (Char[2][Direction] == RIGHT)
			{q = q - PeopleW;}
		}
	}

	else if (S == 20)
	{
		if (Char[1][Y] == Char[2][Y])//�W�U
		{
			i = X;
			j = Y;
			if (Char[0][Direction] == UP)
			{o = o + PeopleH;
			p = p + PeopleH;}
			else if (Char[0][Direction] == DOWN)
			{o = o - PeopleH;
			p = p - PeopleH;}
		}

		else if (Char[1][X] == Char[2][X])//���k
		{
			i = Y;
			j = X;
			if (Char[0][Direction] == LEFT)
			{o = o + PeopleW;
			p = p + PeopleW;}
			else if (Char[0][Direction] == RIGHT)
			{o = o - PeopleW;
			p = p - PeopleW;}
		}
	}

	else if (S == 30)
	{
		if (Char[2][Y] == Char[3][Y])//�W�U
		{
			i = X;
			j = Y;
			if (Char[0][Direction] == UP)
			{o = o + PeopleH;
			p = p + PeopleH;
			q = q + PeopleH;}
			else if (Char[0][Direction] == DOWN)
			{o = o - PeopleH;
			p = p - PeopleH;
			q = q - PeopleH;}
		}

		else if (Char[2][X] == Char[3][X])//���k
		{
			i = Y;
			j = X;
			if (Char[0][Direction] == LEFT)
			{o = o + PeopleW;
			p = p + PeopleW;
			q = q + PeopleW;}
			else if (Char[0][Direction] == RIGHT)
			{o = o - PeopleW;
			p = p - PeopleW;
			q = q - PeopleW;}
		}
	}

	Char[3][i] = Char[2][i];//i�G���k=1;�W�U=0
	Char[2][i] = Char[1][i];
	Char[1][i] = Char[0][i];

	Char[1][j] = Char[0][j] + o;//j�G���k=0;�W�U=1,k = ���ʮ��
	Char[2][j] = Char[1][j] + p;
	Char[3][j] = Char[2][j] + q;

	Char[3][Direction] = Char[2][Direction];
	Char[2][Direction] = Char[1][Direction];
	Char[1][Direction] = Char[0][Direction];
}