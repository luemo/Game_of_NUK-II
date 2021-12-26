#include <allegro.h>
#include "header_value_walk.h"
#include "header_S_value.h"

//������������ʮ�
//(��H�����y�M�b��������������ɻP��ê���P�O)

int people_walk_face (int Char[4][4])
{
//���Y�H�ﭱ�V�^��-1((���ᤣ���ʧ@(���Y�H���V�b�o�̤w�g��F)((�Ҧ��H��m����
//���V���ܦ^��0�A���ܦ^��1

	if (Char[0][N_Direction] == UP && Char[0][Direction] != UP)	//���V
	{Char[0][Direction] = UP;
	return yes;}
	else if (Char[0][N_Direction] == DOWN && Char[0][Direction] != DOWN)
	{Char[0][Direction] = DOWN;
	return yes;}
	else if (Char[0][N_Direction] == LEFT && Char[0][Direction] != LEFT)
	{Char[0][Direction] = LEFT;
	return yes;}
	else if (Char[0][N_Direction] == RIGHT && Char[0][Direction] != RIGHT)
	{Char[0][Direction] = RIGHT;
	return yes;}

	return no;
}

void people_walk_first (int Char[4], BITMAP *butter)
{
//Char[4] = �_�Y�H�����K�I�Abutter = �������

	if (Char[N_Direction] == UP && Char[Direction] == UP)		//PeopleH*3
	{
		Char[Y] = Char[Y] - PeopleH;

		if (Char[Y] < PeopleH/2)//�p�G�W�L�W��ɫh�]���̤W
		{Char[Y] = PeopleH/2;}
	}	//end of key[KEY_UP]

	if (Char[N_Direction] == DOWN && Char[Direction] == DOWN)		//PeopleH*0
	{
		Char[Y] = Char[Y] + PeopleH;

		if (Char[Y] > butter->h - PeopleH/2)//�p�G�W�L�U��ɫh�]���̤U - �H����/2
		{Char[Y] = butter->h - PeopleH/2;}
	}	//end of key[KEY_DOWN]

	if (Char[N_Direction] == LEFT && Char[Direction] == LEFT)		//PeopleH*1
	{
		Char[X] = Char[X] - PeopleW;

		if (Char[X] < PeopleW/2)//�p�G�W�L����ɫh�]���̥�
		{Char[X] = PeopleW/2;}
	}	//end of key[KEY_LEFT]

	if (Char[N_Direction] == RIGHT && Char[Direction] == RIGHT)		//PeopleH*2
	{
		Char[X] = Char[X] + PeopleW;

		if (Char[X] > butter->w - PeopleW/2)//�p�G�W�L�k��ɫh�]���̥k - �H���e
		{Char[X] = butter->w - PeopleW/2;}
	}	//end of key[KEY_RIGHT]

}


void people_walk_other (int Char_aft[4], int Char_bef[4])
{
//Char_1[4] = �W�@�ӤH���K�I�AChar[4] = �o�@�ӤH���K�I
//�N�e�@�ӤH���K�I�ƻs��᭱�@�ӤH

	Char_bef[X] = Char_aft[X];
	Char_bef[Y] = Char_aft[Y];
	Char_bef[Direction] = Char_aft[Direction];
}

int people_walk_red (int Char[4], BITMAP *barrier)
{//�N�H���y�ЦU�[�@�ӤH�����æs��s���}�C��
//�̤�V�P�O�O�_�i�H�樫
//�^�ǭ�0 = �L��ê���A1 = ����ê��
	int Character[2];

	Character[X] = Char[X] + PeopleW;
	Character[Y] = Char[Y] + PeopleH;

	if (Char[Direction] == UP)
	{
		Character[Y] = 	Character[Y] - PeopleH;
		if (barrier->line[Character[Y]][Character[X] * 3 + 0] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 1] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 2] == 255)
		{return yes;}
	}	//end of key[KEY_UP]

	if (Char[Direction] == DOWN)
	{
		Character[Y] = Character[Y] + PeopleH;
		if (barrier->line[Character[Y]][Character[X] * 3 + 0] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 1] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 2] == 255)
		{return yes;}
	}	//end of key[KEY_DOWN]

	if (Char[Direction] == LEFT)
	{
		Character[X] = Character[X] - PeopleW;
		if (barrier->line[Character[Y]][Character[X] * 3 + 0] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 1] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 2] == 255)
		{return yes;}
	}	//end of key[KEY_LEFT]
	if (Char[Direction] == RIGHT)
	{
		Character[X] = Character[X] + PeopleW;
		if (barrier->line[Character[Y]][Character[X] * 3 + 0] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 1] == 0 && barrier->line[Character[Y]][Character[X] * 3 + 2] == 255)
		{return yes;}
	}	//end of key[KEY_RIGHT]

	return no;
}