#include <allegro.h>
#include "header_value_walk.h"
#include "header_S_value.h"

//中間方塊不移動時
//(當人物轉臉和在中間方塊的中間時與障礙物判別)

int people_walk_face (int Char[4][4])
{
//領頭人改面向回傳-1((之後不做動作(領頭人面向在這裡已經改了)((所有人位置不動
//面向不變回傳0，改變回傳1

	if (Char[0][N_Direction] == UP && Char[0][Direction] != UP)	//面向
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
//Char[4] = 起頭人物的貼點，butter = 中間方塊

	if (Char[N_Direction] == UP && Char[Direction] == UP)		//PeopleH*3
	{
		Char[Y] = Char[Y] - PeopleH;

		if (Char[Y] < PeopleH/2)//如果超過上邊界則設為最上
		{Char[Y] = PeopleH/2;}
	}	//end of key[KEY_UP]

	if (Char[N_Direction] == DOWN && Char[Direction] == DOWN)		//PeopleH*0
	{
		Char[Y] = Char[Y] + PeopleH;

		if (Char[Y] > butter->h - PeopleH/2)//如果超過下邊界則設為最下 - 人物高/2
		{Char[Y] = butter->h - PeopleH/2;}
	}	//end of key[KEY_DOWN]

	if (Char[N_Direction] == LEFT && Char[Direction] == LEFT)		//PeopleH*1
	{
		Char[X] = Char[X] - PeopleW;

		if (Char[X] < PeopleW/2)//如果超過左邊界則設為最左
		{Char[X] = PeopleW/2;}
	}	//end of key[KEY_LEFT]

	if (Char[N_Direction] == RIGHT && Char[Direction] == RIGHT)		//PeopleH*2
	{
		Char[X] = Char[X] + PeopleW;

		if (Char[X] > butter->w - PeopleW/2)//如果超過右邊界則設為最右 - 人物寬
		{Char[X] = butter->w - PeopleW/2;}
	}	//end of key[KEY_RIGHT]

}


void people_walk_other (int Char_aft[4], int Char_bef[4])
{
//Char_1[4] = 上一個人的貼點，Char[4] = 這一個人的貼點
//將前一個人的貼點複製到後面一個人

	Char_bef[X] = Char_aft[X];
	Char_bef[Y] = Char_aft[Y];
	Char_bef[Direction] = Char_aft[Direction];
}

int people_walk_red (int Char[4], BITMAP *barrier)
{//將人物座標各加一個人身高並存於新的陣列中
//依方向判別是否可以行走
//回傳值0 = 無障礙物，1 = 有障礙物
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