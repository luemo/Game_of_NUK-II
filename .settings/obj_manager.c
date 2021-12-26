#include "mydef.h"
#include "objdef.h"

int objs_projection(obj* objPtr,unsigned char* mainArray,int xsize,int ysize){
	int i,j,k;
	int startHight,endHight,startWidth,endWidth;

	i=0;
	if(objPtr->subObjQuantity != 0){

		for(i=0;i<objPtr->subObjQuantity * 4;i+=4){

			startHight = objPtr->posX + objPtr->subObjs[i];
			endHight = startHight + objPtr->subObjs[i + 2];
			startWidth = objPtr->posY + objPtr->subObjs[i + 1];
			endWidth = startWidth + objPtr->subObjs[i + 3];

//			printf("%d,%d,%d,%d\n",startHight,endHight,startWidth,endWidth);

			for(j=startHight;j<endHight;j++){
				for(k=startWidth;k<endWidth;k++){
					mainArray[j * xsize + k] = objPtr->surfaceData;
				}
			}

		}

	}else{

		for(i=0;i<objPtr->hight;i++){
			for(j=0;j<objPtr->width;j++){
//				if(objPtr->data[i*objPtr->width+j] != objPtr->floorData){
					mainArray[(i+objPtr->posX)*xsize+(j+objPtr->posY)] = objPtr->data[i*objPtr->width+j];
//				}else{
//					mainArray[(i+objPtr->posX)*xsize+(j+objPtr->posY)] = objPtr->floorData;
//				}
			}
		}

	}

//	printf("%d\n",object->layer);

	if(objPtr->nextNode != NULL){
		objs_projection(objPtr->nextNode,mainArray,xsize,ysize);
	}

	return 0;
}

void initObj(obj* newObject,int type,obj* ExistingObj,unsigned char floorData){
//	unsigned char floorData = '0';
	obj* existingLastObj;
	newObject->nextNode = NULL;

	existingLastObj = getLastObjNodePtr(ExistingObj);
	newObject->priorNode = existingLastObj;
	existingLastObj->nextNode = newObject;

	switch (type){

		//FLOOR
		case 0 :
			newObject->fixed = TRUE;
			newObject->posX = 0;
			newObject->posY = 0;
			newObject->hight = 121;
			newObject->width = 121;
			newObject->type = 0;
			newObject->subObjQuantity = 0;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = floorData;
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->floorData);
			//for 1st obj
			newObject->id = -1;
			newObject->layer = -1;
			newObject->priorNode = NULL;
			newObject->nextNode = NULL;
			break;

		//WALL
		case 1 :
			newObject->fixed = TRUE;
			newObject->posX = 0;
			newObject->posY = 0;
			newObject->hight = 121;
			newObject->width = 121;
			newObject->type = 1;
			newObject->subObjQuantity = 10;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = '1';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_Wall_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->floorData,newObject->surfaceData);
			Set_Data_to_Wall_UCHAR(newObject);
			break;

		//ROOM1_CHAIR
		case 2 :
			newObject->fixed = FALSE;
			newObject->posX = 23;
			newObject->posY = 12;
			newObject->hight = 9;
			newObject->width = 9;
			newObject->type = 2;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'A';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//ROOM1_TABLE
		case 3 :
			newObject->fixed = FALSE;
			newObject->posX = 20;
			newObject->posY = 20;
			newObject->hight = 16;
			newObject->width = 32;
			newObject->type = 3;
			newObject->subObjQuantity = 4;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'B';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
			set_Data_to_ROOM1_TABLE_UCHAR(newObject);
			break;

		//ROOM1_DOOR
		case 4 :
			newObject->fixed = TRUE;
			newObject->posX = 45;
			newObject->posY = 50;
			newObject->hight = 17;
			newObject->width = 10;
			newObject->type = 4;
			newObject->subObjQuantity = 0;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'C';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
			fillData_to_ROOM1_DOOR_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->floorData,newObject->surfaceData);

			break;

		//ROOM2_BED
		case 5 :
			newObject->fixed = FALSE;
			newObject->posX = 25;
			newObject->posY = 84;
			newObject->hight = 26;
			newObject->width = 36;
			newObject->type = 5;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'D';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//ROOM2_MIRROR
		case 6 :
			newObject->fixed = FALSE;
			newObject->posX = 0;
			newObject->posY = 65;
			newObject->hight = 6;
			newObject->width = 0;
			newObject->type = 6;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'E';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//ROOM2_CHARGE
		case 7 :
			newObject->fixed = FALSE;
			newObject->posX = 1;
			newObject->posY = 110;
			newObject->hight = 10;
			newObject->width = 10;
			newObject->type = 7;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'F';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//ROOM2_DOOR
		case 8 :
			newObject->fixed = TRUE;
			newObject->posX = 48;
			newObject->posY = 61;
			newObject->hight = 14;
			newObject->width = 14;
			newObject->type = 8;
			newObject->subObjQuantity = 0;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'G';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
			fillData_to_ROOM2_DOOR_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->floorData,newObject->surfaceData);
			break;

		//ROOM3_CHAIR
		case 9 :
			newObject->fixed = FALSE;
			newObject->posX = 95;
			newObject->posY = 73;
			newObject->hight = 9;
			newObject->width = 9;
			newObject->type = 9;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'G';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//ROOM3_DESK
		case 10 :
			newObject->fixed = FALSE;
			newObject->posX = 88;
			newObject->posY = 61;
			newObject->hight = 24;
			newObject->width = 12;
			newObject->type = 10;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'I';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//ROOM3_BOOKCASE
		case 11 :
			newObject->fixed = FALSE;
			newObject->posX = 112;
			newObject->posY = 85;
			newObject->hight = 8;
			newObject->width = 24;
			newObject->type = 11;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'J';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//AISLE_STANDBY_AREA
		case 12 :
			newObject->fixed = FALSE;
			newObject->posX = 62;
			newObject->posY = 110;
			newObject->hight = 10;
			newObject->width = 10;
			newObject->type = 12;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'K';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//PARLOR_START
		case 13 :
			newObject->fixed = FALSE;
			newObject->posX = 62;
			newObject->posY = 0;
			newObject->hight = 10;
			newObject->width = 10;
			newObject->type = 13;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'L';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//PARLOR_SOFA
		case 14 :
			newObject->fixed = FALSE;
			newObject->posX = 90;
			newObject->posY = 1;
			newObject->hight = 28;
			newObject->width = 16;
			newObject->type = 14;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'M';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//PARLOR_TABLE
		case 15 :
			newObject->fixed = FALSE;
			newObject->posX = 90;
			newObject->posY = 25;
			newObject->hight = 18;
			newObject->width = 12;
			newObject->type = 15;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'N';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;

		//PARLOR_TVCABINET
		case 16 :
			newObject->fixed = FALSE;
			newObject->posX = 85;
			newObject->posY = 52;
			newObject->hight = 28;
			newObject->width = 8;
			newObject->type = 16;
			newObject->subObjQuantity = 1;
			newObject->subObjs = calloc(sizeof(int),newObject->subObjQuantity * 4);
			newObject->floorData = floorData;
			newObject->surfaceData = 'P';
			newObject->data = calloc(sizeof(unsigned char),newObject->hight * newObject->width);
