#include <allegro.h>
#include <stdio.h>
#include "header_Walk.h"
#include "header_value_walk.h"
#include "header_S_value.h"

void People_Walking (int Map[2], int Char[4][4],Character role, BITMAP *BIGMAP, BITMAP *barrier, BITMAP *Sq_MAP,int KEY)//3�W0�U1��2�k
{
	int Red_For_Sq = 0;
//	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);
	BITMAP *Sq_MAP_RED = create_bitmap (SQ_SIDE + PeopleW*2, SQ_SIDE + PeopleH*2);
	clear_to_color(Sq_MAP_RED,makecol(255,0,0));
	clear_to_color(Sq_MAP,makecol(255,0,255));
//	BITMAP *buff = create_bitmap (32,32);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	people_walk_sq_red (Map, Char[0], barrier, Sq_MAP_RED);

	Char[0][N_Direction] = KEY;	//��V����J�Ĥ@�ӤH�����V

	if (Char[0][N_Direction] == UP || Char[0][N_Direction] == DOWN || Char[0][N_Direction] == RIGHT || Char[0][N_Direction] == LEFT)
	{
		Red_For_Sq = people_walk_face (Char);
		if (Red_For_Sq != yes)	//�p�G�S���ﭱ�V�h�i�J
		{
			Red_For_Sq = people_walk_red (Char[0], Sq_MAP_RED);//�O�_����ê���A�L�h�i�J
			if (Red_For_Sq != yes)	//�p�G�S����ê���h�i�J
			{
				Red_For_Sq = people_walk_side (Char, Sq_MAP);//�O�_�b���
				
					if (Red_For_Sq != no)//�b���
					{people_walk_sq_movie(Map, Char[0],BIGMAP);
					people_walk_side_all (Char, Red_For_Sq);}
					else if (Red_For_Sq == no)	//�p�G�b�����åi�H��(�S�I���ê��)
					{							//�|����T����m�A�T����G����m�A�G����@����m�A�@������
						people_walk_other (Char[2],Char[3]);
						people_walk_other (Char[1],Char[2]);
						people_walk_other (Char[0],Char[1]);
						people_walk_first (Char[0],Sq_MAP);
					}
			}	//end of (Red_For_Sq != 1)	//�p�G�S����ê���h�i�J
		}	//end of (Red_For_Sq != 1)	//�p�G�S���ﭱ�V�h�i�J
	}	//end of (Char[0][3] == Read_Key ()) != -1
/*�H�U�K��*/
//	people_walk_sq (Char, role, Sq_MAP);

//	people_walk_map (Map, BIGMAP, Sq_MAP);
//	destroy_bitmap (Sq_MAP);
	destroy_bitmap (Sq_MAP_RED);

}
