/*
 * src_load_save.c
 *
 *  Created on: 2012/12/13
 *      Author: Lue
 */
#include <allegro.h>
#include <stdio.h>
#include "header_System.h"
#include "header_S_value.h"

int Load_Save_Num ();

void Load_Save (int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{

	int i = not;
	char load_str[100];
	i = Load_Save_Num();
	if (i != not)
	{
		FILE *LoadTXTFile;
		sprintf (load_str,"Save\\save\\save_%d.txt",i);

		LoadTXTFile = fopen(load_str,"r");

		fscanf (LoadTXTFile,"%d %d %d\n", map_number, &Map[X], &Map[Y]);

		for (i = 0; i < 4; i++)
		{
			fscanf (LoadTXTFile,"%d %d %d %d\n", &Char[i][X], &Char[i][Y], &Char[i][Direction], &Char[i][N_Direction]);
		}

		fscanf (LoadTXTFile,"%d %d %d %d\n", &people[0], &people[1], &people[2], &people[3]);

		for (i = 0; i < EvenALL; i++)
		{
			fscanf (LoadTXTFile,"%d ", &EvenMain[i]);
		}

		fscanf (LoadTXTFile,"\n");
		fclose (LoadTXTFile);
	}

}
int Load_Save_Num ()//沒有按鍵回傳-1
{
	if (key[KEY_0])
	{
		return 0;
	}	//end of key[0]
	if (key[KEY_1])
	{
		return 1;
	}	//end of key[KEY_1]

	if (key[KEY_2])
	{
		return 2;
	}	//end of key[KEY_2]

	if (key[KEY_3])
	{
		return 3;
	}	//end of key[KEY_3]

	if (key[KEY_4])
	{
		return 4;
	}	//end of key[KEY_4]

	if (key[KEY_5])
	{
		return 5;
	}	//end of key[5]
	if (key[KEY_6])
	{
		return 6;
	}	//end of key[6]
	if (key[KEY_7])
	{
		return 7;
	}	//end of key[7]
	if (key[KEY_8])
	{
		return 8;
	}	//end of key[8]
	if (key[KEY_9])
	{
		return 9;
	}	//end of key[9]
	return not;
}
