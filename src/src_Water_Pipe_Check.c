/*
 * src_Water_Pipe_Check.c
 *
 *  Created on: 2012/11/8
 *      Author: Lue
 */

#include <stdio.h>
#include "header_value_water_pipe.h"
#include "header_S_value.h"

int water_pipe_check_all(int n,int PIPE[P_straight * P_straight * P_straight],int *last_sate)//驗證水管是否為通路，是回傳與入口距離
{//last為上一步的來之方向，之後改為下一步的來之方向；now為本來在的位置改為現在這一步的位置，設定檢查為now = 水管結束的位置(最後連接)
	int i = -1,j;
	int last = LEFT;
	int now = n * P_straight * P_straight + P_straight;

	while (last != not)
	{
		switch(last)
		{
			case UP:
				i = now + P_straight;
				if (PIPE[i] == PipeUD)
				{last = last;}
				else if (PIPE[i] == PipeLU)
				{last = RIGHT;}
				else if (PIPE[i] == PipeRU)
				{last = LEFT;}
				else
				{last = not;}
				break;
			case DOWN:
				i = now - P_straight;
				if (PIPE[i] == PipeUD)
				{last = last;}
				else if (PIPE[i] == PipeLD)
				{last = RIGHT;}
				else if (PIPE[i] == PipeRD)
				{last = LEFT;}
				else
				{last = not;}
				break;
			case LEFT:
				i = now + 1;
				if (PIPE[i] == PipeRL)
				{last = last;}
				else if (PIPE[i] == PipeLD)
				{last = UP;}
				else if (PIPE[i] == PipeLU)
				{last = DOWN;}
				else
				{last = not;}
				break;
			case RIGHT:
				i = now - 1;
				if (PIPE[i] == PipeRL)
				{last = last;}
				else if (PIPE[i] == PipeRD)
				{last = UP;}
				else if (PIPE[i] == PipeRU)
				{last = DOWN;}
				else
				{last = not;}
				break;
			default:
//				printf ("Error!");
//				fflush (stdout);
				return -1;
		}

		now = i;
		if (PIPE[i] == Pipe_End)
		{
			last = not;
//			printf ("OVER!");
//			fflush (stdout);
			return Pipe_OVER;
		}
	}
	now = now % (P_straight * P_straight);
	*last_sate = now;
	i = (now / P_straight) - (2 / P_straight);
	j = (now % P_straight) - (2 % P_straight);
	return i+j;
}

int water_pipe_choose(int all[P_straight],int stay[3])//挑選三個，回傳挑選的第一條
{
	int j;
	for(j = 0; j < 6 ; j++)						//挑選
	{
		if (all[j] >= all[stay[0]] || stay[0] == -1)
		{
			stay[2] = stay[1];
			stay[1] = stay[0];
			stay[0] = j;
		}
		else if (all[j] >= all[stay[1]] || stay[1] == -1)
		{
			stay[2] = stay[1];
			stay[1] = j;
		}
		else if (all[j] >= all[stay[2]] || stay[2] == -1)
		{
			stay[2] = j;
		}
	}
	return stay[1];				//回傳挑選的第二條
}
