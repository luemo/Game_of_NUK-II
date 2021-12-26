/*
 ============================================================================
 Name        : sks2012_space_v01.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "mydef.h"
#include "objdef.h"

int main(void) {

	BITMAP *image;
	PALETTE pal;
	FILE* txtFilePtr;
	int scale = SCREEN_HIGHT / SPACE_HIGHT;
	int shift_pixels_hight = (SCREEN_HIGHT - (SPACE_HIGHT * scale)) / 2;
	int shift_pixels_width = (SCREEN_WIDTH - (SPACE_WIDTH * scale)) / 2;
	int newPosX,newPosY;
	unsigned char floorData;

	unsigned char* mainArray;
	unsigned char* preVisualizeArray;

	obj* selectedObjPtr;

	obj floor;
	obj wall;
	obj room1_door;
	obj room2_door;
	obj chair;
	obj room1_table;
 	obj room2_bed;
	obj room2_charge;
	obj room3_chair;
	obj room3_desk;
	obj room3_bookcase;
	obj aisle_standby_area;
	obj parlor_start;
	obj parlor_sofa;
	obj parlor_table;
	obj parlor_tvcabinet;

	mainArray = calloc(sizeof(unsigned char),SPACE_HIGHT * SPACE_WIDTH);
	preVisualizeArray = calloc(sizeof(unsigned char),SPACE_HIGHT * SPACE_WIDTH * 4);

	txtFilePtr = fopen("mapinfo.txt","w");

	selectedObjPtr = NULL;

	floorData = '0';
	fillData_to_1D_array_UCHAR(mainArray,SPACE_HIGHT,SPACE_WIDTH,floorData);

	initObj(&floor,FLOOR,&floor,floorData);
	initObj(&wall,WALL,&floor,floorData);
	initObj(&room1_door,ROOM1_DOOR,&floor,floorData);
	initObj(&room2_door,ROOM2_DOOR,&floor,floorData);
	initObj(&chair,ROOM1_CHAIR,&floor,floorData);
	initObj(&room1_table,ROOM1_TABLE,&floor,floorData);
	initObj(&room2_bed,ROOM2_BED,&floor,floorData);
	initObj(&room2_charge,ROOM2_CHARGE,&floor,floorData);
	initObj(&room3_chair,ROOM3_CHAIR,&floor,floorData);
	initObj(&room3_desk,ROOM3_DESK,&floor,floorData);
	initObj(&room3_bookcase,ROOM3_BOOKCASE,&floor,floorData);
	initObj(&aisle_standby_area,AISLE_STANDBY_AREA,&floor,floorData);
	initObj(&parlor_start,PARLOR_START,&floor,floorData);
	initObj(&parlor_sofa,PARLOR_SOFA,&floor,floorData);
	initObj(&parlor_table,PARLOR_TABLE,&floor,floorData);
	initObj(&parlor_tvcabinet,PARLOR_TVCABINET,&floor,floorData);

//--------------------------------------------------------

	selectedObjPtr = &floor;

	allegro_init();
	set_close_button_callback(close_button_handler);
	install_keyboard();
	install_mouse();
	set_color_depth( 32 );
	set_gfx_mode( GFX_AUTODETECT_WINDOWED, SCREEN_HIGHT, SCREEN_WIDTH, 0, 0 );
	get_palette(pal);
	select_mouse_cursor(MOUSE_CURSOR_ARROW);
	enable_hardware_cursor();
//	vsync();
//	set_window_title("Allegro Window!");

//	set_palette(desktop_palette);
	image = create_bitmap(SCREEN_HIGHT, SCREEN_WIDTH);
//	clear_to_color(screen, makecol(255, 255, 255));
//	clear_to_color(image, makecol(255, 255, 255));
//	clear_bitmap( image );
	close_button_pressed = FALSE;

	while((close_button_pressed == FALSE) && (!key[KEY_ESC])){
		clear_bitmap( image );

		objs_projection(&floor,mainArray,SPACE_HIGHT,SPACE_WIDTH);
		data_covert_to_image(mainArray,SPACE_HIGHT,SPACE_WIDTH,preVisualizeArray,image,scale,shift_pixels_hight,shift_pixels_width);

		textprintf_ex( image, font, 10, 630, makecol( 255, 255, 255 ),
					 -1, "mouse_b: %d", mouse_b );
		textprintf_ex( image, font, 95, 630, makecol( 255, 255, 255 ),
					 -1, "mouse_z: %d", mouse_z );
		textprintf_ex( image, font, 220, 630, makecol( 255, 255, 255 ),
							 -1, "mouse_x: %d", mouse_x );
		textprintf_ex( image, font, 325, 630, makecol( 255, 255, 255 ),
							 -1, "mouse_y: %d", mouse_y );

		if(mouse_b == 1){
			selectedObjPtr = getSelectedObj(&floor,mouse_x,mouse_y,scale,shift_pixels_hight,shift_pixels_width);
			moveNodeToTheLast(selectedObjPtr);
			if(selectedObjPtr->fixed == FALSE){
				newPosX = ((mouse_y - shift_pixels_hight) / scale) - selectedObjPtr->hight / 2;
				newPosY = ((mouse_x - shift_pixels_width) / scale) - selectedObjPtr->width / 2;;
				if(objMovingCollisionDetector(selectedObjPtr,newPosX,newPosY) == NULL){
					selectedObjPtr->posX = newPosX;
					selectedObjPtr->posY = newPosY;
				}
			}
		}
		if((mouse_b == 4) && (selectedObjPtr != NULL) && (objRotationCollisionDetector(selectedObjPtr) == NULL)){
			ObjRotation(selectedObjPtr);
			rest(150);
		}
		if(key[KEY_F5]){
			resetAllObjPosition(&floor);
		}
		if(mouse_b == 2 || mouse_b == 3){
			resetSelectedObjPosition(selectedObjPtr);
		}

		show_mouse(image);
		blit( image, screen, 0, 0, 0, 0, image->w, image->h );

		rest(20);
		vsync();
	}

	save_bitmap("map.bmp", image, pal);
//	readkey();

	remove_mouse();
	remove_keyboard();
	destroy_bitmap( image );
	allegro_exit();

	//--------------------------------------------------------

	printf_1D_Array_AS_2D_UCHAR(txtFilePtr,mainArray,SPACE_HIGHT,SPACE_WIDTH);
	printf_1D_Array_AS_2D_UCHAR(stdout,mainArray,SPACE_HIGHT,SPACE_WIDTH);

//	printf_1D_Array_AS_2D_UCHAR(floor.data,floor.hight,floor.width);

	free(mainArray);
	free(preVisualizeArray);
	fclose(txtFilePtr);

	return EXIT_SUCCESS;

}END_OF_MAIN();

void printf_1D_Array_AS_2D_UCHAR(FILE* destPtr,unsigned char* array,int xsize,int ysize){
	int i,j;
	for(i=0;i<xsize;i++){
		for(j=0;j<ysize;j++){
			fprintf(destPtr,"%c",array[i*ysize+j]);
//			if(j != ysize - 1){
//				fprintf(destPtr,",");
//			}
		}
		fprintf(destPtr,"\n");
	}
	fflush(stdout);
}


