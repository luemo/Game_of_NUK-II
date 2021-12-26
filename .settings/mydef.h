#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#define SPACE_HIGHT 121
#define SPACE_WIDTH 121
//#define BITMAP_HIGHT 605
//#define BITMAP_WIDTH 605
#define SCREEN_HIGHT 640
#define SCREEN_WIDTH 640

typedef struct struct_obj{
	struct struct_obj* priorNode;
	int id,layer;
	int fixed;
	int posX,posY;
	int hight,width;
	int subObjQuantity;
	int *subObjs;
	unsigned char type;
	unsigned char floorData;
	unsigned char surfaceData;
	unsigned char* data;
	struct struct_obj* nextNode;
}obj;

//global variable
int close_button_pressed;

//prototype

//main.c
void printf_1D_Array_AS_2D_UCHAR(FILE* destPtr,unsigned char* array,int xsize,int ysize);

//obj_manager.c
void fillData_to_1D_array_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char filledData);
void fillData_to_Wall_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData);
void set_Data_to_ROOM1_TABLE_UCHAR(obj* objPtr);
void fillData_to_ROOM1_DOOR_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData);
void fillData_to_ROOM2_DOOR_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData);
void Set_Data_to_Wall_UCHAR(obj* objPtr);
void setSingleSubObjData(obj* objPtr);
int objs_projection(obj* object,unsigned char* mainArray,int xsize,int ysize);
obj* getLastObjNodePtr(obj* objPtr);
void initObj(obj* newObject,int type,obj* ExistingObj,unsigned char floorData);
void moveNodeToTheLast(obj* objPtr);
void resetAllObjPosition(obj* objPtr);
void resetSelectedObjPosition(obj* objPtr);

//gui_processing.c
void data_covert_to_image(unsigned char *data,int hight,int width,unsigned char *preVisualizeArray,BITMAP *image,int scale,int shift_pixels_hight,int shift_pixels_width);
void close_button_handler();
void ObjRotation(obj* objPtr);
obj* getSelectedObj(obj* objs,int mouse_x,int mouse_y,int scale,int shift_pixels_hight,int shift_pixels_width);
obj* objMovingCollisionDetector(obj* objPtr,int newPosX,int newPosY);
obj* objRotationCollisionDetector(obj* objPtr);

