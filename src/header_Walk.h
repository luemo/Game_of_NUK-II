#include "header_value_walk.h"

#ifndef Character
	typedef struct struct_character{
		BITMAP *character1;
		BITMAP *character2;
		BITMAP *character3;
		BITMAP *character4;
	}Character;
#endif

/*people_walk_movie in sq.cpp*/
int people_walk_face (int Char[4][4]);
void people_walk_first (int Char[4], BITMAP *butter);
void people_walk_other (int Char_aft[4], int Char_bef[4]);
int people_walk_red (int Char[4], BITMAP *barrier);
/*******************************************************************************************************************/
/*people_walk_side.cpp*/
int people_walk_side (int Char[4][4], BITMAP *butter);
void people_walk_side_all (int Char[4][4], int S);
/*******************************************************************************************************************/
/*people_walk_sq.cpp*/
void people_walk_sq_red (int Map[2], int Char[4], BITMAP *barrier, BITMAP *butter_red);
void people_walk_sq_movie (int Map[2], int Char[4], BITMAP *BIGMAP);
/*******************************************************************************************************************/
/*People_Walking.cpp*///<-�̥D�n���{���A�ΦX�W�����{��
void People_Walking (int Map[2], int Char[4][4], Character role, BITMAP *BIGMAP, BITMAP *barrier, BITMAP *Sq_MAP,int KEY);//3�W0�U1��2�k
/*******************************************************************************************************************/
/*people_walk_picture.cpp*///<-����K�Ϫ��{���A�s���W��People_Walking���{��
void people_walk_map (int Map[2], BITMAP *BIGMAP, BITMAP *Sq_MAP, BITMAP *butter);
void people_walk_sq (int Char[4][4], Character role, BITMAP *Sq_MAP,int n,int KEY);

/*******************************************************************************************************************/
/*Walking.cpp&TEXT.cpp*///<-�����ɮסA�j�a�Ϫ����ϥ�
void TEXT ();
void Walking(int Map[2], int Char[4][4], Character role, BITMAP *BIGMAP, BITMAP *barrier,int KEY);

/*******************************************************************************************************************/
/**///<-����K�Ϫ����ϥ�
void peoplework_chang (int People[4],Character *role);
