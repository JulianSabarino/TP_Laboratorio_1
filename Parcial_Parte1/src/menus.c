/*
 * menus.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#include "menus.h"

void printMenuSaloon(int startingMenu)
{
	printf("%d.Alta de Salon\n",startingMenu);
	printf("%d.Baja de Salon\n",(startingMenu+1));
	printf("%d.Imprimir Salones\n",(startingMenu+2));
}

void printMenuArcade(int startingMenu)
{
	printf("%d.Alta de Arcade\n",startingMenu);
	printf("%d.Modificar Arcade\n",(startingMenu+1));
	printf("%d.Baja de Arcade\n",(startingMenu+2));
	printf("%d.Imprimir Arcades\n",(startingMenu+3));
	printf("%d.Imprimir Juegos\n",(startingMenu+4));
}

void printMenuInfo(int startingMenu,int isMenu)
{
	if(isMenu==1)
	{
		printf("%d.Informes\n",startingMenu);
	}
	else
	{
		printf("\t1.Salones Medios (4+ Arcades)\n");
		printf("\t2.Arcades Multijugador\n");
		printf("\t3.Salon por ID\n");
		printf("\t4.Arcades por ID de Salon\n");
		printf("\t5.Salones mas Grande\n");
		printf("\t6.Recaudacion Maxima\n");
		printf("\t7.Juego por Cantidad de Arcades\n");
	}
}

int getMyOption(int* option)
{
	int errorCode;
	printf("\nElegir Opcion: ");
	errorCode = getMyInt(option);
	return errorCode;
}

