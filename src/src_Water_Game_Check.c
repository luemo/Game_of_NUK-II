/*
 * src_Water_Game_Check.c
 *
 *  Created on: 2012/11/1
 *      Author: Lue
 */

#include "header_S_value.h"
#include "header_value_water_pipe.h"
#include "header_System.h"

int water_pipe_check(int PIPE[P_straight * P_straight])//���Ҥ��ެO�_���q���A�O�^��yes
{//last���W�@�B���Ӥ���V�A����אּ�U�@�B���Ӥ���V�Fnow�����Ӧb����m�אּ�{�b�o�@�B����m�A�]�w�ˬd��now = ���޵�������m(�̫�s��)
	int i = -1;
	int OVER = no;
	int last = LEFT;
	int now = P_straight;

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
				printf ("Error!");
				fflush (stdout);
				return -1;
		}
//		if (last != not)
//		{now = i;}
		now = i;
		if (PIPE[i] == Pipe_End)
		{
			last = not;
			OVER = yes;
		}
	}
	return OVER;

}