//			fillData_to_1D_array_UCHAR(newObject->data,newObject->hight,newObject->width,newObject->surfaceData);
			setSingleSubObjData(newObject);
			break;
	}

	newObject->id = existingLastObj->id + 1;
	newObject->layer = existingLastObj->layer + 1;

}

obj* getLastObjNodePtr(obj* objPtr){
	while(objPtr->nextNode != NULL){
		objPtr = objPtr->nextNode;
	}

	return objPtr;
}

void fillData_to_1D_array_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char filledData){
	int i;
	int size = xsize * ysize;
	for(i=0;i<size;i++){
		array[i] = filledData;
	}
}
void Set_Data_to_Wall_UCHAR(obj* objPtr){

	//WALL_UL(1,0)->(61,0)
	objPtr->subObjs[ 0] = 1;
	objPtr->subObjs[ 1] = 0;
	objPtr->subObjs[ 2] = 61;
	objPtr->subObjs[ 3] = 1;

	//WALL_U(0,0)->(0,120)
	objPtr->subObjs[ 4] = 0;
	objPtr->subObjs[ 5] = 0;
	objPtr->subObjs[ 6] = 1;
	objPtr->subObjs[ 7] = 121;

	//WALL_R(1,120)->(119,120)
	objPtr->subObjs[ 8] = 1;
	objPtr->subObjs[ 9] = 120;
	objPtr->subObjs[10] = 119;
	objPtr->subObjs[11] = 1;

	//WALL_D(120,0)->(120,120)
	objPtr->subObjs[12] = 120;
	objPtr->subObjs[13] = 0;
	objPtr->subObjs[14] = 1;
	objPtr->subObjs[15] = 121;

	//WALL_DL(72,0)->(119,0)
	objPtr->subObjs[16] = 72;
	objPtr->subObjs[17] = 0;
	objPtr->subObjs[18] = 48;
	objPtr->subObjs[19] = 1;

	//---------------------------------------------

	//WALL_ML(61,1)->(61,39)
	objPtr->subObjs[20] = 61;
	objPtr->subObjs[21] = 1;
	objPtr->subObjs[22] = 1;
	objPtr->subObjs[23] = 39;

	//WALL_MU(1,60)->(60,60)
	objPtr->subObjs[24] = 1;
	objPtr->subObjs[25] = 60;
	objPtr->subObjs[26] = 61;
	objPtr->subObjs[27] = 1;

	//WALL_MR(61,81)->(61,120)
	objPtr->subObjs[28] = 61;
	objPtr->subObjs[29] = 81;
	objPtr->subObjs[30] = 1;
	objPtr->subObjs[31] = 39;

	//WALL_DR(78,60)->(78,98)
	objPtr->subObjs[32] = 78;
	objPtr->subObjs[33] = 60;
	objPtr->subObjs[34] = 1;
	objPtr->subObjs[35] = 39;

	//WALL_MD(78,60)->(120,60)
	objPtr->subObjs[36] = 78;
	objPtr->subObjs[37] = 60;
	objPtr->subObjs[38] = 43;
	objPtr->subObjs[39] = 1;


}

