/*
 * saloon.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */
#include "myFunc.h"
#include "saloon.h"
#include "lList.h"
Saloon* saloon_new()
{
	Saloon* this =(Saloon*)malloc(sizeof(Saloon));
	if(this!=NULL)
	{
		this->pFirstArcade = NULL;
	}
	return this;
}


int saloon_setName(Saloon* this,char* nombre)
{
	int errorCode = -1;
	if(this != NULL)
	{
		strncpy(this->name, nombre, 51);
		errorCode = 0;
	}
	return errorCode;
}

int saloon_getName(Saloon* this,char* nombre)
{
	int errorCode = -1;
	if(this != NULL)
	{
		strncpy(nombre,this->name, 51);
		errorCode = 0;
	}
	return errorCode;
}


/*

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int errorCode = -1;
	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		errorCode = 0;
	}
	return errorCode;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int errorCode = -1;
	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		errorCode = 0;
	}
	return errorCode;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int errorCode = -1;
	if(this != NULL)
	{
		this->sueldo = sueldo;
		errorCode = 0;
	}
	return errorCode;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int errorCode = -1;
	if(this != NULL)
	{
		*sueldo = this->sueldo;
		errorCode = 0;
	}
	return errorCode;
}



Employee* employee_new()
{
	Employee* this = malloc(sizeof(Employee));
	return this;
}

int get_employee_data( char* nombre, int* horasT, int* sueldo)
{
	int errorCode = 0;
	//char name[128];
	printf("Ingrese Nombre: ");
	errorCode = errorCode + myGets(nombre, 128);
	//printf("%s",name);
	printf("Ingrese horas trabajadas: ");
	errorCode = errorCode + getMyInt(horasT);
	printf("Ingrese sueldo trabajadas: ");
	errorCode = errorCode + getMyInt(sueldo);

	if(errorCode!=0)
	{
		errorCode = -1;
	}

	return errorCode;
}

Employee* searchById(LinkedList* ListEmployee, int idToSearch, int* index)
{
	Employee* errorCode = NULL;
	Node* tempList = ListEmployee->pFirstNode;
	int id;
	int error;

	while(tempList!=NULL)
	{
		error = employee_getId(tempList->pElement, &id);
		if(error == 0)
		{
			if(id == idToSearch)
			{
				*index = ll_indexOf(ListEmployee,tempList->pElement);
				errorCode =tempList->pElement;
				break;
			}
			else
			{
				tempList = tempList->pNextNode;
			}
		}
	}

	return errorCode;
}

int modify_all(Employee* this)
{
	int errorCode = -1;
	char nombre[128];
	int horasT;
	int sueldo;

	errorCode = get_employee_data(nombre, &horasT, &sueldo);
	if(errorCode == 0 && this != NULL)
	{
		errorCode = errorCode + employee_setNombre(this, nombre);
		errorCode = errorCode + employee_setHorasTrabajadas(this, horasT);
		errorCode = errorCode + employee_setSueldo(this, sueldo);
	}

	if(errorCode !=0)
	{
		errorCode = -1;
	}
	return errorCode;
}

int compare_employee(void* this,void* that)
{
	int errorCode = 0;

	Employee* e1 = this;
	Employee* e2 = that;

	if(this != NULL && that != NULL)
	{
		errorCode = strcmp(e1->nombre,e2->nombre);
	}

	return errorCode;
}






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

	//if(errorCode == 0 && (stricmp(type,"Local") == 0 || stricmp(type,"Shopping") == 0)){}
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
*/
