/*
 * informes.h
 *
 *  Created on: Oct 18, 2021
 *      Author: JS
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "arcade.h"
#include "myGets.h"
#include "saloon.h"

int listMediumSaloon(Saloon* listS,int lenS,Arcade* ListA,int lenA);
int listMultiplayer(Arcade* list, int len);
int listSaloonInfo(Saloon* listS,int lenS,Arcade* listA,int lenA, char* id);
int listArcadeInfo(Saloon* listS,int lenS,Arcade* listA,int lenA, char* id);
int listBiggestSaloon(Saloon* listS,int lenS,Arcade* listA,int lenA);
int listSaloonIncome(Saloon* listS,int lenS,Arcade* listA,int lenA,char* id, int tokenPrice);
int listArcadeGames(Arcade* list, int len, char* gameName);
#endif /* INFORMES_H_ */
