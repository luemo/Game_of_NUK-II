#include <allegro.h>
#include <stdio.h>
#include "header_Water_Pipe.h"
#include "header_S_value.h"
#include "header_value_water_pipe.h"

int Water_Pipe(int PIPE_Answer[P_straight * P_straight])
{
	int PIPE[3 * P_straight * P_straight];					//�T��
	int PIPE_ALL[P_straight * P_straight * P_straight];		//�Ҧ�������
	int PIPE_Last[P_straight * P_straight];					//�̫᪺�@��
	int dec[6] = {0,0,0,0,0,0};//��J�f�Z��
	int last[6] = {0,0,0,0,0,0};//�̫��m
	int stay[3] = {-1,-1,-1};//�d�U�Ӫ�
	int seat = 0;//,seat_counder = seat,seat_counder_number = 0;
	int i = 1,j = 0;
	int counder = 0;
	int OVER = no;

	FILE *TEST_PIPE = fopen("txt\\TEST_PIPE.txt","w");
	FILE *TEST_PIPE_last = fopen("txt\\TEST_PIPE_last.txt","w");

//	printf ("START\n");

	for (i = 0; i < 6 ; i++)						//���
	{
		water_pipe_PutValue(i,PIPE_ALL);
	}

	while(counder < 2000 && OVER != yes)
	{
		for (i = 0; i < 6 ; i++)
		{
			dec[i] = water_pipe_check_all(i,PIPE_ALL,&last[i]);	//���Ҥ��ެO�_���q���A�O�^�ǻP�J�f�Z��
			if (dec[i] == Pipe_OVER)
			{
				for (j = 0; j < P_straight * P_straight; j++)
				{
					PIPE_Last[j] = PIPE_ALL[i * P_straight * P_straight + j];
				}
				OVER = yes;
			}
		}
//abandon�˱�(����ޱ��f�̫��F��ɮ�)
		water_pipe_Abandon(PIPE_ALL,last,dec);
		seat = last[water_pipe_choose(dec,stay)];//�D��T�ӡA�^�ǬD�諸�ĤG���Aseat���̾a��X�f�����Ӧ�m
		water_pipe_PutValueToAll(stay,PIPE_ALL,PIPE);//�d�U�n���T��

		water_pipe_Copulation(PIPE_ALL,PIPE,seat);//�T���V�����t�ܤ���

//����
		water_pipe_Mutation(PIPE_ALL,seat);


//�~�P
		if (counder % 50 == 0)
		{
//			printf ("�~�P = %d\n",counder);
			for (i = 1; i < 6 ; i++)						//���
			{water_pipe_PutValue(i,PIPE_ALL);}
		}
//		printf ("counder = %d\n",counder);
//		fflush(stdout);
		counder = counder + 1;
	}
	fprintf (TEST_PIPE_last,"�N�� = %d\n",counder-1);
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
