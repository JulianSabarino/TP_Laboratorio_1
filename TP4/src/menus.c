/*
 * menus.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#include "menus.h"

void showMenu()
{
	printf("1. Cargar los datos de los empleados (modo texto).\n");
	printf("2. Cargar los datos de los empleados (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");
}

int getMyOption(int* option)
{
	int errorCode;
	printf("\nElegir Opcion: ");
	errorCode = getMyInt(option);
	return errorCode;
}

