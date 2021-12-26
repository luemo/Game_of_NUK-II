/*
 * header_Cfont.h
 *
 *  Created on: 2012/10/20
 *      Author: Lue
 */

#ifndef HEADER_CFONT_H_
#define HEADER_CFONT_H_
int init_Cfont();
int close_Cfont();
int print_cfont(FILE *word_source,BITMAP *Cfont_out,int dest_x,int dest_y,int R,int G,int B,int line);

#endif /* HEADER_CFONT_H_ */
