/*
 * src_Water_Pipe_Check.c
 *
 *  Created on: 2012/11/8
 *      Author: Lue
 */

#include <stdio.h>
#include "header_value_water_pipe.h"
#include "header_S_value.h"

int water_pipe_check_all(int n,int PIPE[P_straight * P_straight * P_straight],int *last_sate)//���Ҥ��ެO�_���q���A�O�^�ǻP�J�f�Z��
{//last���W�@�B���Ӥ���V�A����אּ�U�@�B���Ӥ���V�Fnow�����Ӧb����m�אּ�{�b�o�@�B����m�A�]�w�ˬd��now = ���޵�������m(�̫�s��)
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

int water_pipe_choose(int all[P_straight],int stay[3])//�D��T�ӡA�^�ǬD�諸�Ĥ@��
{
	int j;
	for(j = 0; j < 6 ; j++)						//�D��
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
	return stay[1];				//�^�ǬD�諸�ĤG��
}
