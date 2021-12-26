/*
 * src_Cfont.c
 *
 *  Created on: 2012/10/20
 *      Author: Lue
 */
#include <allegro.h>
#include <stdio.h>
#include "header_Cfont.h"

#define FONT_map_sor 0
#define FONT_x 1
#define FONT_y 2
#define SCREEN_x 3
#define SCREEN_y 4

#define OK 2
#define Error 3

#define FONT_WORD_W 16
#define FONT_WORD_H 16

int load_Cfont();
int line_num_choose(FILE *word_source,int line);
int word_site_on_pic(int word_parameter[5],char now_word[2]);

BITMAP *font_map_sor[6];
BITMAP *font_buffer;
PALETTE pal;

int init_Cfont(){
//	allegro_init();
//	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,200,0,0);
	font_buffer=create_bitmap(SCREEN_W,SCREEN_H);
	clear_to_color(font_buffer,makecol(255,0,255));
	load_Cfont();
	return 0;
}

int load_Cfont(){
	font_map_sor[0]=load_bitmap("Cfont\\Cfont_A440xAAFF.bmp",NULL);
	font_map_sor[1]=load_bitmap("Cfont\\Cfont_AB40xAFFF.bmp",NULL);
	font_map_sor[2]=load_bitmap("Cfont\\Cfont_B040xB7FF.bmp",NULL);
	font_map_sor[3]=load_bitmap("Cfont\\Cfont_B840xBFFF.bmp",NULL);
	font_map_sor[4]=load_bitmap("Cfont\\Cfont_C040xC67F.bmp",NULL);
	font_map_sor[5]=load_bitmap("Cfont\\Cfont_sign_other.bmp",NULL);
	return 0;
}

