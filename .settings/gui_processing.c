#include "mydef.h"
#include "objdef.h"

void data_covert_to_image(unsigned char *data,int hight,int width,unsigned char *preVisualizeArray,BITMAP *image,int scale,int shift_pixels_hight,int shift_pixels_width){
	int i,j,k,l;
	int depth = 4;
//	int scale_color = scale * depth;
	int width_color = width * depth;
//	int hight_scale = hight * scale;
//	int width_color_scale = width * scale_color;
//	int shift_pixels;
	int colorB,colorG,colorR;

//	shift_pixels = image->h


	//transform to RGBA format
	for(i=0;i<hight;i++){
		for(j=0;j<width;j++){
//			greyLevel = (data[i * width + j] == '0') ? 0 : 255;

			//color processing
			if(data[i * width + j] == '0'){
				colorB = 0;
				colorG = 0;
				colorR = 0;
			}else if(data[i * width + j] == 'M'){
				colorB = 0;
				colorG = 0;
				colorR = 255;
			}else{
				colorB = 255;
				colorG = 255;
				colorR = 255;
			}

			preVisualizeArray[(i * width_color) + (j * depth) + 0] = colorB;
			preVisualizeArray[(i * width_color) + (j * depth) + 1] = colorG;
			preVisualizeArray[(i * width_color) + (j * depth) + 2] = colorR;
			preVisualizeArray[(i * width_color) + (j * depth) + 3] = 255;
		}
	}

	//Enlarge and copy to the bitmap
	for(i=0;i<hight;i++){
		for(j=0;j<width_color;j+=4){

			for(k=0;k<scale;k++){
				for(l=0;l<scale;l++){
					image->line[i * scale + k + shift_pixels_hight][j * scale + ( (l + shift_pixels_width) * depth ) + 0] = preVisualizeArray[(i * width_color) + (j) + 0];
					image->line[i * scale + k + shift_pixels_hight][j * scale + ( (l + shift_pixels_width) * depth ) + 1] = preVisualizeArray[(i * width_color) + (j) + 1];
					image->line[i * scale + k + shift_pixels_hight][j * scale + ( (l + shift_pixels_width) * depth ) + 2] = preVisualizeArray[(i * width_color) + (j) + 2];
					image->line[i * scale + k + shift_pixels_hight][j * scale + ( (l + shift_pixels_width) * depth ) + 3] = preVisualizeArray[(i * width_color) + (j) + 3];
				}
			}

		}
	}

}

//當按下視窗關閉鈕時,將close_button_pressed設為TRUE
void close_button_handler(){
   close_button_pressed = TRUE;
}
END_OF_FUNCTION(close_button_handler);

obj* getSelectedObj(obj* firstObjPtr,int mouse_x,int mouse_y,int scale,int shift_pixels_hight,int shift_pixels_width){
	obj* objPtr = firstObjPtr;
	obj* lastObjPtr;

	while(objPtr->nextNode != NULL){
		objPtr = objPtr->nextNode;
	}
	lastObjPtr = objPtr;

//	printf("%d,%d,%d,%d\n",(objPtr->posX * scale + shift_pixels_hight),
//			((objPtr->posX + objPtr->hight) * scale + shift_pixels_hight),
//			(objPtr->posY * scale + shift_pixels_width),
//			((objPtr->posY + objPtr->width) * scale + shift_pixels_width));

	if((mouse_y > (objPtr->posX * scale + shift_pixels_hight)) &&
			(mouse_y < ((objPtr->posX + objPtr->hight) * scale + shift_pixels_hight)) &&
			(mouse_x > (objPtr->posY * scale + shift_pixels_width)) &&
			(mouse_x < ((objPtr->posY + objPtr->width) * scale + shift_pixels_width)))
	{
		return objPtr;
	}

	while(objPtr->priorNode != NULL){

		if((mouse_y > (objPtr->posX * scale + shift_pixels_hight)) &&
				(mouse_y < ((objPtr->posX + objPtr->hight) * scale + shift_pixels_hight)) &&
				(mouse_x > (objPtr->posY * scale + shift_pixels_width)) &&
				(mouse_x < ((objPtr->posY + objPtr->width) * scale + shift_pixels_width)))
		{
			return objPtr;
		}else if(objPtr->priorNode != NULL){
				objPtr = objPtr->priorNode;
		}else{
				return firstObjPtr;
		}

	}

	return firstObjPtr;

}
END_OF_FUNCTION(getSelectedObj);

