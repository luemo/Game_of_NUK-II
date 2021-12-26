/*
 * src_Water_Game_init.c
 *
 *  Created on: 2012/11/1
 *      Author: Lue
 */
#include <stdio.h>
#include "header_value_water_pipe.h"

void water_pipe_init(int PIPE[P_straight * P_straight])//水管初始化(全為零)
{
	int i = 0;
	for (i = 0;i < P_straight*P_straight; i++)
	{
		PIPE[i] = 0;
	}
}
void water_pipe_IO(int PIPE[P_straight * P_straight],int Input,int Output)//水管出入口初始化(入2出3)
{
	PIPE[Input] = Pipe_Start;
	PIPE[Output] = Pipe_End;
}
