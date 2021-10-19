/*
 * saloon.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */
#include "myGets.h"
#include "saloon.h"

int initSaloon(Saloon* list,int len)
{
	int i;
	int errorCode = -1;
	if(list !=NULL && len > 0)
	{
		for(i = 0;i < len;i++)
		{
			list[i].isEmpty = 1;
		}
		errorCode = 0;
	}
	return errorCode;
}

int printSaloon(Saloon* list, int len, int options)
{
	int errorCode = -1;
	int i;
	if(list !=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(options>0)
				{
					printf("ID: %s ",list[i].id);
				}
				if(options>1)
				{
					printf("Name: %s ",list[i].name);
				}
				if(options>2)
				{
					printf("Direc: %s ",list[i].direc);
				}
				if(options>3)
				{
					printf("Tipo: %s ",list[i].type);
				}
				printf("\n");
			}
		}
		errorCode = 0;

	}
	return errorCode;
}


int addSaloon(Saloon* list, int len, char* id, char* name,char* direc,char* type)
{
	int i;
	int errorCode = -1;
	if(list != NULL && len > 0)
	{
		i = findSaloonEmpty(list,len);
		if(i >= 0)
		{
			strncpy(list[i].id,id,7);
			strncpy(list[i].name,name,51);
			strncpy(list[i].direc,direc,51);
			strncpy(list[i].type,type,20);

			list[i].isEmpty = 0;

			errorCode = i;
		}
	}

	return errorCode;
}

int protectedAddSaloon(Saloon* list,int len)
{
	int errorCode = -1;
	char id[7];
	char name[51];
	char direc[51];
	char type[20];
	//static int ID = 0; // USO ESTO SI QUIERO CREAR UN ID AUTOINCREMENTAL

	printf("Ingrese Nombre del Salon: ");
	errorCode = myGets(name,51);

	printf("Ingrese Direccion del Salon: ");
	errorCode = errorCode + myGets(direc,51);

	printf("Ingrese Tipo del Salon: ");
	errorCode = myGets(type,20);

	if(errorCode == 0)
	{
		strncpy(id,type,1);
		strncat(id,name,3);
		strncat(id,direc,2);

		id[6] = '\0';

		errorCode = addSaloon(list, len, id, name, direc, type);
		//ID++;
	}

	return errorCode;
}

int findSaloonEmpty(Saloon* list, int len)
{
	int errorCode = -1;
	int i;

	if(list !=NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				errorCode = i;
				break;
			}
		}
	}

	return errorCode;
}

int findSaloonId(Saloon* list, int len, char* id)
{
	int errorCode = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(stricmp(list[i].id,id)==0)
			{
				errorCode = i;
				break;
			}
		}
	}

	return errorCode;
}
