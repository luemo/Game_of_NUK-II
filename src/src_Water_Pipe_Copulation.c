/*
 * src_Water_Pipe_Copulation.c
 *
 *  Created on: 2012/11/8
 *      Author: Lue
 */

#include <stdio.h>
#include <stdlib.h>
#include "header_value_water_pipe.h"
#include "header_S_value.h"
#include "header_Water_Pipe.h"

void water_pipe_Copulation(int P_all[P_straight * P_straight * P_straight],int P_new[3 * P_straight * P_straight],int now)//三條染色體交配變六條
{

	int BreakPoint1,BreakPoint2;int i,j;
	int num1,num2;

	for (j = 0; j < 3; j++)
	{
		i = rand()%6;
		if (i < 3)
		{num1 = 0;}
		else if (i < 5)
		{num1 = 1;}
		else
		{num1 = 2;}

		i = rand()%6;
		if (i < 3)
		{num2 = (num1 + 1) % 3;}
		else if (i < 5)
		{num2 = (num1 + 2) % 3;}
		else
		{num2 = num1;}

		i = rand()%6;
		if (i < 2)
		{BreakPoint1 = now + 1;}
		else if (i < 4)
		{BreakPoint1 = now + P_straight;}
		else if (i < 5)
		{BreakPoint1 = now - 1;}
		else
		{BreakPoint1 = now - P_straight;}

//		BreakPoint1 = rand()%(P_straight * P_straight);
//		BreakPoint1 = now+1;
		BreakPoint2 = BreakPoint1 + P_straight+1;
		if (BreakPoint2 >= P_straight * P_straight)
		{BreakPoint2 = P_straight * P_straight - 1;}
		if (BreakPoint1 > BreakPoint2)	//使BreakPoint1小於BreakPoint2
		{
			i = BreakPoint1;
			BreakPoint1 = BreakPoint2;
			BreakPoint2 = i;
		}
//		printf ("BreakPoint1 = %d,",BreakPoint1);
//		printf ("BreakPoint2 = %d\n",BreakPoint2);

		for (i = 0;i < P_straight * P_straight; i++)
		{
			if (i == BreakPoint1)
			{
				for (i = BreakPoint1; i <= BreakPoint2; i++)
				{
					P_new[j * P_straight * P_straight + i] = P_all[num2 * P_straight * P_straight + i];
				}
			}
			else
			{P_new[j * P_straight * P_straight + i] = P_all[num1 * P_straight * P_straight + i];}
		}
	}

	for (i = 0;i < 3 * P_straight * P_straight; i++)
	{P_all[3 * P_straight * P_straight + i] = P_new[i];}
}
