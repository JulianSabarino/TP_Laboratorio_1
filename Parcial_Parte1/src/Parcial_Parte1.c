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
		addSaloon(saloonList, LISTLENGHT, "AlfaBe", "Yulians", "Micasa", "Shopping");
		addSaloon(saloonList, LISTLENGHT, "BerFa", "Marinas", "Tucasa", "Shopping");
		addSaloon(saloonList, LISTLENGHT, "CarTu", "Halfonzos", "Lacasa", "Local");

		addArcade(arcadeList, LISTLENGHT, "Argentina", "Mono", 2, 50, "AlfaBe", "SnowBros", "SnowAr");
		addArcade(arcadeList, LISTLENGHT, "Peru", "Estereo", 1, 100, "AlfaBe", "MarioBros", "MariPe");

		myGames(2, "SnowBros");
		myGames(2, "MarioBros");

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
						if(errorCode==-1)
						{
							printf("No se pudo Agregar Salon");
						}
						break;
					case 2:
						errorCode = protectedDeleteSaloon(saloonList, LISTLENGHT, arcadeList, LISTLENGHT); //funciona
						if(errorCode==-1)
						{
							printf("No se pudo Eliminar Salon");
						}
						break;
					case 3:
						errorCode = printSaloon(saloonList, LISTLENGHT, 4); //funciona
						break;
					case 4:
						errorCode = protectedAddArcade(arcadeList, LISTLENGHT, saloonList, LISTLENGHT); //funciona
						if(errorCode==-1)
						{
							printf("No se pudo Agregar Arcade");
						}
						break;
					case 5:
						errorCode = protectedModifyArcade(arcadeList, LISTLENGHT);//funciona
						if(errorCode==-1)
						{
							printf("No se pudo Modificar Arcade");
						}
						break;
					case 6:
						errorCode = protectedDeleteArcade(arcadeList, LISTLENGHT); //funciona
						if(errorCode==-1)
						{
							printf("No se pudo Eliminar Arcade");
						}
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
								listMultiplayer(arcadeList, LISTLENGHT); //funciona
								break;
							case 3:
								printSaloon(saloonList, LISTLENGHT, 4);
								printf("Ingrese Id del Salon: ");
								myGets(id, sizeof(id));
								listSaloonInfo(saloonList, LISTLENGHT, arcadeList, LISTLENGHT, id); //funciona
								break;
							case 4:
								printSaloon(saloonList, LISTLENGHT, 4);
								printf("Ingrese Id del Salon: ");
								myGets(id, sizeof(id));
								listArcadeInfo(saloonList, LISTLENGHT, arcadeList, LISTLENGHT, id); //funciona
								break;
							case 5:
								listBiggestSaloon(saloonList, LISTLENGHT, arcadeList, LISTLENGHT);//funciona
								break;
							case 6:
								printSaloon(saloonList, LISTLENGHT, 4); //funciona
								printf("Ingrese Id del Salon: ");
								myGets(id, sizeof(id));
								printf("Ingrese precio de las fichas: ");
								getMyInt(&tokenPrice);
								errorCode = listSaloonIncome(saloonList, LISTLENGHT, arcadeList, LISTLENGHT, id, tokenPrice);
								printf("El ingreso maximo del salon seleccionado es: %d \n",errorCode);
								break;
							case 7:
								myGames(1, NULL); //no funciona
								printf("Ingrese Juego a Filtrar: ");
								myGets(gameName, sizeof(gameName));
								errorCode = listArcadeGames(arcadeList, LISTLENGHT, gameName);
								printf("El juego seleccionado aparece en %d Arcades\n",errorCode);
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
	puts("Parcial 1"); /* prints TP 1 */
	return EXIT_SUCCESS;
}
