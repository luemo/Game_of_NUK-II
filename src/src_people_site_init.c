#include <allegro.h>
#include "header_S_value.h"
#include "header_value_walk.h"

#ifndef struct_character
	typedef struct struct_character{
	BITMAP *character1;
	BITMAP *character2;
	BITMAP *character3;
	BITMAP *character4;
}Character;
#endif

void EvenMain_init (int EvenMain[EvenALL])
{
	int i;
	for (i = 0; i < EvenALL; i++)
	{EvenMain[i] = no;}
}

int People_site_Green (int Map[2],int Char[4],int Site_X,int Site_Y,BITMAP *Not)
{
	if (Map[X]+Char[X]-SQ_SIDE/2 >= PeopleW*(Site_X-1) && Map[X]+Char[X]-SQ_SIDE/2 <= PeopleW*(Site_X+2))
	{
		if (Map[Y]+Char[Y]-SQ_SIDE/2 >= PeopleH*(Site_Y-1) && Map[Y]+Char[Y]-SQ_SIDE/2 <= PeopleH*(Site_Y+2))
		{
			if ((Char[Direction] == UP && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3] == UP*10 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+1] == 255 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+2] == UP*10) || (Char[Direction] == LEFT && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3] == LEFT*10 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+1] == 255 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+2] == LEFT*10) || (Char[Direction] == DOWN && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3] == DOWN*10 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+1] == 255 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+2] == DOWN*10) || (Char[Direction] == RIGHT && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3] == RIGHT*10 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+1] == 255 && Not->line[Map[Y]+Char[Y]-SQ_SIDE/2][(Map[X]+Char[X]-SQ_SIDE/2)*3+2] == RIGHT*10))//BGR
			{return yes;}
		}
	}
	return no;
}

