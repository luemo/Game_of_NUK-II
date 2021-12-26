#include <allegro.h>
#include <stdio.h>
#include "header_Walk.h"
#include "header_value_walk.h"
#include "header_S_value.h"

void People_Walking (int Map[2], int Char[4][4],Character role, BITMAP *BIGMAP, BITMAP *barrier, BITMAP *Sq_MAP,int KEY)//3上0下1左2右
{
	int Red_For_Sq = 0;
//	BITMAP *Sq_MAP = create_bitmap (SQ_SIDE, SQ_SIDE);
	BITMAP *Sq_MAP_RED = create_bitmap (SQ_SIDE + PeopleW*2, SQ_SIDE + PeopleH*2);
	clear_to_color(Sq_MAP_RED,makecol(255,0,0));
	clear_to_color(Sq_MAP,makecol(255,0,255));
//	BITMAP *buff = create_bitmap (32,32);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	people_walk_sq_red (Map, Char[0], barrier, Sq_MAP_RED);

	Char[0][N_Direction] = KEY;	//方向鍵鍵入第一個人的面向

	if (Char[0][N_Direction] == UP || Char[0][N_Direction] == DOWN || Char[0][N_Direction] == RIGHT || Char[0][N_Direction] == LEFT)
	{
		Red_For_Sq = people_walk_face (Char);
		if (Red_For_Sq != yes)	//如果沒有改面向則進入
		{
			Red_For_Sq = people_walk_red (Char[0], Sq_MAP_RED);//是否有障礙物，無則進入
			if (Red_For_Sq != yes)	//如果沒有障礙物則進入
			{
				Red_For_Sq = people_walk_side (Char, Sq_MAP);//是否在邊界
				
					if (Red_For_Sq != no)//在邊界
					{people_walk_sq_movie(Map, Char[0],BIGMAP);
					people_walk_side_all (Char, Red_For_Sq);}
					else if (Red_For_Sq == no)	//如果在中間並可以走(沒碰到障礙物)
					{							//四號到三號位置，三號到二號位置，二號到一號位置，一號走動
						people_walk_other (Char[2],Char[3]);
						people_walk_other (Char[1],Char[2]);
						people_walk_other (Char[0],Char[1]);
						people_walk_first (Char[0],Sq_MAP);
					}
			}	//end of (Red_For_Sq != 1)	//如果沒有障礙物則進入
		}	//end of (Red_For_Sq != 1)	//如果沒有改面向則進入
	}	//end of (Char[0][3] == Read_Key ()) != -1
/*以下貼圖*/
//	people_walk_sq (Char, role, Sq_MAP);

//	people_walk_map (Map, BIGMAP, Sq_MAP);
//	destroy_bitmap (Sq_MAP);
	destroy_bitmap (Sq_MAP_RED);

}
