/*
 ============================================================================
 Name        : TP2.c
 Author      : Julian Sabarino
 Version     :
 Copyright   : 9/8/2021
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#include "menu.h"

#define LENGTH 1000

int main(void)
{
	setbuf(stdout,NULL);
	Employee list[LENGTH];
	int option;
	int errorCode;
	initEmployees(list,LENGTH);

	addEmployee(list, LENGTH,"Julian","Sabarino",19500,0);
	addEmployee(list, LENGTH,"Tobias","Fornaroli",24000,1);
	addEmployee(list, LENGTH,"Juan","Cristal",35000,3);
	addEmployee(list, LENGTH,"Tomas","Amitrano",16000,2);
	addEmployee(list, LENGTH,"Mateo","Amitrano",5000,1);
	addEmployee(list, LENGTH,"Roberto","Alfonso",18000,0);
	addEmployee(list, LENGTH,"Aladin","Kaladin",25000,1);
	addEmployee(list, LENGTH,"Ruberto","Elsapodetective",48000,2);
	addEmployee(list, LENGTH,"Gasparin","Fantasma",12000,3);
	addEmployee(list, LENGTH,"Benja","Monkee",40000,0);

	do
	{
		showMyMenu();
		errorCode = getMyInt(&option);//Toma un valor entero, si el valor no es valido (por ejemplo un float o un string) cierra el programa
		if(errorCode == 0)
		{
			switch(option)
			{
				case 1:
					errorCode = protectedAdd(list,LENGTH);
					if(errorCode < 0)
					{
						printf("Fallo al Agregar\n");
					}
					break;
				case 2:
					errorCode = protectedModify(list,LENGTH);
					if(errorCode == -1)
					{
						printf("Fallo al Modificar\n");
					}
					break;
				case 3:
					errorCode = protectedDelete(list,LENGTH);
					if(errorCode == -1)
					{
						printf("Fallo al Eliminar\n");
					}
					break;
				case 4:
					errorCode = protectedInfo(list, LENGTH);
					if(errorCode == -1)
					{
						printf("Fallo al Mostrar\n");
					}
					break;
			}
		}
		else
		{
			printf("Hubo problemas al ejecutar el programa");
			break;
		}

	}while(option != 5);

	puts("TP 2"); /* prints TP 1 */
	return EXIT_SUCCESS;
}