void Walk_init (int Char[4][4], int M_X, int M_Y, int M_Face)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		Char[i][X] = M_X;
		Char[i][Y] = M_Y;
		Char[i][Direction] = M_Face;
		Char[i][N_Direction] = -1;
	}
}
void peoplework_chang (int People[4],Character *role)
{
	int i;
	BITMAP *Char = create_bitmap (PeopleW*3,PeopleH*4);

	for (i = 0; i < 4; i++)
	{
		switch(i)
		{
			case 0:
				if (People[i] == captain)
				{role->character1 = load_bitmap("image\\character\\captain.bmp",NULL);}
/*				if (People[i] == AC)
				{role->character1 = load_bitmap("image\\character\\AC.bmp",NULL);}
				else if (People[i] == AM)
				{role->character1 = load_bitmap("image\\character\\AM.bmp",NULL);}
				else if (People[i] == AP)
				{role->character1 = load_bitmap("image\\character\\AP.bmp",NULL);}
				else if (People[i] == APIBM)
				{role->character1 = load_bitmap("image\\character\\APIBM.bmp",NULL);}
				else if (People[i] == CEE)
				{role->character1 = load_bitmap("image\\character\\CEE.bmp",NULL);}
				else if (People[i] == CM)
				{role->character1 = load_bitmap("image\\character\\CM.bmp",NULL);}
				else if (People[i] == CS)
				{role->character1 = load_bitmap("image\\character\\CS.bmp",NULL);}
				else if (People[i] == DKHL)
				{role->character1 = load_bitmap("image\\character\\DKHL.bmp",NULL);}
				else if (People[i] == ECON)
				{role->character1 = load_bitmap("image\\character\\ECON.bmp",NULL);}
				else if (People[i] == EE)
				{role->character1 = load_bitmap("image\\character\\EE.bmp",NULL);}
				else if (People[i] == EFL)
				{role->character1 = load_bitmap("image\\character\\EFL.bmp",NULL);}
				else if (People[i] == EL)
				{role->character1 = load_bitmap("image\\character\\EL.bmp",NULL);}
				else if (People[i] == FIM)
				{role->character1 = load_bitmap("image\\character\\FIM.bmp",NULL);}
				else if (People[i] == GL)
				{role->character1 = load_bitmap("image\\character\\GL.bmp",NULL);}
				else if (People[i] == IM)
				{role->character1 = load_bitmap("image\\character\\IM.bmp",NULL);}
				else if (People[i] == LAW)
				{role->character1 = load_bitmap("image\\character\\LAW.bmp",NULL);}
				else if (People[i] == LS)
				{role->character1 = load_bitmap("image\\character\\LS.bmp",NULL);}
				else if (People[i] == TCCD)
				{role->character1 = load_bitmap("image\\character\\TCCD.bmp",NULL);}
				else if (People[i] == WL)
				{role->character1 = load_bitmap("image\\character\\WL.bmp",NULL);}
				else if (People[i] == NoOne)
				{role->character1 = load_bitmap("image\\character\\NoOne.bmp",NULL);}*/
				break;
			case 1:
				if (People[i] == AC)
				{role->character2 = load_bitmap("image\\character\\AC.bmp",NULL);}
				else if (People[i] == AM)
				{role->character2 = load_bitmap("image\\character\\AM.bmp",NULL);}
				else if (People[i] == AP)
				{role->character2 = load_bitmap("image\\character\\AP.bmp",NULL);}
				else if (People[i] == APIBM)
				{role->character2 = load_bitmap("image\\character\\APIBM.bmp",NULL);}
				else if (People[i] == CEE)
				{role->character2 = load_bitmap("image\\character\\CEE.bmp",NULL);}
				else if (People[i] == CM)
				{role->character2 = load_bitmap("image\\character\\CM.bmp",NULL);}
				else if (People[i] == CS)
				{role->character2 = load_bitmap("image\\character\\CS.bmp",NULL);}
				else if (People[i] == DKHL)
				{role->character2 = load_bitmap("image\\character\\DKHL.bmp",NULL);}
				else if (People[i] == ECON)
				{role->character2 = load_bitmap("image\\character\\ECON.bmp",NULL);}
				else if (People[i] == EE)
				{role->character2 = load_bitmap("image\\character\\EE.bmp",NULL);}
				else if (People[i] == EFL)
				{role->character2 = load_bitmap("image\\character\\EFL.bmp",NULL);}
				else if (People[i] == EL)
				{role->character2 = load_bitmap("image\\character\\EL.bmp",NULL);}
				else if (People[i] == FIM)
				{role->character2 = load_bitmap("image\\character\\FIM.bmp",NULL);}
				else if (People[i] == GL)
				{role->character2 = load_bitmap("image\\character\\GL.bmp",NULL);}
				else if (People[i] == IM)
				{role->character2 = load_bitmap("image\\character\\IM.bmp",NULL);}
				else if (People[i] == LAW)
				{role->character2 = load_bitmap("image\\character\\LAW.bmp",NULL);}
				else if (People[i] == LS)
				{role->character2 = load_bitmap("image\\character\\LS.bmp",NULL);}
				else if (People[i] == TCCD)
				{role->character2 = load_bitmap("image\\character\\TCCD.bmp",NULL);}
				else if (People[i] == WL)
				{role->character2 = load_bitmap("image\\character\\WL.bmp",NULL);}
				else if (People[i] == NoOne)
				{role->character2 = load_bitmap("image\\character\\NoOne.bmp",NULL);}
				break;
			case 2:
				if (People[i] == AC)
				{role->character3 = load_bitmap("image\\character\\AC.bmp",NULL);}
				else if (People[i] == AM)
				{role->character3 = load_bitmap("image\\character\\AM.bmp",NULL);}
				else if (People[i] == AP)
				{role->character3 = load_bitmap("image\\character\\AP.bmp",NULL);}
				else if (People[i] == APIBM)
				{role->character3 = load_bitmap("image\\character\\APIBM.bmp",NULL);}
				else if (People[i] == CEE)
				{role->character3 = load_bitmap("image\\character\\CEE.bmp",NULL);}
				else if (People[i] == CM)
				{role->character3 = load_bitmap("image\\character\\CM.bmp",NULL);}
				else if (People[i] == CS)
				{role->character3 = load_bitmap("image\\character\\CS.bmp",NULL);}
				else if (People[i] == DKHL)
				{role->character3 = load_bitmap("image\\character\\DKHL.bmp",NULL);}
				else if (People[i] == ECON)
				{role->character3 = load_bitmap("image\\character\\ECON.bmp",NULL);}
				else if (People[i] == EE)
				{role->character3 = load_bitmap("image\\character\\EE.bmp",NULL);}
				else if (People[i] == EFL)
				{role->character3 = load_bitmap("image\\character\\EFL.bmp",NULL);}
				else if (People[i] == EL)
				{role->character3 = load_bitmap("image\\character\\EL.bmp",NULL);}
				else if (People[i] == FIM)
				{role->character3 = load_bitmap("image\\character\\FIM.bmp",NULL);}
				else if (People[i] == GL)
				{role->character3 = load_bitmap("image\\character\\GL.bmp",NULL);}
				else if (People[i] == IM)
				{role->character3 = load_bitmap("image\\character\\IM.bmp",NULL);}
				else if (People[i] == LAW)
				{role->character3 = load_bitmap("image\\character\\LAW.bmp",NULL);}
				else if (People[i] == LS)
				{role->character3 = load_bitmap("image\\character\\LS.bmp",NULL);}
				else if (People[i] == TCCD)
				{role->character3 = load_bitmap("image\\character\\TCCD.bmp",NULL);}
				else if (People[i] == WL)
				{role->character3 = load_bitmap("image\\character\\WL.bmp",NULL);}
				else if (People[i] == NoOne)
				{role->character3 = load_bitmap("image\\character\\NoOne.bmp",NULL);}
				break;
			case 3:
//			Char = load_bitmap("image\\character\\AC.bmp",NULL);
//			blit (Char,role->character4, 0, 0, 0, 0, PeopleW*3, PeopleH*4);
				if (People[i] == AC)
				{role->character4 = load_bitmap("image\\character\\AC.bmp",NULL);}
				else if (People[i] == AM)
				{role->character4 = load_bitmap("image\\character\\AM.bmp",NULL);}
				else if (People[i] == AP)
				{role->character4 = load_bitmap("image\\character\\AP.bmp",NULL);}
				else if (People[i] == APIBM)
				{role->character4 = load_bitmap("image\\character\\APIBM.bmp",NULL);}
				else if (People[i] == CEE)
				{role->character4 = load_bitmap("image\\character\\CEE.bmp",NULL);}
				else if (People[i] == CM)
				{role->character4 = load_bitmap("image\\character\\CM.bmp",NULL);}
				else if (People[i] == CS)
				{role->character4 = load_bitmap("image\\character\\CS.bmp",NULL);}
				else if (People[i] == DKHL)
				{role->character4 = load_bitmap("image\\character\\DKHL.bmp",NULL);}
				else if (People[i] == ECON)
				{role->character4 = load_bitmap("image\\character\\ECON.bmp",NULL);}
				else if (People[i] == EE)
				{role->character4 = load_bitmap("image\\character\\EE.bmp",NULL);}
				else if (People[i] == EFL)
				{role->character4 = load_bitmap("image\\character\\EFL.bmp",NULL);}
				else if (People[i] == EL)
				{role->character4 = load_bitmap("image\\character\\EL.bmp",NULL);}
				else if (People[i] == FIM)
				{role->character4 = load_bitmap("image\\character\\FIM.bmp",NULL);}
				else if (People[i] == GL)
				{role->character4 = load_bitmap("image\\character\\GL.bmp",NULL);}
				else if (People[i] == IM)
				{role->character4 = load_bitmap("image\\character\\IM.bmp",NULL);}
				else if (People[i] == LAW)
				{role->character4 = load_bitmap("image\\character\\LAW.bmp",NULL);}
				else if (People[i] == LS)
				{role->character4 = load_bitmap("image\\character\\LS.bmp",NULL);}
				else if (People[i] == TCCD)
				{role->character4 = load_bitmap("image\\character\\TCCD.bmp",NULL);}
				else if (People[i] == WL)
				{role->character4 = load_bitmap("image\\character\\WL.bmp",NULL);}
				else if (People[i] == NoOne)
				{role->character4 = load_bitmap("image\\character\\NoOne.bmp",NULL);}
				break;
		}
	}
	destroy_bitmap (Char);
//	role->character1 = load_bitmap("image\\character\\EE.bmp",NULL);
//	role->character2 = load_bitmap("image\\character\\AM.bmp",NULL);
//	role->character3 = load_bitmap("image\\character\\AC.bmp",NULL);
//	role->character4 = load_bitmap("image\\character\\LS.bmp",NULL);
}
