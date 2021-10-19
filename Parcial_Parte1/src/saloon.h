/*
 * saloon.h
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#ifndef SALOON_H_
#define SALOON_H_

struct Saloon
{
	char id[7];
	char name[51];
	char direc[51];
	char type[20];
	int isEmpty;
};

typedef struct Saloon Saloon;

int initSaloon(Saloon*, int);

int addSaloon(Saloon*, int, char*, char*,char*,char*);
int protectedAddSaloon(Saloon*, int);

int printSaloon(Saloon*, int, int);

int findSaloonEmpty(Saloon*, int);
int findSaloonId(Saloon*, int, char*);
#endif /* SALOON_H_ */
