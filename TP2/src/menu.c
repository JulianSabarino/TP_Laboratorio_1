/*
 * menu.c
 *
 *  Created on: Nov 23, 2021
 *      Author: JS
 */

#include "menu.h"
#include <stdio.h>

void showMyMenu()
{
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. Salir\n");
}


void showModify()
{
	printf("Elija lo que quiera modificar\n");
	printf("\t1.Nombre\n");
	printf("\t2.Apellido\n");
	printf("\t3.Salario\n");
	printf("\t4.Sector\n");
}

void showInfo()
{
	printf("Elija lo que quiera mostrar\n");
	printf("\t1.Ordenados por sector y nombre\n");
	printf("\t2.Promedio de Salarios\n");
}

void showSort()
{
	printf("Elija como lo quiere ordenar\n");
	printf("\t0.Ascendente\n");
	printf("\t1.Descebdente\n");
}
