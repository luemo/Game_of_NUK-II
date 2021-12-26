#include <allegro.h>
#include <stdio.h>


typedef struct struct_character{
	BITMAP *character1;
	BITMAP *character2;
	BITMAP *character3;
	BITMAP *character4;
}Character;

#include "header_System.h"
#include "header_S_value.h"
int Speak_function (int event_num);

int main()
{

	Init();

	int OVER = -1;
//	OVER = Water_Pipe_Game();

	while (OVER != no)
	{
		OVER = Main_Menu ();
	}

	Exit();

	return 0;
}
END_OF_MAIN();

