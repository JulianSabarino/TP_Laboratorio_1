/*
 * arcade.h
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "myGets.h"
#include "saloon.h"

struct Arcade
{
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;

	char saloonId[7];
	char gameName[63];

	char id[7];

	int isEmpty;
};

typedef struct Arcade Arcade;

int initArcade(Arcade* list,int len);

int addArcade(Arcade*, int, char*, char*, int, int, char*, char*, char*);
int protectedAddArcade(Arcade*, int, Saloon*, int);

int deleteArcade(Arcade*, int, char*);
int protectedDeleteArcade(Arcade*, int);

int modifyGameArcade(Arcade*, int, char*, char*);
int modifyPlayArcade(Arcade*, int, char*, int);
int protectedModifyArcade(Arcade*, int);

int printArcade(Arcade*, int);

int findArcadeEmpty(Arcade*, int);
int findArcadeId(Arcade*, int, char*);

//CREAR UNA FUNCION QUE TENGA UN STATIC CON LA LISTA DE JUEGOS

int deleteSaloon(Saloon*, int, char*, Arcade*, int);
int protectedDeleteSaloon(Saloon*, int, Arcade*, int);


struct Games
{
	char gameName[63];
	int isEmpty;
};

typedef struct Games Games;

int initGames(Games*, int);
int myGames(int, char*);
int printMyGames(Games*, int);
int addNewGames(Games*, int, char*);

#endif /* ARCADE_H_ */
