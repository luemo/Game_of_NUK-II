#include "header_value_water_pipe.h"

int Water_Pipe(int PIPE_Answer[P_straight*P_straight]);

/////////////////////////////////////////////////��ȻP����/////////////////////////////////////////////////
void water_pipe_write(FILE *TEST_PIPE,int A,int PIPE[P_straight * P_straight * P_straight]);
void water_pipe_writeOne(FILE *TEST_PIPE,int PIPE[P_straight * P_straight]);
///////////////////////////////////////////////////��l��///////////////////////////////////////////////////
void water_pipe_PutValue(int n,int PIPE[P_straight * P_straight]);//�üƶ�ȶi�J�V����
void water_pipe_PutValueToAll(int stay[3],int PIPE_old[P_straight * P_straight * P_straight],int PIPE_new[3 *P_straight * P_straight]);//�d�U�n���T��

int water_pipe_check_all(int n,int PIPE[P_straight * P_straight],int *last_sate);//���Ҥ��ެO�_���q���A�O�^�ǻP�J�f�Z��

int water_pipe_choose(int all[P_straight],int stay[3]);//�D��T�ӡA�^�ǬD�諸�ĤG��

void water_pipe_Copulation(int P_all[P_straight * P_straight * P_straight],int P_new[3 * P_straight * P_straight],int now);//�T���V�����t�ܤ���

int water_pipe_Mutation(int P_all[P_straight * P_straight * P_straight],int now);

int water_pipe_Abandon(int P_all[P_straight * P_straight * P_straight],int last[P_straight],int dec[P_straight]);//abandon�˱�(����ޱ��f�̫��F��ɮ�)







/*
///////////////////////////////////////////////////��l��///////////////////////////////////////////////////

/////////////////////////////////////////////////��ȻP����/////////////////////////////////////////////////

void water_pipe_random(int PIPE[P_straight * P_straight]);//�üƶ�ȶi�J
void water_pipe_verification(int PIPE[P_straight * P_straight],int *last,int *now);//���Ҥ��ެO�_���q���A�_�hlast��-1
void water_pipe_CheckConnection(int PIPE[P_straight * P_straight * P_straight],int stay[3]);//���Ҥ��ެO�_���q��
int water_pipe_CheckDistance(int INPUT,int now);//�J�f��ثe���Z��
/////////////////////////////////////////////////��ȻP����/////////////////////////////////////////////////

void water_pipe_PutOneToOne (int P1[P_straight * P_straight * P_straight],int P2[P_straight * P_straight],int num,int A);//A==1�A�e���AA==2�A���e�A�e800��100
void water_pipe_PutAllToThree (int P1[P_straight * P_straight * P_straight],int P2[3 * P_straight * P_straight],int num[2]);//�D�X����V����
void water_pipe_PutThreeToAll (int P1[P_straight * P_straight * P_straight],int P2[3 * P_straight * P_straight],int A);//�T���V�����J�V���鶰����AA���q�ĴX����


*/
