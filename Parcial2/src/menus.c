/*
 * menus.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#include "menus.h"

void showMenu()
{
	printf("1. Cargar los datos de Arcades y Salones (modo texto).\n");
	printf("2. Alta de Salon\n");
	printf("3. Alta de Arcade\n");
	printf("4. Modificar Arcade\n");
	printf("5. Baja de Salon\n");
	printf("6. Baja de Arcade\n");
	printf("7. Informes\n");
	printf("8. Duplicar Tokens\n");
}

void showList()
{
	printf("1. Listar Salones\n");
	printf("2. Listar Arcades Ordenados por Nombre\n");
	printf("3. Generar Archivo Juegos\n");
	printf("4. Generar Archivo Arcade Multijugador\n");
}

int getMyOption(int* option)
{
	int errorCode;
	printf("\nElegir Opcion: ");
	errorCode = getMyInt(option);
	return errorCode;
}

