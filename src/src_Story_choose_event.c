/*
 * src_Story_choose_event.c
 *
 *  Created on: 2012/10/6
 *      Author: Lue
 */
#include <stdio.h>
#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"

PALETTE pal;

int Speak_function (int event_num);

int Story_choose (int event,int EvenMain[EvenALL])
{
	int OVER = WIN;
	if (event == EvenThingsToCS || event == EvenThingsToAPIBM || event == EvenCSToThings)
	{
//		printf ("could not find Event number:%d\n",event);
//		fflush(stdout);
	}
	else if (event == EvenLO2)
	{
		save_bitmap("image\\Speak\\11.bmp", screen, pal);
		Speak_function(event);
	}
	else if (event == EvenTCCD1)
	{
		Speak_function(event);
	}
	else if (event == EvenHANA)
	{//��i����}�Y���Ϥ�+����C��
		OVER = Flower();
		if (OVER == WIN)
		{
			Speak_function(event);
			OVER = Flower();
		}
	}
	else if (event == EvenOffice)
	{
		Speak_function(event);
	}
	else if (event == EvenDKHL)
	{//�T�i���Ϥ�+�p�C��
		OVER = Water_Pipe_Game();
		Speak_function(event);
	}
	else if (event == EvenLS1)
	{//���+�p�C��+���
		Speak_function(event);
		OVER = Water_Pipe_Game();
		EvenMain[EvenLS2] = yes;
		Speak_function(EvenLS2);
	}
	else if(event == END_OF_STORY)
	{
		 if(EvenMain[EvenIM2] == yes)
		 {//GE����
			 Speak_function (END_OF_STORY);
		 }
		 else
		 {
			 Speak_function (42);
		 }
	}

	else
	{
		Speak_function(event);
	}

	return OVER;
}
