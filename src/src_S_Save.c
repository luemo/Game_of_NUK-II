#include <allegro.h>
#include <stdio.h>
#include "header_System.h"
#include "header_S_value.h"

void Save (int map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{
	int i = 0;

	FILE *SaveTXTFile_GameData;
	SaveTXTFile_GameData = fopen("Save\\SaveQ.txt","w");

	fprintf (SaveTXTFile_GameData,"%d %d %d\n", map_number, Map[X], Map[Y]);

	for (i = 0; i < 4; i++)
	{
		fprintf (SaveTXTFile_GameData,"%d %d %d 0\n", Char[i][X], Char[i][Y], Char[i][Direction]);
	}

	fprintf (SaveTXTFile_GameData,"%d %d %d %d\n", people[0], people[1], people[2], people[3]);

	for (i = 0; i < EvenALL; i++)
	{
		fprintf (SaveTXTFile_GameData,"%d ", EvenMain[i]);
//		printf ("%d = %d;",i, EvenMain[i]);fflush(stdout);
	}

	fclose (SaveTXTFile_GameData);
}



void Load(int *map_number,int Map[2],int Char[4][4],int people[4],int EvenMain[EvenALL])
{

	int i = 0;
	FILE *LoadTXTFile_GameData;

	LoadTXTFile_GameData = fopen("Save\\SaveQ.txt","r");

	fscanf (LoadTXTFile_GameData,"%d %d %d\n", map_number, &Map[X], &Map[Y]);

	for (i = 0; i < 4; i++)
	{
		fscanf (LoadTXTFile_GameData,"%d %d %d %d\n", &Char[i][X], &Char[i][Y], &Char[i][Direction], &Char[i][N_Direction]);
	}

	fscanf (LoadTXTFile_GameData,"%d %d %d %d\n", &people[0], &people[1], &people[2], &people[3]);

	for (i = 0; i < EvenALL; i++)
	{
		fscanf (LoadTXTFile_GameData,"%d ", &EvenMain[i]);
	}

	fscanf (LoadTXTFile_GameData,"\n");

	fclose (LoadTXTFile_GameData);
}
