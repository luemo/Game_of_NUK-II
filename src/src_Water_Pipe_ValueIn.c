/*
 * src_Water_Pipe_ValueIn.c
 *
 *  Created on: 2012/11/8
 *      Author: Lue
 */
#include <stdio.h>
#include <stdlib.h>
#include "header_value_water_pipe.h"
#include "header_Water_Pipe.h"


void water_pipe_PutValue(int n,int PIPE[P_straight * P_straight])//亂數填值進入染色體
{
	int i = 0;
	int j = n * P_straight * P_straight;
	for (i = 0;i < P_straight * P_straight; i++)
	{
		PIPE[j + i] = rand() % 6 + 11;
	}
	PIPE[j + P_straight] = Pipe_Start;
	PIPE[j + 4 * P_straight+5] = Pipe_End;
}
void water_pipe_PutValueToAll(int stay[3],int PIPE_old[P_straight * P_straight * P_straight],int PIPE_new[3 *P_straight * P_straight])//留下好的三條
{
	int i = 0,now = 0;
	int j = 0,A = 0;


	for (j = 0;j < 3; j++)
	{
		now = stay[j] * P_straight * P_straight;
		A = j * P_straight * P_straight;
		for (i = 0;i < P_straight * P_straight; i++)
		{
			PIPE_new[A + i] = PIPE_old[now + i];
		}
	}
	for (j = 0;j < 3 * P_straight * P_straight; j++)
	{
		PIPE_old[j] = PIPE_new[j];
	}
}
