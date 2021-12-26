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
/*People_Walking.cpp*///<-最主要的程式，統合上面的程式
void People_Walking (int Map[2], int Char[4][4], Character role, BITMAP *BIGMAP, BITMAP *barrier, BITMAP *Sq_MAP,int KEY);//3上0下1左2右
/*******************************************************************************************************************/
/*people_walk_picture.cpp*///<-幕後貼圖的程式，連接上面People_Walking的程式
void people_walk_map (int Map[2], BITMAP *BIGMAP, BITMAP *Sq_MAP, BITMAP *butter);
void people_walk_sq (int Char[4][4], Character role, BITMAP *Sq_MAP,int n,int KEY);

/*******************************************************************************************************************/
/*Walking.cpp&TEXT.cpp*///<-測試檔案，大地圖直接使用
void TEXT ();
void Walking(int Map[2], int Char[4][4], Character role, BITMAP *BIGMAP, BITMAP *barrier,int KEY);

/*******************************************************************************************************************/
/**///<-角色貼圖直接使用
void peoplework_chang (int People[4],Character *role);
