/*
 ============================================================================
 Name        : Parcial2.c
 Author      : Julian Sabarino
 Version     :
 Copyright   : 9/8/2021
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lList.h"
#include "Controller.h"
//#include "Employee.h"
#include "menus.h"
#include "error.h"

int main(void)
{
	setbuf(stdout,NULL);

	int option;
	int errorCode;
	int currentID;
	LinkedList* lList = ll_newLinkedList();
	LinkedList* jointList;

	do
	{
		showMenu();
		getMyOption(&option);
		switch(option)
		{
			case 1:
				errorCode = controller_loadFromText("arcades.csv" , lList);
				if(errorCode == -1)
				{
					ERROR(2);
				}
				else
				{
					currentID = errorCode + 1;
				}
				break;
			case 2:
				errorCode = controller_addSaloon(lList);
				if(errorCode == -1)
				{
					ERROR(3);
				}
				else
				{
					if(errorCode == -2)
					{
						ERROR(1);
					}
					else
					{
						printf("\nAgregado correctamente\n");
					}
				}
				break;
			case 3:
				errorCode = controller_addArcade(lList,currentID);
				if(errorCode == -1)
				{
					ERROR(3);
				}
				else
				{
					if(errorCode == -2)
					{
						ERROR(1);
					}
					else
					{
						printf("\nAgregado correctamente\n");
					}
				}
				break;
			case 4:
				errorCode = controller_modifyArcade(lList);
				if(errorCode == -1)
				{
					ERROR(3);
				}
				else
				{
					if(errorCode == -2)
					{
						ERROR(1);
					}
					else
					{
						printf("\nAgregado correctamente\n");
					}
				}
				break;
			case 5:
				errorCode = controller_deleteSaloon(lList);
				if(errorCode == -1)
				{
					ERROR(3);
				}
				else
				{
					printf("\Eliminado correctamente\n");
				}
				break;
			case 6:
				errorCode = controller_deleteArcade(lList);
				if(errorCode == -1)
				{
					ERROR(3);
				}
				else
				{
					printf("\Eliminado correctamente\n");
				}
				break;
			case 7:
				showList();
				getMyOption(&option);
				switch(option)
				{
				case 1:
					printf("\n");
					controller_ListSaloon(lList);
					printf("\n");
					break;
				case 2:
					jointList = controller_generateJoinList(lList);
					ll_sort(jointList, controller_sortJoint, 1);
					printf("\n");
					controller_printAllJoin(jointList);
					printf("\n");
					ll_clear(jointList);
					break;
				case 3:
					jointList = controller_generateJoinList(lList);
					ll_sort(jointList, controller_sortJoint, 1);
					controller_saveGames(jointList);
					ll_clear(jointList);
					break;
				case 4:
					jointList = controller_generateJoinList(lList);
					ll_sort(jointList, controller_sortJoint, 1);
					ll_filter(jointList, controller_filterMultiplayer);
					printf("\n");
					controller_printAllJoin(jointList);
					printf("\n");
					controller_saveMultiplayer(jointList);
					ll_clear(jointList);
					break;

				default:
					printf("Opcion invalida\n");
				}
				break;
			case 8:
				jointList = controller_generateJoinList(lList);
				ll_sort(jointList, controller_sortJoint, 1);
				ll_map(jointList,controller_duplicateTokens);
				printf("\n");
				controller_printAllJoin(jointList);
				printf("\n");
				controller_saveKointAsText(jointList);
				ll_clear(jointList);
				break;
			case 10:
				printf("adios!");
				break;

		}



	}while(option != 10);


	//controller_loadFromText("arcades.csv" , lList);
	//controller_ListSaloon(lList);
}
