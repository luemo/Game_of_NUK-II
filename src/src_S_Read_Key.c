#include <allegro.h>
#include "header_S_value.h"

int Read_Key ()//3�W0�U1��2�k//����V�� - �M�w��V - �S������^��-1
{
	rest(10);

	if (key[KEY_UP])
	{
		return UP;
	}	//end of key[KEY_UP]

	if (key[KEY_DOWN])
	{
		return DOWN;
	}	//end of key[KEY_DOWN]

	if (key[KEY_LEFT])
	{
		return LEFT;
	}	//end of key[KEY_LEFT]

	if (key[KEY_RIGHT])
	{
		return RIGHT;
	}	//end of key[KEY_RIGHT]

	if (key[KEY_SPACE])
	{
		return SPACE;
	}	//end of key[SPACE]
	if (key[KEY_TAB])
	{
		return TAB;
	}	//end of key[TAB]
		return not;
}