obj* objMovingCollisionDetector(obj* objPtr,int newPosX,int newPosY){
	int i,j;
//	int count = 0;
	int selectedObj_StartHight,selectedObj_EndHight,selectedObj_StartWidth,selectedObj_EndWidth;
	int obj_StartHight,obj_EndHight,obj_StartWidth,obj_EndWidth;

	obj* firstObjPtr = objPtr;
	obj* lastObjPtr = objPtr;
	obj* selectedObjPtr = objPtr;

	while(firstObjPtr->priorNode != NULL){
		firstObjPtr = firstObjPtr->priorNode;
	}

	//Collision Detection for the edge
	if(((newPosX < 0) || ((newPosX + selectedObjPtr->hight) > 121) || ( newPosY < 0) || ((newPosY + selectedObjPtr->width) > 121))){
		return firstObjPtr;
	}

	while(lastObjPtr->nextNode != NULL){
		lastObjPtr = lastObjPtr->nextNode;
	}

	objPtr = lastObjPtr->priorNode;

	if(selectedObjPtr->subObjQuantity > 0){
		for(i=0;i<selectedObjPtr->subObjQuantity * 4;i+=4){
			selectedObj_StartHight = newPosX + selectedObjPtr->subObjs[i];
			selectedObj_EndHight = selectedObj_StartHight + selectedObjPtr->subObjs[i + 2];
			selectedObj_StartWidth = newPosY + selectedObjPtr->subObjs[i + 1];
			selectedObj_EndWidth = selectedObj_StartWidth + selectedObjPtr->subObjs[i + 3];
//			if(i>4)
//
//			count++;
			objPtr = lastObjPtr->priorNode;

//			printf("isWall:%d\n",objPtr->type == WALL);
//			printf("%d,%d\n%d,%d,%d,%d\n",count,i,selectedObj_StartHight,selectedObj_EndHight,selectedObj_StartWidth,selectedObj_EndWidth);fflush(stdout);
			while(objPtr->priorNode != NULL){

				for(j=0;j<objPtr->subObjQuantity * 4;j+=4){
					obj_StartHight = objPtr->posX + objPtr->subObjs[j];
					obj_EndHight = obj_StartHight + objPtr->subObjs[j + 2];
					obj_StartWidth = objPtr->posY + objPtr->subObjs[j + 1];
					obj_EndWidth = obj_StartWidth + objPtr->subObjs[j + 3];

					if(objPtr->type == WALL)printf("WALL %d, %d,%d,%d,%d\n",i,obj_StartHight,obj_EndHight,obj_StartWidth,obj_EndWidth);fflush(stdout);

					if((/*(objPtr->type != WALL) && */
							((!((selectedObj_StartHight < obj_StartHight + 1) && (selectedObj_EndHight < obj_StartHight + 1))) &&
							( !(((selectedObj_StartHight > (obj_EndHight - 1)) && ((selectedObj_StartHight + selectedObjPtr->subObjs[j + 2] / 2) > (obj_EndHight - 1))))) &&
							( !((selectedObj_StartWidth < obj_StartWidth + 1) && (selectedObj_EndWidth < obj_StartWidth + 1))) &&
							( !(((selectedObj_StartWidth > (obj_EndWidth - 1)) && ((selectedObj_StartWidth + selectedObjPtr->subObjs[j + 3] / 2) > (obj_EndWidth - 1))))))))
					{
						printf("Collided!!: %d ,%d %d %d %d|%d,%d,%d,%d,%d,%d,%d,%d\n",objPtr->type,selectedObj_StartHight,selectedObj_EndHight,selectedObj_StartWidth,selectedObj_EndWidth,
								((selectedObj_StartHight < obj_StartHight + 1)) , (selectedObj_EndHight < obj_StartHight + 1),
								 ((selectedObj_StartHight > (obj_EndHight - 1))) , ((selectedObj_StartHight + selectedObjPtr->subObjs[j + 2] / 2) > (obj_EndHight - 1)),
								 ((selectedObj_StartWidth < obj_StartWidth + 1)) , (selectedObj_EndWidth < obj_StartWidth + 1),
								 ((selectedObj_StartWidth > obj_EndWidth - 1)) , ((selectedObj_StartWidth + selectedObjPtr->subObjs[j + 3] / 2) > (obj_EndWidth - 1)));
						fflush(stdout);
						return objPtr;
					}

				}

				objPtr = objPtr->priorNode;
			}
		}
	}else{
		while(objPtr->priorNode != NULL && objPtr->type != 1){

			if(((objPtr != selectedObjPtr) &&
					((!((newPosX < objPtr->posX + 1) && ((newPosX + selectedObjPtr->hight) < objPtr->posX + 1))) &&
					( !(((newPosX > (objPtr->posX + objPtr->hight - 1)) && ((newPosX + selectedObjPtr->hight / 2) > (objPtr->posX + objPtr->hight - 1))))) &&
					( !((newPosY < objPtr->posY + 1) && ((newPosY + selectedObjPtr->width) < objPtr->posY + 1))) &&
					( !(((newPosY > (objPtr->posY + objPtr->width - 1)) && ((newPosY + selectedObjPtr->width / 2) > (objPtr->posY + objPtr->width - 1))))))))
			{
				return objPtr;
			}

			objPtr = objPtr->priorNode;
		}
	}

	return NULL;
}
END_OF_FUNCTION(objMovingCollisionDetector);

