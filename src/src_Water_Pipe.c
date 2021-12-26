#include <allegro.h>
#include <stdio.h>
#include "header_Water_Pipe.h"
#include "header_S_value.h"
#include "header_value_water_pipe.h"

int Water_Pipe(int PIPE_Answer[P_straight * P_straight])
{
	int PIPE[3 * P_straight * P_straight];					//三條
	int PIPE_ALL[P_straight * P_straight * P_straight];		//所有的六條
	int PIPE_Last[P_straight * P_straight];					//最後的一條
	int dec[6] = {0,0,0,0,0,0};//到入口距離
	int last[6] = {0,0,0,0,0,0};//最後位置
	int stay[3] = {-1,-1,-1};//留下來的
	int seat = 0;//,seat_counder = seat,seat_counder_number = 0;
	int i = 1,j = 0;
	int counder = 0;
	int OVER = no;

	FILE *TEST_PIPE = fopen("txt\\TEST_PIPE.txt","w");
	FILE *TEST_PIPE_last = fopen("txt\\TEST_PIPE_last.txt","w");

//	printf ("START\n");

	for (i = 0; i < 6 ; i++)						//填值
	{
		water_pipe_PutValue(i,PIPE_ALL);
	}

	while(counder < 2000 && OVER != yes)
	{
		for (i = 0; i < 6 ; i++)
		{
			dec[i] = water_pipe_check_all(i,PIPE_ALL,&last[i]);	//驗證水管是否為通路，是回傳與入口距離
			if (dec[i] == Pipe_OVER)
			{
				for (j = 0; j < P_straight * P_straight; j++)
				{
					PIPE_Last[j] = PIPE_ALL[i * P_straight * P_straight + j];
				}
				OVER = yes;
			}
		}
//abandon捨棄(當水管接口最後到了邊界時)
		water_pipe_Abandon(PIPE_ALL,last,dec);
		seat = last[water_pipe_choose(dec,stay)];//挑選三個，回傳挑選的第二條，seat為最靠近出口的那個位置
		water_pipe_PutValueToAll(stay,PIPE_ALL,PIPE);//留下好的三條

		water_pipe_Copulation(PIPE_ALL,PIPE,seat);//三條染色體交配變六條

//突變
		water_pipe_Mutation(PIPE_ALL,seat);


//洗牌
		if (counder % 50 == 0)
		{
//			printf ("洗牌 = %d\n",counder);
			for (i = 1; i < 6 ; i++)						//填值
			{water_pipe_PutValue(i,PIPE_ALL);}
		}
//		printf ("counder = %d\n",counder);
//		fflush(stdout);
		counder = counder + 1;
	}
	fprintf (TEST_PIPE_last,"代數 = %d\n",counder-1);
	water_pipe_write(TEST_PIPE,5,PIPE_ALL);
	water_pipe_writeOne(TEST_PIPE_last,PIPE_Last);

	fclose (TEST_PIPE);
	fclose (TEST_PIPE_last);
//	printf ("OVER");
	for (i = 0; i < P_straight * P_straight; i++)
	{
		PIPE_Answer[i] = PIPE_ALL[i];
	}
	OVER = yes;

	return 0;
}
