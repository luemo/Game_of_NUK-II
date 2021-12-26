/*
 * src_Speak_function.c
 *
 *  Created on: 2012/10/6
 *      Author: Lue
 */
#include <stdio.h>
#include <allegro.h>
#include "header_S_value.h"
#include "header_System.h"
#include "header_Cfont.h"
#include "header_Speak_function.h"

int Print_Speak_to_Screen(FILE *speak_source,int background_num,int face,int line, int R,int G,int B,int x,int y);

int Change_txt(FILE *speak_source)
{
	FILE *speak_load = fopen("load.txt","w");
	char No [1000];
	if (speak_source == NULL)
	{
		printf("無法開啟檔案 !!");
	    return 0;
	}

	rewind(speak_source);
	while(!feof(speak_source))
	{
		fscanf(speak_source, "%s", No);                //一次讀取8個字元

		fprintf(speak_load, "%s", No);
		fprintf(speak_load, "\n");
	}

	fclose(speak_load);		//關閉檔案
	printf("資料寫入完畢!!");
	return EXIT_SUCCESS;
}
int Speak_function (int event_num)
{
	int i,j;
	int background_num,face,line,R,G,B,x,y;

//	printf ("SOURCE = %s\tENACTMENT = %s\t", SPEAK_TXT_SOURCE[event_num],SPEAK_TXT_ENACTMENT[event_num]);
//	fflush (stdout);

	FILE *speak_source = fopen(SPEAK_TXT_SOURCE[event_num],"r");
	FILE *speak_enactment = fopen(SPEAK_TXT_ENACTMENT[event_num],"r");

	rewind(speak_enactment);
	fscanf (speak_enactment,"%d\n", &j);

//	printf ("j = %d\n", j);
//	fflush (stdout);

	for (i = 0; i < j; i++)
	{

		fscanf (speak_enactment,"\n");
		fscanf (speak_enactment,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",&background_num,&face,&line,&R,&G,&B,&x,&y);

//		printf ("\nbackground_num %d;\tface %d;\tline %d;\tR %d;\tG %d;\tb %d;\tx %d;\ty %d\t",background_num,face,line,R,G,B,x,y);
//		fflush (stdout);
		Print_Speak_to_Screen(speak_source,background_num,face,line,R,G,B,x,y);
	}
	return 0;
}
int Print_Speak_to_Screen(FILE *speak_source,int background_num,int face,int line, int R,int G,int B,int x,int y)
{
	int i,j;
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	BITMAP *background = load_bitmap (SPEAK_BACKGROUND[background_num],NULL);
	BITMAP *speaker_face = load_bitmap (SPEAK_FACE[face],NULL);
	BITMAP *speak_box = load_bitmap ("image\\Speak\\SPEAK.bmp",NULL);
	BITMAP *speak_box_butter = create_bitmap (speak_box->w, speak_box->h);
	clear_to_color(speak_box_butter,makecol(255,0,255));

	blit (background, speak_box_butter, 0, SCREEN_H -  speak_box_butter->h, 0, 0, speak_box_butter->w, speak_box_butter->h);
	for (i = 0;i < speak_box_butter->h;i++)//對話框半透明
	{
		for (j = 0;j < speak_box_butter->w*3;j++)
		{
			speak_box_butter->line[i][j] = speak_box->line[i][j]*70/100 + speak_box_butter->line[i][j]*30/100;
		}
	}
	blit (background, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (speak_box_butter, butter, 0, 0, 0,  SCREEN_H -  speak_box_butter->h, speak_box_butter->w, speak_box_butter->h);
	masked_blit (speaker_face, butter, 0, 0, 0,  SCREEN_H -  speaker_face->h, speaker_face->w, speaker_face->h);

	print_cfont(speak_source,butter,x,y,R,G,B,line);
//int print_cfont(FILE *word_source,BITMAP *Cfont_out,int dest_x,int dest_y,int R,int G,int B,int line);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	rest(250);
	while (!key[KEY_SPACE]){}

	destroy_bitmap (butter);
	destroy_bitmap (background);
	destroy_bitmap (speaker_face);
	destroy_bitmap (speak_box);
	return 0;
}

