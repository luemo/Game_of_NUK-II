/*
 * src_Water_Pipe_Write.c
 *
 *  Created on: 2012/11/8
 *      Author: Lue
 */

#include <stdio.h>
#include "header_value_water_pipe.h"

void water_pipe_write(FILE *TEST_PIPE,int A,int PIPE[P_straight * P_straight * P_straight])
{
	int i, j = 0;

	for (i = 0;i < (A+1) * P_straight * P_straight; i++)
	{
		if (i%(P_straight * P_straight) == 0)
		{
			fprintf (TEST_PIPE,"\n²Ä%d±ø\n",j);
			j = j + 1;
		}
		if (PIPE[i] == 2){fprintf (TEST_PIPE,"¡×");}
		else if (PIPE[i] == 3){fprintf (TEST_PIPE,"¡×");}
		else if (PIPE[i] == PipeUD){fprintf (TEST_PIPE,"¢x");}
		else if (PIPE[i] == PipeRL){fprintf (TEST_PIPE,"¢w");}
		else if (PIPE[i] == PipeLU){fprintf (TEST_PIPE,"¢}");}
		else if (PIPE[i] == PipeLD){fprintf (TEST_PIPE,"¢{");}
		else if (PIPE[i] == PipeRU){fprintf (TEST_PIPE,"¢|");}
		else if (PIPE[i] == PipeRD){fprintf (TEST_PIPE,"¢z");}
		else {fprintf (TEST_PIPE,"¡C");}

		if ((i+1)%P_straight == 0 && i !=0)
		{fprintf (TEST_PIPE,"\n");}
	}
}


void water_pipe_writeOne(FILE *TEST_PIPE,int PIPE[P_straight * P_straight])
{
	int i = 0;

	for (i = 0;i < P_straight * P_straight; i++)
	{
		if (PIPE[i] == 2){fprintf (TEST_PIPE,"¡×");}
		else if (PIPE[i] == 3){fprintf (TEST_PIPE,"¡×");}
		else if (PIPE[i] == PipeUD){fprintf (TEST_PIPE,"¢x");}
		else if (PIPE[i] == PipeRL){fprintf (TEST_PIPE,"¢w");}
		else if (PIPE[i] == PipeLU){fprintf (TEST_PIPE,"¢}");}
		else if (PIPE[i] == PipeLD){fprintf (TEST_PIPE,"¢{");}
		else if (PIPE[i] == PipeRU){fprintf (TEST_PIPE,"¢|");}
		else if (PIPE[i] == PipeRD){fprintf (TEST_PIPE,"¢z");}
		else {fprintf (TEST_PIPE,"¡C");}

		if ((i+1)%P_straight == 0 && i !=0)
		{fprintf (TEST_PIPE,"\n");}
	}
}
