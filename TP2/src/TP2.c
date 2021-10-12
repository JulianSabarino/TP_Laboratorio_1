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

int main(void)
{
	setbuf(stdout,NULL);
	Employee list[1000];
	int option;
	int errorCode;
	initEmployees(list,1000);


	do
	{
		showMyMenu();
		getMyInt(&option);
		//printf("%d\n",findEmpty(list,1000));

		switch(option)
		{
			case 1:
				errorCode = protectedAdd(list,1000);
				if(errorCode == -1)
				{
					printf("Fallo al agregar\n");
				}
				break;
			case 2:
				errorCode = protectedModify(list,1000);
				if(errorCode == -1)
				{
					printf("Fallo al modificar\n");
				}
				break;
			case 3:
				errorCode = protectedDelete(list,1000);
				break;
			case 4:
				sortEmployees(list, 1000, 1);
				/*
				errorCode = protectedInfo(list,1000);
				printEmployees(list, 1000);*/
				break;
		}
		//printf("%d",choice);

	}while(option != 5);

	puts("TP 1"); /* prints TP 1 */
	return EXIT_SUCCESS;
}

