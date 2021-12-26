#include <allegro.h>
#include <time.h>
#include "header_S_value.h"

void Time_Delay (float time)		//停頓多少時間
{
	float T1 = 0,T2 = 0;            //時間計算 
	T1=clock();
	while (time != (T2-T1)/CLK_TCK)
	{T2=clock();}
}


int Time_After (float *T1, float T2)	//過了多少時間做動作(已過時間,預定要等的時間)
{
	float T3 = 0;
	float T4 = 0;
	if (*T1 == 0)
	{*T1=clock();}
	else
	{T3=clock();}
	T4 = T2 - (T3-*T1)/CLK_TCK;
	if (T4 < 0.1)
	{*T1 = 0;
	return yes;}
	return no;
}