obj* objRotationCollisionDetector(obj* objPtr){
	obj* firstObjPtr = objPtr;
	obj* lastObjPtr = objPtr;
	obj* selectedObjPtr = objPtr;

	while(firstObjPtr->priorNode != NULL){
		firstObjPtr = firstObjPtr->priorNode;
	}

	//Collision Detection for the edge
	if(((selectedObjPtr->posX < 0) || ((selectedObjPtr->posX + selectedObjPtr->width) > 121) || ( selectedObjPtr->posY < 0) || ((selectedObjPtr->posY + selectedObjPtr->hight) > 121))){
		return firstObjPtr;
	}

	while(lastObjPtr->nextNode != NULL){
		lastObjPtr = lastObjPtr->nextNode;
	}

	objPtr = lastObjPtr->priorNode;

	while(objPtr->priorNode != NULL && objPtr->type != 1){

		if((objPtr != selectedObjPtr) &&
				(!((selectedObjPtr->posX < objPtr->posX + 1) && ((selectedObjPtr->posX + selectedObjPtr->width) < objPtr->posX + 1))) &&
				(!(((selectedObjPtr->posX > (objPtr->posX + objPtr->hight - 1)) && ((selectedObjPtr->posX + selectedObjPtr->width / 2) > (objPtr->posX + objPtr->hight - 1))))) &&
				(!((selectedObjPtr->posY < objPtr->posY + 1) && ((selectedObjPtr->posY + selectedObjPtr->hight) < objPtr->posY + 1))) &&
				(!(((selectedObjPtr->posY > (objPtr->posY + objPtr->width - 1)) && ((selectedObjPtr->posY + selectedObjPtr->hight / 2) > (objPtr->posY + objPtr->width - 1))))))
		{
			return objPtr;
		}

		objPtr = objPtr->priorNode;
	}

	return NULL;
}
END_OF_FUNCTION(objRotationCollisionDetector);

void ObjRotation(obj* objPtr){
	objPtr->hight ^= objPtr->width;
	objPtr->width ^= objPtr->hight;
	objPtr->hight ^= objPtr->width;

	objPtr->subObjs[2] ^= objPtr->subObjs[3];
	objPtr->subObjs[3] ^= objPtr->subObjs[2];
	objPtr->subObjs[2] ^= objPtr->subObjs[3];

	switch (objPtr->type){
		case 3:

			set_Data_to_ROOM1_TABLE_UCHAR(objPtr);

	}
}
END_OF_FUNCTION(ObjRotation);
