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
void water_pipe_init(int PIPE[P_straight * P_straight]);//���ު�l��(�����s)
void water_pipe_IO(int PIPE[P_straight * P_straight],int Input,int Output);//���ޥX�J�f��l��(�J2�X3)
int Move_Pipe (int key,int pipe_site,int PIPE[P_straight * P_straight]);
int water_pipe_check(int PIPE[P_straight * P_straight]);//���Ҥ��ެO�_���q���A�O�^��yes

#endif /* HEADER_WATER_GAME_H_ */
