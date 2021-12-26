/*
 * src_Water_Pipe_Mutation.c
 *
 *  Created on: 2012/11/18
 *      Author: Lue
 */

#include <stdio.h>
#include <stdlib.h>
#include "header_value_water_pipe.h"
#include "header_S_value.h"
#include "header_Water_Pipe.h"
int water_pipe_Mutation_Probability_Chack (int Mask[Pipe_chack]);

int water_pipe_Mutation(int P_all[P_straight * P_straight * P_straight],int now)
{
	int probability = 0;
	int i = 0,j = i;
	int PIPE_Mutation[P_straight * P_straight];				//突變機率
	int Mask[Pipe_chack];


	for (i = P_straight * P_straight;i < 2 * P_straight * P_straight; i++)		//第二條做突變
	{
		j = i - P_straight * P_straight;
//查看水管的鄰近四格是否通路
	//放入遮罩;0為上.1為左.2居中.3為右.4為下
		PIPE_Mutation[j] = 2;
		Mask[0] = P_all[j - P_straight];
		Mask[1] = P_all[j - 1];
		Mask[2] = P_all[j];
		Mask[3] = P_all[j + 1];
		Mask[4] = P_all[j + P_straight];
		if (j < P_straight)
		{Mask[0] = 0;}
		if (j % P_straight == 0)
		{Mask[1] = 0;}
		if (j % P_straight == P_straight - 1)
		{Mask[3] = 0;}
		if (j > P_straight * (P_straight - 1))
		{Mask[4] = 0;}
	//檢察
		PIPE_Mutation[j] = PIPE_Mutation[j] + water_pipe_Mutation_Probability_Chack (Mask);
	}
	PIPE_Mutation[now] = PIPE_Mutation[now] + Pipe_mutation2;
	if (now > P_straight)
	{PIPE_Mutation[now - P_straight] = PIPE_Mutation[now - P_straight] + Pipe_mutation3;}
	if (now % P_straight != 0)
	{PIPE_Mutation[now - 1] = PIPE_Mutation[now - 1] + Pipe_mutation3;}
	if (now % P_straight != P_straight - 1)
	{PIPE_Mutation[now + 1] = PIPE_Mutation[now + 1] + Pipe_mutation3;}
	if (now < P_straight * (P_straight - 1))
	{PIPE_Mutation[now + P_straight] = PIPE_Mutation[now + P_straight] + Pipe_mutation3;}

	for (i = P_straight * P_straight;i < 2 * P_straight * P_straight; i++)		//第二條做突變
	{
		if (P_all[i] != 2 && P_all[i] != 3)
		{
			probability = rand() % 10;
			if (probability < PIPE_Mutation[j])
			{P_all[i] = rand() % 6 + 11;}
		}
	}
	return 0;
}

int water_pipe_Mutation_Probability_Chack (int Mask[Pipe_chack])
{
	int probability = 0;
	if (Mask[2] == PipeUD)			//PipeUD 11 直的
	{
		if (Mask[0] == PipeUD || Mask[0] == PipeLD || Mask[0] == PipeRD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
		if (Mask[4] == PipeUD || Mask[4] == PipeLU || Mask[4] == PipeRU)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
	}
	else if (Mask[2] == PipeRL)		//PipeRL 12 橫的
	{
		if (Mask[1] == PipeRL || Mask[1] == PipeRU || Mask[0] == PipeRD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
		if (Mask[3] == PipeRL || Mask[3] == PipeLU || Mask[3] == PipeLD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
	}
	else if (Mask[2] == PipeLU)		//PipeLU 13 左上
	{
		if (Mask[0] == PipeUD || Mask[0] == PipeLD || Mask[0] == PipeRD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
		if (Mask[1] == PipeRL || Mask[1] == PipeRU || Mask[0] == PipeRD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
	}
	else if (Mask[2] == PipeLD)		//PipeLD 14 左下
	{
		if (Mask[1] == PipeRL || Mask[1] == PipeRU || Mask[0] == PipeRD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
		if (Mask[4] == PipeUD || Mask[4] == PipeLU || Mask[4] == PipeRU)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
	}
	else if (Mask[2] == PipeRU)		//PipeRU 15 右上
	{
		if (Mask[0] == PipeUD || Mask[0] == PipeLD || Mask[0] == PipeRD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
		if (Mask[3] == PipeRL || Mask[3] == PipeLU || Mask[3] == PipeLD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
	}
	else if (Mask[2] == PipeRD)		//PipeRD 16 右下
	{
		if (Mask[3] == PipeRL || Mask[3] == PipeLU || Mask[3] == PipeLD)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
		if (Mask[4] == PipeUD || Mask[4] == PipeLU || Mask[4] == PipeRU)
		{probability = probability + Pipe_mutation0;}
		else
		{probability = probability + Pipe_mutation1;}
	}

	return probability;
}
