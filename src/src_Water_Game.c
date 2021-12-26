/*
 * src_Water_Game.c
 *
 *  Created on: 2012/11/1
 *      Author: Lue
 */
#include <allegro.h>
#include <stdio.h>
#include "header_Water_Pipe.h"
#include "header_S_value.h"
#include "header_value_water_pipe.h"
#include "header_System.h"

int Water_Pipe_Game ()
{
	int OVER = no,KEY = -1;
	int now_pipe = -1,now_site = 0;
	int PIPE[P_straight * P_straight];
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *butter_all = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *butter_already = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *background_all = load_bitmap("image\\WATER\\Water_background.bmp",NULL);
	BITMAP *background = load_bitmap("image\\WATER\\dump.bmp",NULL);
	BITMAP *Water_End = load_bitmap("image\\WATER\\Water_End.bmp",NULL);
	BITMAP *Water_Start = load_bitmap("image\\WATER\\Water_Start.bmp",NULL);
	BITMAP *Pic_pipe[7] = {create_bitmap (Pipe_W, Pipe_H),
		load_bitmap("image\\WATER\\Water_UD.bmp",NULL),
		load_bitmap("image\\WATER\\Water_RL.bmp",NULL),
		load_bitmap("image\\WATER\\Water_LU.bmp",NULL),
		load_bitmap("image\\WATER\\Water_LD.bmp",NULL),
		load_bitmap("image\\WATER\\Water_RU.bmp",NULL),
		load_bitmap("image\\WATER\\Water_RD.bmp",NULL)};
	clear_to_color(Pic_pipe[0],makecol(0,0,0));
	blit (background,butter_already,0,0,0,0,SCREEN_W, SCREEN_H);
	blit (Water_Start,butter_already,0,0,0,Pipe_H * 1,Pipe_W,Pipe_H);
	blit (Water_End,butter_already,0,0,Pipe_W * 5,Pipe_H * 4,Pipe_W,Pipe_H);

	water_pipe_init(PIPE);//水管初始化(全為零)
	water_pipe_IO(PIPE,P_straight,P_straight*(P_straight-1)-1);//水管出入口初始化(為2)

	while (OVER != yes)
	{
		for (now_site = 0;PIPE[now_site] != 0;now_site++)
		{
			KEY = -1;
//			printf("now_site = %d\tPIPE[now_site] = %d\n",now_site,PIPE[now_site]);
//			fflush(stdout);
		}

		now_pipe = rand()%6+1;
		if (now_pipe == 0)
		{clear_to_color(Pic_pipe[0],makecol(0,16,16));}
		else
		{blit (Pic_pipe[now_pipe],Pic_pipe[0],0,0,0,0,Pipe_W,Pipe_H);}

		while (KEY != SPACE){
			if (key[KEY_A])
			{
				Water_Pipe(PIPE);
				OVER = yes;
				break;
			}

			KEY = Read_Key ();
			rest(50);

			now_site = Move_Pipe (KEY,now_site,PIPE);

			blit (butter_already,butter,0,0,0,0,SCREEN_W, SCREEN_H);
			blit (Pic_pipe[0],butter,0,0,now_site % P_straight * Pipe_W,now_site / P_straight * Pipe_H,Pipe_W,Pipe_H);
			blit (background_all,butter_all,0,0,0,0,SCREEN_W,SCREEN_H);
			blit (butter,butter_all,0,0,SCREEN_W/2-Pipe_W*P_straight/2,SCREEN_H/2-Pipe_H*P_straight/2,P_straight * Pipe_W, P_straight * Pipe_H);
			blit (butter_all,screen,0,0,0,0,SCREEN_W,SCREEN_H);

			if (close_button_pressed == TRUE)
			{break;}
		}

		blit (Pic_pipe[0],butter_already,0,0,now_site % P_straight * Pipe_W,now_site / P_straight * Pipe_H,Pipe_W,Pipe_H);
		rest(100);
		PIPE[now_site] = now_pipe + 10;
		OVER = water_pipe_check(PIPE);//驗證水管是否為通路，是回傳yes
//		printf("OVER = %d\n",OVER);
//		fflush(stdout);
		if (close_button_pressed == TRUE)
		{break;}

	}

	destroy_bitmap (butter);
	destroy_bitmap (butter_all);
	destroy_bitmap (butter_already);
	destroy_bitmap (background);
	destroy_bitmap (background_all);
	destroy_bitmap (Water_End);
	destroy_bitmap (Water_Start);
	destroy_bitmap (Pic_pipe[0]);
	destroy_bitmap (Pic_pipe[1]);
	destroy_bitmap (Pic_pipe[2]);
	destroy_bitmap (Pic_pipe[3]);
	destroy_bitmap (Pic_pipe[4]);
	destroy_bitmap (Pic_pipe[5]);
	destroy_bitmap (Pic_pipe[6]);
	return OVER;
}

int Move_Pipe (int key,int pipe_site,int PIPE[P_straight * P_straight])
{

	if (key == UP)
	{
		pipe_site = pipe_site - P_straight;
		if (pipe_site <= 0)
		{pipe_site = pipe_site + 36;}

		while(PIPE[pipe_site] != 0)
		{
			if (pipe_site <= 5)
			{pipe_site = pipe_site + 30;}
			else
			{pipe_site = pipe_site - P_straight;}
		}
	}	//end of (key == UP)
	else if (key == DOWN)
	{
		pipe_site = pipe_site + P_straight;
		if (pipe_site >= 36)
		{pipe_site = pipe_site - 36;}
		while(PIPE[pipe_site] != 0)
		{
			if (pipe_site >= 30)
			{pipe_site = pipe_site - 30;}
			else
			{pipe_site = pipe_site + P_straight;}
		}
	}	//end of (key == DOWN)
	else if (key == LEFT)
	{
		pipe_site = pipe_site - 1;
		if (pipe_site < 0)
		{pipe_site = 0;}
		while(PIPE[pipe_site] != 0)
		{
			pipe_site = pipe_site - 1;
			if (pipe_site < 0)
			{
				pipe_site = 0;
				break;
			}
		}
	}	//end of (key == LEFT)
	else if (key == RIGHT)
	{
		pipe_site = pipe_site + 1;
		if (pipe_site > P_straight * P_straight)
		{pipe_site = P_straight * P_straight -1;}
		while(PIPE[pipe_site] != 0)
		{
			pipe_site = pipe_site + 1;
			if (pipe_site > P_straight * P_straight)
			{
				pipe_site = P_straight * P_straight -1;
				break;
			}
		}
	}	//end of (key == RIGHT)

	return pipe_site;
}

