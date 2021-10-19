/*
 ============================================================================
 Name        : Parcial_Parte1.c
 Author      : Julian Sabarino
 Version     :
 Copyright   : 9/8/2021
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "saloon.h"
#include "arcade.h"
#include "informes.h"

#define LISTLENGHT 10

int main(void)
{
	setbuf(stdout,NULL);
	//Employee list[LENGTH];
	int option;
	int errorCode;
	Saloon saloonList[LISTLENGHT];
	Arcade arcadeList[LISTLENGHT];


	char id[7];
	int tokenPrice;
	char gameName[63];
	//initEmployees(list,LENGTH);
	/*
	errorCode = isAlph("EstoEsAlfa");
	printf("%d\n",errorCode);
	errorCode = isAlph("3st03sAlfaNum");
	printf("%d\n",errorCode);
	errorCode = charAlpha('A');
	printf("%d\n",errorCode);
	*/
	errorCode = initSaloon(saloonList, LISTLENGHT);
	errorCode = errorCode + initArcade(arcadeList, LISTLENGHT);
	errorCode = errorCode + myGames(0, NULL);

	if(errorCode == 0)
	{
		do
		{
			printMenuSaloon(1);
			printMenuArcade(4);
			printMenuInfo(9, 1);

			errorCode = getMyOption(&option);
			if(errorCode == 0)
			{
				switch(option)
				{
					case 1:
						errorCode = protectedAddSaloon(saloonList,LISTLENGHT); //funciona
						break;
					case 2:
						errorCode = protectedDeleteSaloon(saloonList, LISTLENGHT, arcadeList, LISTLENGHT); //funciona
						break;
					case 3:
						errorCode = printSaloon(saloonList, LISTLENGHT, 4); //funciona
						break;
					case 4:
						errorCode = protectedAddArcade(arcadeList, LISTLENGHT, saloonList, LISTLENGHT); //funciona
						break;
					case 5:
						errorCode = protectedModifyArcade(arcadeList, LISTLENGHT);//funciona
						break;
					case 6:
						errorCode = protectedDeleteArcade(arcadeList, LISTLENGHT); //funciona
						break;
					case 7:
						errorCode = printArcade(arcadeList, LISTLENGHT);//funciona
						break;
					case 8:
						errorCode = myGames(1, NULL); //funciona
						break;
					case 9:
						printMenuInfo(1, 0);
						errorCode = getMyOption(&option);
						switch(option)
						{
							case 1:
								listMediumSaloon(saloonList, LISTLENGHT, arcadeList, LISTLENGHT);
								break;
							case 2:
								listMultiplayer(arcadeList, LISTLENGHT);
								break;
							case 3:
								printSaloon(saloonList, LISTLENGHT, 4);
								printf("Ingrese Id del Salon: ");
								myGets(id, sizeof(id));
								listSaloonInfo(saloonList, LISTLENGHT, arcadeList, LISTLENGHT, id);
								break;
							case 4:
								printArcade(arcadeList, LISTLENGHT);
								printf("Ingrese Id del Arcade: ");
								myGets(id, sizeof(id));
								listArcadeInfo(saloonList, LISTLENGHT, arcadeList, LISTLENGHT, id);
								break;
							case 5:
								listBiggestSaloon(saloonList, LISTLENGHT, arcadeList, LISTLENGHT);
								break;
							case 6:
								printSaloon(saloonList, LISTLENGHT, 4);
								printf("Ingrese Id del Salon: ");
								myGets(id, sizeof(id));
								printf("Ingrese precio de las fichas: ");
								getMyInt(&tokenPrice);
								listSaloonIncome(saloonList, LISTLENGHT, arcadeList, LISTLENGHT, id, tokenPrice);
								break;
							case 7:
								myGames(1, NULL);
								printf("Ingrese Juego a Filtrar: ");
								myGets(gameName, sizeof(gameName));
								listArcadeGames(arcadeList, LISTLENGHT, gameName);
								break;
							default:
								printf("opcion invalida");
						}
						break;
				}
			}
			else
			{
				printf("Hubo problemas al ejecutar el programa");
				break;
			}
		}while(option != 0);
	}
	else
	{
		printf("Hubo problemas al ejecutar el programa");
	}
	puts("TP 1"); /* prints TP 1 */
	return EXIT_SUCCESS;
}
