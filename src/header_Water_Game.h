/*
 * header_Water_Game.h
 *
 *  Created on: 2012/11/1
 *      Author: Lue
 */
#include "header_value_water_pipe.h"
#ifndef HEADER_WATER_GAME_H_
#define HEADER_WATER_GAME_H_

int Water_Pipe_Game ();
void water_pipe_init(int PIPE[P_straight * P_straight]);//水管初始化(全為零)
void water_pipe_IO(int PIPE[P_straight * P_straight],int Input,int Output);//水管出入口初始化(入2出3)
int Move_Pipe (int key,int pipe_site,int PIPE[P_straight * P_straight]);
int water_pipe_check(int PIPE[P_straight * P_straight]);//驗證水管是否為通路，是回傳yes

#endif /* HEADER_WATER_GAME_H_ */
