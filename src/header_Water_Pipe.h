#include "header_value_water_pipe.h"

int Water_Pipe(int PIPE_Answer[P_straight*P_straight]);

/////////////////////////////////////////////////填值與驗證/////////////////////////////////////////////////
void water_pipe_write(FILE *TEST_PIPE,int A,int PIPE[P_straight * P_straight * P_straight]);
void water_pipe_writeOne(FILE *TEST_PIPE,int PIPE[P_straight * P_straight]);
///////////////////////////////////////////////////初始化///////////////////////////////////////////////////
void water_pipe_PutValue(int n,int PIPE[P_straight * P_straight]);//亂數填值進入染色體
void water_pipe_PutValueToAll(int stay[3],int PIPE_old[P_straight * P_straight * P_straight],int PIPE_new[3 *P_straight * P_straight]);//留下好的三條

int water_pipe_check_all(int n,int PIPE[P_straight * P_straight],int *last_sate);//驗證水管是否為通路，是回傳與入口距離

int water_pipe_choose(int all[P_straight],int stay[3]);//挑選三個，回傳挑選的第二條

void water_pipe_Copulation(int P_all[P_straight * P_straight * P_straight],int P_new[3 * P_straight * P_straight],int now);//三條染色體交配變六條

int water_pipe_Mutation(int P_all[P_straight * P_straight * P_straight],int now);

int water_pipe_Abandon(int P_all[P_straight * P_straight * P_straight],int last[P_straight],int dec[P_straight]);//abandon捨棄(當水管接口最後到了邊界時)







/*
///////////////////////////////////////////////////初始化///////////////////////////////////////////////////

/////////////////////////////////////////////////填值與驗證/////////////////////////////////////////////////

void water_pipe_random(int PIPE[P_straight * P_straight]);//亂數填值進入
void water_pipe_verification(int PIPE[P_straight * P_straight],int *last,int *now);//驗證水管是否為通路，否則last為-1
void water_pipe_CheckConnection(int PIPE[P_straight * P_straight * P_straight],int stay[3]);//驗證水管是否為通路
int water_pipe_CheckDistance(int INPUT,int now);//入口到目前的距離
/////////////////////////////////////////////////填值與驗證/////////////////////////////////////////////////

void water_pipe_PutOneToOne (int P1[P_straight * P_straight * P_straight],int P2[P_straight * P_straight],int num,int A);//A==1，前放後，A==2，後放前，前800後100
void water_pipe_PutAllToThree (int P1[P_straight * P_straight * P_straight],int P2[3 * P_straight * P_straight],int num[2]);//挑出兩條染色體
void water_pipe_PutThreeToAll (int P1[P_straight * P_straight * P_straight],int P2[3 * P_straight * P_straight],int A);//三條染色體放入染色體集中營，A為從第幾條放


*/