void fillData_to_Wall_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData){
	int i,j;
	int size = xsize * ysize;
	for(i=0;i<size;i++){
		array[i] = floorData;
	}

	//WALL_UL(0,0)->(0,61)
	for(i=0;i<62;i++){
		for(j=0;j<1;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_U(0,0)->(120,0)
	for(i=0;i<1;i++){
		for(j=0;j<ysize;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_R(120,0)->(120,120)
	for(i=120;i<xsize;i++){
		for(j=0;j<ysize;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_D(0,120)->(120,120)
	for(i=0;i<xsize;i++){
		for(j=120;j<ysize;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_D(0,120)->(120,120)
	for(i=0;i<xsize;i++){
		for(j=120;j<ysize;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_DL(0,72)->(0,120)
	for(i=72;i<xsize;i++){
		for(j=0;j<1;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//---------------------------------------------

	//WALL_ML(0,61)->(39,61)
	for(i=61;i<62;i++){
		for(j=0;j<39;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_MU(60,0)->(60,60)
	for(i=0;i<62;i++){
		for(j=60;j<61;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_MR(81,61)->(120,61)
	for(i=61;i<62;i++){
		for(j=81;j<ysize;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_DR(60,78)->(99,78)
	for(i=78;i<79;i++){
		for(j=60;j<99;j++){
			array[i*ysize+j] = filledData;
		}
	}

	//WALL_MD(60,78)->(60,120)
	for(i=78;i<xsize;i++){
		for(j=60;j<61;j++){
			array[i*ysize+j] = filledData;
		}
	}

}

void fillData_to_ROOM1_DOOR_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData){
	int i;
	int size = xsize * ysize;
	for(i=0;i<size;i++){
		array[i] = floorData;
	}

	array[0] = filledData;
	array[1*ysize+1] = filledData;
	array[2*ysize+2] = filledData;
	array[3*ysize+2] = filledData;
	array[4*ysize+3] = filledData;
	array[5*ysize+3] = filledData;
	array[6*ysize+4] = filledData;
	array[7*ysize+4] = filledData;
	array[8*ysize+5] = filledData;
	array[9*ysize+5] = filledData;
	array[10*ysize+6] = filledData;
	array[11*ysize+6] = filledData;
	array[12*ysize+7] = filledData;
	array[13*ysize+7] = filledData;
	array[14*ysize+8] = filledData;
	array[15*ysize+8] = filledData;
	array[16*ysize+9] = filledData;

}

void fillData_to_ROOM2_DOOR_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData){
	int i;
	int size = xsize * ysize;
	for(i=0;i<size;i++){
		array[i] = floorData;
	}

	for(i=0;i<xsize;i++){
			array[(xsize-1-i)*ysize+i] = filledData;
	}

}

void set_Data_to_ROOM1_TABLE_UCHAR(obj* objPtr){
//	int l,i,j,k;
//	int H_range,W_range;
//	int size = objPtr->hight * objPtr->width;

	objPtr->subObjs[ 0] = 0;
	objPtr->subObjs[ 1] = 0;
	objPtr->subObjs[ 2] = 2;
	objPtr->subObjs[ 3] = 2;

	objPtr->subObjs[ 4] = 0;
	objPtr->subObjs[ 5] = objPtr->width - 2;
	objPtr->subObjs[ 6] = 2;
	objPtr->subObjs[ 7] = 2;

	objPtr->subObjs[ 8] = objPtr->hight - 2;
	objPtr->subObjs[ 9] = 0;
	objPtr->subObjs[10] = 2;
	objPtr->subObjs[11] = 2;

	objPtr->subObjs[12] = objPtr->hight - 2;
	objPtr->subObjs[13] = objPtr->width - 2;
	objPtr->subObjs[14] = 2;
	objPtr->subObjs[15] = 2;


/*
	for(i=0;i<size;i++){
		objPtr->data[i] = objPtr->floorData;
	}

	objPtr->subObjs[ 0] = 0 * objPtr->width + 0;
	objPtr->subObjs[ 1] = 0 * objPtr->width + 1;
	objPtr->subObjs[ 2] = 1 * objPtr->width + 0;
	objPtr->subObjs[ 3] = 1 * objPtr->width + 1;

	objPtr->subObjs[ 4] = 0 * objPtr->width + (objPtr->width - 2);
	objPtr->subObjs[ 5] = 0 * objPtr->width + (objPtr->width - 1);
	objPtr->subObjs[ 6] = 1 * objPtr->width + (objPtr->width - 2);
	objPtr->subObjs[ 7] = 1 * objPtr->width + (objPtr->width - 1);

	objPtr->subObjs[ 8] = (objPtr->hight - 2) * objPtr->width + 0;
	objPtr->subObjs[ 9] = (objPtr->hight - 2) * objPtr->width + 1;
	objPtr->subObjs[10] = (objPtr->hight - 1) * objPtr->width + 0;
	objPtr->subObjs[11] = (objPtr->hight - 1) * objPtr->width + 1;

	objPtr->subObjs[12] = (objPtr->hight - 2) * objPtr->width + (objPtr->width - 2);
	objPtr->subObjs[13] = (objPtr->hight - 2) * objPtr->width + (objPtr->width - 1);
	objPtr->subObjs[14] = (objPtr->hight - 1) * objPtr->width + (objPtr->width - 2);
	objPtr->subObjs[15] = (objPtr->hight - 1) * objPtr->width + (objPtr->width - 1);

	for(l=0;l<objPtr->subObjQuantity;l++){

		H_range = objPtr->subObjs[ 2] - objPtr->subObjs[ 0] + 1;
		W_range = objPtr->subObjs[ 0] - objPtr->subObjs[ 1] + 1;
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){

				for(k=0;k<10;k++){
					objPtr->data[objPtr->subObjs[0]] = objPtr->surfaceData;
				}

			}
		}

	}


	//Draw four corners
	array[0 * ysize + 0] = filledData;
	array[0 * ysize + 1] = filledData;
	array[1 * ysize + 0] = filledData;
	array[1 * ysize + 1] = filledData;

	array[0 * ysize + (ysize - 2)] = filledData;
	array[0 * ysize + (ysize - 1)] = filledData;
	array[1 * ysize + (ysize - 2)] = filledData;
	array[1 * ysize + (ysize - 1)] = filledData;

	array[(xsize - 2) * ysize + 0] = filledData;
	array[(xsize - 2) * ysize + 1] = filledData;
	array[(xsize - 1) * ysize + 0] = filledData;
	array[(xsize - 1) * ysize + 1] = filledData;

	array[(xsize - 2) * ysize + (ysize - 2)] = filledData;
	array[(xsize - 2) * ysize + (ysize - 1)] = filledData;
	array[(xsize - 1) * ysize + (ysize - 2)] = filledData;
	array[(xsize - 1) * ysize + (ysize - 1)] = filledData;
	*/
}

/*
void fillData_to_ROOM1_TABLE_UCHAR(unsigned char* array,int xsize,int ysize,unsigned char floorData,unsigned char filledData){
	int i;
	int size = xsize * ysize;
	for(i=0;i<size;i++){
		array[i] = floorData;
	}

	//Draw four corners
	array[0 * ysize + 0] = filledData;
	array[0 * ysize + 1] = filledData;
	array[1 * ysize + 0] = filledData;
	array[1 * ysize + 1] = filledData;

	array[0 * ysize + (ysize - 2)] = filledData;
	array[0 * ysize + (ysize - 1)] = filledData;
	array[1 * ysize + (ysize - 2)] = filledData;
	array[1 * ysize + (ysize - 1)] = filledData;

	array[(xsize - 2) * ysize + 0] = filledData;
	array[(xsize - 2) * ysize + 1] = filledData;
	array[(xsize - 1) * ysize + 0] = filledData;
	array[(xsize - 1) * ysize + 1] = filledData;

	array[(xsize - 2) * ysize + (ysize - 2)] = filledData;
	array[(xsize - 2) * ysize + (ysize - 1)] = filledData;
	array[(xsize - 1) * ysize + (ysize - 2)] = filledData;
	array[(xsize - 1) * ysize + (ysize - 1)] = filledData;
}
*/

void moveNodeToTheLast(obj* objPtr){
	obj* lastObjPtr = objPtr;

	while(lastObjPtr->nextNode != NULL){
		lastObjPtr = lastObjPtr->nextNode;
	}

	//move currently node to the last
	if(objPtr->fixed == FALSE && objPtr->nextNode != NULL){
		objPtr->priorNode->nextNode = objPtr->nextNode;
		objPtr->nextNode->priorNode = objPtr->priorNode;
		objPtr->priorNode = lastObjPtr;
		objPtr->nextNode = NULL;
		lastObjPtr->nextNode = objPtr;
	}

}
void resetSelectedObjPosition(obj* objPtr){
	switch (objPtr->type){

		//FLOOR
		case 0 :
			objPtr->posX = 0;
			objPtr->posY = 0;
			objPtr->hight = 121;
			objPtr->width = 121;
			break;

		//WALL
		case 1 :
			objPtr->posX = 0;
			objPtr->posY = 0;
			objPtr->hight = 121;
			objPtr->width = 121;
			break;

		//ROOM1_CHAIR
		case 2 :
			objPtr->posX = 23;
			objPtr->posY = 12;
			objPtr->hight = 9;
			objPtr->width = 9;
			break;

		//ROOM1_TABLE
		case 3 :
			objPtr->posX = 20;
			objPtr->posY = 20;
			objPtr->hight = 16;
			objPtr->width = 32;
			set_Data_to_ROOM1_TABLE_UCHAR(objPtr);
			break;

		//ROOM1_DOOR
		case 4 :
			objPtr->posX = 45;
			objPtr->posY = 50;
			objPtr->hight = 17;
			objPtr->width = 10;
			break;

		//ROOM2_BED
		case 5 :
			objPtr->posX = 25;
			objPtr->posY = 84;
			objPtr->hight = 26;
			objPtr->width = 36;
			break;

		//ROOM2_MIRROR
		case 6 :
			objPtr->posX = 0;
			objPtr->posY = 65;
			objPtr->hight = 6;
			objPtr->width = 0;
			break;

		//ROOM2_CHARGE
		case 7 :
			objPtr->posX = 1;
			objPtr->posY = 110;
			objPtr->hight = 10;
			objPtr->width = 10;
			break;

		//ROOM2_DOOR
		case 8 :
			objPtr->posX = 48;
			objPtr->posY = 61;
			objPtr->hight = 14;
			objPtr->width = 14;
			break;

		//ROOM3_CHAIR
		case 9 :
			objPtr->posX = 95;
			objPtr->posY = 73;
			objPtr->hight = 9;
			objPtr->width = 9;
			break;

		//ROOM3_DESK
		case 10 :
			objPtr->posX = 88;
			objPtr->posY = 61;
			objPtr->hight = 24;
			objPtr->width = 12;
			break;

		//ROOM3_BOOKCASE
		case 11 :
			objPtr->posX = 112;
			objPtr->posY = 85;
			objPtr->hight = 8;
			objPtr->width = 24;
			break;

		//AISLE_STANDBY_AREA
		case 12 :
			objPtr->posX = 62;
			objPtr->posY = 110;
			objPtr->hight = 10;
			objPtr->width = 10;
			break;

		//PARLOR_START
		case 13 :
			objPtr->posX = 62;
			objPtr->posY = 0;
			objPtr->hight = 10;
			objPtr->width = 10;
			break;

		//PARLOR_SOFA
		case 14 :
			objPtr->posX = 90;
			objPtr->posY = 1;
			objPtr->hight = 28;
			objPtr->width = 16;
			break;

		//PARLOR_TABLE
		case 15 :
			objPtr->posX = 90;
			objPtr->posY = 25;
			objPtr->hight = 18;
			objPtr->width = 12;
			break;

		//PARLOR_TVCABINET
		case 16 :
			objPtr->posX = 85;
			objPtr->posY = 52;
			objPtr->hight = 28;
			objPtr->width = 8;
			break;
	}
}

void resetAllObjPosition(obj* objPtr){

	resetSelectedObjPosition(objPtr);

	if(objPtr->nextNode != NULL){
		resetAllObjPosition(objPtr->nextNode);
	}
}

void setSingleSubObjData(obj* objPtr){
	objPtr->subObjs[0] = 0;
	objPtr->subObjs[1] = 0;
	objPtr->subObjs[2] = objPtr->hight;
	objPtr->subObjs[3] = objPtr->width;
}
