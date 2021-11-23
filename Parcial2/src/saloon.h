/*
 * saloon.h
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#ifndef SALOON_H_
#define SALOON_H_

#include "lList.h"

struct Saloon
{
	char name[51];
	LinkedList* pFirstArcade;
};

typedef struct Saloon Saloon;

Saloon* saloon_new();
int saloon_setName(Saloon* this,char* nombre);
int saloon_getName(Saloon* this,char* nombre);

int initSaloon(Saloon*, int);

int addSaloon(Saloon*, int, char*, char*,char*,char*);
int protectedAddSaloon(Saloon*, int);

int printSaloon(Saloon*, int, int);

int findSaloonEmpty(Saloon*, int);
int findSaloonId(Saloon*, int, char*);
#endif /* SALOON_H_ */
