/*
 * arcade.h
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "myFunc.h"
#include "saloon.h"
#include "lList.h"
struct Arcade
{
	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
};

typedef struct Arcade Arcade;

Arcade* arcade_new();
Arcade* arcade_newParameters(int currentID);
int arcade_setAll(Arcade* this,int id,char* gameName, char* nation, char* soundType, int cantPlayers, int maxToken);
int arcade_getAll(Arcade* this,int* id,char* gameName, char* nation, char* soundType, int* cantPlayers, int* maxToken);
int arcade_getId(Arcade* this, int* id);


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

///////////////////
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