int print_cfont(FILE *word_source,BITMAP *Cfont_out,int dest_x,int dest_y,int R,int G,int B,int line)
{
//	int Re,l=-1;
	int i,j;
	char now_word[2] = {0,0};
	int word_parameter[5] = {-1,-1,-1,0,0};

	if (word_source == NULL)
	{
		printf("�L�k�}���ɮ� !!");
	    return 0;
	}
	rewind(word_source);
//	Re =
	clear_to_color(font_buffer,makecol(255,0,255));
	line_num_choose(word_source,line);
	while (now_word[0] != '@' && now_word[1] != '#' && !feof(word_source))
	{
		fscanf(word_source, "%c%c", &now_word[0], &now_word[1]);				//�@��Ū��2�Ӧr��,����@�ӥ����r
//			printf("now_word[0] = %x now_word[1] = %x\n",now_word[0], now_word[1]);
		if (now_word[0] == 0xa)
		{
			now_word[0] = now_word[1];
			fscanf(word_source, "%c", &now_word[1]);					//���檺�ܡA�����@�Ӧ줸
//				printf("now_word[0] = %x now_word[1] = %x\n",now_word[0], now_word[1]);
			word_parameter[SCREEN_y] = word_parameter[SCREEN_y] + 1;	//�ù��W�K��y�y�д���
			word_parameter[SCREEN_x] = 0;								//�ù��W�K��x�y���k�s
		}
		if (now_word[0] != '@' && now_word[1] != '#' && !feof(word_source))
		{

//			l =
			word_site_on_pic(word_parameter,now_word);
//				printf("FONT_map_sor = %d\tX = %d\tY = %d\n",word_parameter[FONT_map_sor],word_parameter[FONT_x],word_parameter[FONT_y]);
//				printf("straight = %d\n",l);
			blit (font_map_sor[word_parameter[FONT_map_sor]],font_buffer, word_parameter[FONT_x]*FONT_WORD_W, word_parameter[FONT_y]*FONT_WORD_H, word_parameter[SCREEN_x]*FONT_WORD_W, word_parameter[SCREEN_y]*FONT_WORD_H, FONT_WORD_W, FONT_WORD_H);
			word_parameter[SCREEN_x] = word_parameter[SCREEN_x] + 1;
		}
//	while (!key[KEY_ESC]){}
	}
	for (i = 0; i < font_buffer->h; i++)
	{
		for (j = 0; j < font_buffer->w; j++)
		{
			if(font_buffer->line[i][j*3] == 0 && font_buffer->line[i][j*3+1] == 0 && font_buffer->line[i][j*3+2] == 0)//BGR
			{
				Cfont_out->line[dest_y+i][(dest_x+j)*3] = B;
				Cfont_out->line[dest_y+i][(dest_x+j)*3+1] = G;
				Cfont_out->line[dest_y+i][(dest_x+j)*3+2] = R;
			}
		}
	}
//	save_bitmap("dump.bmp", font_buffer, pal);
//	save_bitmap("Cfont_out.bmp", Cfont_out, pal);
	return OK;
}
int word_site_on_pic(int word_parameter[5],char now_word[2])
{
	int straight = 0;
	if (now_word[0] >= -92 && now_word[0] <= -86)							//�P�_�r�b���i�Ϥ��W��
	{
		word_parameter[FONT_map_sor] = 0;//A440xAAFF
		straight = -92;
	}
	else if (now_word[0] >= -85 && now_word[0] <= -81)
	{
		word_parameter[FONT_map_sor] = 1;//AB40xAFFF
		straight = -85;
	}
	else if (now_word[0] >= -80 && now_word[0] <= -73)
	{
		word_parameter[FONT_map_sor] = 2;//B040xB7FF
		straight = -80;
	}
	else if (now_word[0] >= -72 && now_word[0] <= -65)
	{
		word_parameter[FONT_map_sor] = 3;//B840xBFFF
		straight = -72;
	}
	else if (now_word[0] >= -64 && now_word[0] <= -58)
	{
		word_parameter[FONT_map_sor] = 4;//C040xC67F
		straight = -64;
	}
	else
	{
		word_parameter[FONT_map_sor] = 5;//sign_other
	}

	if (word_parameter[FONT_map_sor] < 5)							//�r������r�ɡA�P�_�L��Ϥ�����m
	{
		if (now_word[1] >= 0x40)							//�P�_�r�b�Ϥ��W����y�y��(�ĴX�C)
		{
			word_parameter[FONT_y] = (now_word[0] - straight)*10 + ((now_word[1] - 0x40)/0x10);
		}
		else
		{
			word_parameter[FONT_y] = (now_word[0] - straight)*10 + ((now_word[1] - (-0xA0))/0x10);
		}

		if (now_word[1] >= 0x40)							//�P�_�r�b�Ϥ��W����x�y��(�ĴX��)
		{
			word_parameter[FONT_x] = now_word[1]%0x10;
		}
		else
		{
			word_parameter[FONT_x] = 16+(now_word[1]%0x10);
			if (word_parameter[FONT_x] == 16)
			{word_parameter[FONT_x] = 0;}
		}
	}
	else
	{
		if (now_word[0] == -95)
		{
			if(now_word[1] == 0xffffffe3)						//�Ĥ@��ƲĤ���"��"
			{
				word_parameter[FONT_y] = 0;
				word_parameter[FONT_x] = 5;
			}
			else if (now_word[1] == 75)						//�ĤT��ƲĤT��"�K"
			{
				word_parameter[FONT_y] = 2;
				word_parameter[FONT_x] = 2;
			}
			else if (now_word[1] >= 64 && now_word[1] <= 98)		//�Ĥ@���"�@�A�B�C�D��F�G�H�I�a�b"
			{
				word_parameter[FONT_y] = 0;
				if (now_word[1] <= 73)
				{word_parameter[FONT_x] = now_word[1] - 64;}
				else
				{word_parameter[FONT_x] = now_word[1] - 97 + 10;}
			}
			else											//�ĤG���"�m�n�q�r�u�v���������ϡ�"
			{
				word_parameter[FONT_y] = 1;
				if (now_word[1] == 109)
				{word_parameter[FONT_x] = 0;}
				else if (now_word[1] == 110)
				{word_parameter[FONT_x] = 1;}
				else if (now_word[1] == 113)
				{word_parameter[FONT_x] = 2;}
				else if (now_word[1] == 114)
				{word_parameter[FONT_x] = 3;}
				else if (now_word[1] == 117)
				{word_parameter[FONT_x] = 4;}
				else if (now_word[1] == 118)
				{word_parameter[FONT_x] = 5;}
				else if (now_word[1] == -83)
				{word_parameter[FONT_x] = 6;}
				else if (now_word[1] == -82)
				{word_parameter[FONT_x] = 7;}
				else if (now_word[1] == -81)
				{word_parameter[FONT_x] = 8;}
				else if (now_word[1] == -78)
				{word_parameter[FONT_x] = 9;}
				else if (now_word[1] == -49)
				{word_parameter[FONT_x] = 10;}
				else if (now_word[1] == -48)
				{word_parameter[FONT_x] = 11;}
			}
		}
		else if (now_word[0] == -94)
		{
			if (now_word[1] == 72)							//�ĤT��ƲĤ@��"�H"
			{
				word_parameter[FONT_y] = 2;
				word_parameter[FONT_x] = 0;
			}
			else if (now_word[1] == 73)						//�ĤT��ƲĤG��"�I"
			{
				word_parameter[FONT_y] = 2;
				word_parameter[FONT_x] = 1;
			}
			else if (now_word[1] <= -72 && now_word[1] >= -81)	//�ĥ|��� �Ʀr"��������������������"
			{
				word_parameter[FONT_y] = 3;
				word_parameter[FONT_x] = now_word[1] - (-81);
			}
			else if (now_word[1] <= -37 && now_word[1] >= -49)	//�Ĥ���� �^��j�gA~M
			{
				word_parameter[FONT_y] = 4;
				word_parameter[FONT_x] = now_word[1] - (-49);
			}
			else if (now_word[1] <= -24 && now_word[1] >= -36)	//�Ĥ���� �^��j�gN~Z
			{
				word_parameter[FONT_y] = 5;
				word_parameter[FONT_x] = now_word[1] - (-36);
			}
			else if (now_word[1] <= -11 && now_word[1] >= -23)	//�ĤC��� �^��p�ga~m
			{
				word_parameter[FONT_y] = 6;
				word_parameter[FONT_x] = now_word[1] - (-23);
			}
			else if (now_word[1] <= -2 && now_word[1] >= -10)	//�ĤK��� �^��p�gn~v
			{
				word_parameter[FONT_y] = 7;
				word_parameter[FONT_x] = now_word[1] - (-10);
			}
//			else												//�ĤQ��ƥb���r
//			{word_parameter[FONT_y] = 9;}
		}
		else if (now_word[0] == -93)
		{
			if (now_word[1] <= 67 && now_word[1] >= 64)	//�ĤE��� �^��p�gw~z
			{
				word_parameter[FONT_y] = 8;
				word_parameter[FONT_x] = now_word[1] - (64);
			}
		}
	}
		return straight;
}
int line_num_choose(FILE *word_source,int line)
{
	int now_line = 0;
	char beginning_of_the_string = {0};
	while (!feof(word_source))
	{
		fscanf(word_source, "%c", &beginning_of_the_string);			//�@��Ū��1�Ӧr��,�P�_�O�_�O"@"
//		printf("ONE = %c\t",beginning_of_the_string);
		if (beginning_of_the_string == '@')
		{
			fscanf(word_source, "%c", &beginning_of_the_string);		//�@��Ū��1�Ӧr��,�P�_�O�_�O"#"
//			printf("TWO = %c\t",beginning_of_the_string);
			if (beginning_of_the_string == '#')
			{
				fscanf(word_source, "%c", &beginning_of_the_string);	//�@��Ū��1�Ӧr��,�P�_�O�_�O"#"
//				printf("THREE = %c\t",beginning_of_the_string);
				if (beginning_of_the_string == '#')
				{
					fscanf(word_source, "%c", &beginning_of_the_string);	//�@��Ū��1�Ӧr��,�P�_�O�_�O"["
//					printf("FOUR = %c\t",beginning_of_the_string);
					if (beginning_of_the_string == '[')
					{
						fscanf(word_source, "%d%c", &now_line, &beginning_of_the_string);				//�@��Ū��1�ӼƦr,�P�_�O�_��line
//						printf("%d %c\t", now_line,beginning_of_the_string);
						if (now_line == line)
						{
//							printf("line = %d\n",now_line);
							return OK;
						}
//						printf("now_line != %d\n",line);
					}
				}
			}
		}
		else
		{
//			fscanf(word_source, "%c%c", &beginning_of_the_string[0], &beginning_of_the_string[1]);				//�@��Ū��2�Ӧr��,�P�_�O�_�O"@#"
//			printf("\n%c %c\t",beginning_of_the_string[0], beginning_of_the_string[1]);
//			printf("%d\t",beginning_of_the_string);//[0], beginning_of_the_string[1]);
//			printf("%x\n",beginning_of_the_string);//[0], beginning_of_the_string[1]);
//			return Error;
		}
	}
	return Error;
}

int close_Cfont(){
	destroy_bitmap(font_map_sor[0]);
	destroy_bitmap(font_map_sor[1]);
	destroy_bitmap(font_map_sor[2]);
	destroy_bitmap(font_map_sor[3]);
	destroy_bitmap(font_map_sor[4]);
	destroy_bitmap(font_map_sor[5]);
	destroy_bitmap(font_buffer);
	return 0;
}

