/*
 * src_Water_Pipe_Abandon.c
 *
 *  Created on: 2012/11/18
 *      Author: Lue
 */

#include <stdio.h>
#include <stdlib.h>
#include "header_value_water_pipe.h"
#include "header_S_value.h"
#include "header_Water_Pipe.h"

int water_pipe_Abandon(int P_all[P_straight * P_straight * P_straight],int last[P_straight],int dec[P_straight])//abandon捨棄(當水管接口最後到了邊界時)
{
	int i = 0;
	int j = 0;

	for ( i = 0 ; i < P_straight ; i++ )
	{
		if (last[i] < P_straight || last[i] % P_straight == 0 || last[i] % P_straight == P_straight - 1 ||last[i] > P_straight * (P_straight - 1))
		{
			dec[i] = 0;
			for ( j = i * P_straight * P_straight ; j < (i+1) * P_straight * P_straight ; j++ )
			{
				if (P_all[j] != 2 && P_all[j] != 3)
				{
					P_all[j] = rand() % 6 + 11;
				}
			}
//			printf ("\t\tAbandon = %d\n",i);
//			fflush(stdout);
		}
	}
	return 0;
}
