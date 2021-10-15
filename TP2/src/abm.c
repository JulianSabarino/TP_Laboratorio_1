/*
 * abm.c
 *
 *  Created on: Oct 5, 2021
 *      Author: JS
 */
#include "abm.h"

void showMyMenu()
{
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("\ta. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
	printf("\tb. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
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
	printf("\t1.Ordenados\n");
	printf("\t2.Promedio de Salarios\n");
}

void showSort()
{
	printf("Elija como lo quiere ordenar\n");
	printf("\t1.Ascendente\n");
	printf("\t2.Descebdente\n");
}

void printEmployee(Employee* list,int len, int i)
{
	printf("%d\t\t%s\t\t%s\t\t%.2f\t\t%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
}

void printEmployees(Employee* list,int len)
{
	//int j = findEmpty(list, len);
	int i;
	printf("ID\t\tNAME\t\tSURNAME\t\tSALARY\t\tSECTOR\n");
	for(i = 0; i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			printEmployee(list, len, i);
		}
	}
}

void initEmployees(Employee* Employee, int size)
{
	int i;
	for(i = 0;i < size;i++)
	{
		Employee[i].isEmpty = 1;
	}
}


int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
	int i;
	int errorCode = -1;
	if(list != NULL && len > 0)
	{
		i = findEmpty(list,len);
		if(i >= 0)
		{
			list[i].id = id;
			strncpy(list[i].name,name,51);
			strncpy(list[i].lastName,lastName,51);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;
			errorCode = i;
		}
	}

	return errorCode;
}

int protectedAdd(Employee* list,int len)
{
	int errorCode = 0;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	printf("Ingrese el ID del trabajador: ");
	errorCode = errorCode + getMyInt(&id);

	printf("Ingrese el NOMBRE del trabajador: ");
	errorCode = errorCode + myGets(name, 51);

	printf("Ingrese el APELLIDO del trabajador: ");
	errorCode = errorCode + myGets(lastName, 51);

	printf("Ingrese el SALARIO del trabajador: ");
	errorCode = errorCode + getMyFloat(&salary);

	printf("Ingrese el SECTOR del trabajador: ");
	errorCode = errorCode + getMyInt(&sector);

	if(errorCode == 0 && (id>0 && salary>0 && sector>=0 && isAlph(name)==0 && isAlph(lastName)==0))
	{
		errorCode = addEmployee(list,len,id,name,lastName,salary,sector);
	}

	return errorCode;
}

int modifyEmployee(Employee* list,int len, int i, int option)
{
	int errorCode = -1;
	char buff[51];
	float salary;
	int sector;
	if(list != NULL && len > 0)
	{
		switch(option)
		{
			case 1:
				printf("Ingrese nuevo nombre: ");
				errorCode = myGets(buff, 51);
				if(errorCode == 0 && isAlph(buff) == 0)
				{
					strncpy(list[i].name,buff,51);
				}
				break;
			case 2:
				printf("Ingrese nuevo apellido: ");
				errorCode = myGets(buff, 51);
				if(errorCode == 0 && isAlph(buff) == 0)
				{
					strncpy(list[i].lastName,buff,51);
				}
				break;
			case 3:
				printf("Ingrese nuevo salario: ");
				errorCode = getMyFloat(&salary);
				if(errorCode == 0 && salary > 0)
				{
					list[i].salary = salary;
				}
				break;
			case 4:
				printf("Ingrese nuevo sector: ");
				errorCode = getMyInt(&sector);
				if(errorCode == 0 && sector >= 0)
				{
					list[i].sector = sector;
				}
				break;
			default:
				errorCode = -1;
		}
	}
	return errorCode;
}

int protectedModify(Employee* list,int len)
{
	int errorCode = 0;
	int id;
	int position;
	int option;

	printEmployees(list, len);
	printf("Elija el el usuario por ID: ");
	errorCode = getMyInt(&id);
	if(errorCode == 0)
	{
		position = findEmployeeById(list, len, id);
		if(position != -1)
		{
			showModify();
			getMyInt(&option);
			if(option>0 && option<5)
			{
				errorCode = modifyEmployee(list,len, position, option);
			}
			else
			{
				printf("Opcion invalida \n");
			}
		}
		else
		{
			printf("ID invalido\n");
		}
	}

	return errorCode;
}

int removeEmployee(Employee* list, int len, int i)
{
	int errorCode = -1;
	if(list !=NULL && len > 0)
	{
		list[i].isEmpty = 1;
		errorCode = i;
	}
	return errorCode;
}

int protectedDelete(Employee* list, int len)
{
	int errorCode;
	int id;
	int position;

	printEmployees(list, len);
	printf("Elija el el usuario por ID: ");
	errorCode = getMyInt(&id);
	if(errorCode == 0)
	{
		position = findEmployeeById(list, len, id);
		if(position != -1)
		{
			errorCode = removeEmployee(list, len, position);
		}
		else
		{
			printf("ID invalido\n");
			errorCode = -1;
		}
	}
	return errorCode;
}

int swapEmployee(Employee* list,int len, int A, int B)
{
	int errorCode = -1;
	Employee buff;
	if(list != NULL && len>0 && A<len && B<len)
	{
		buff.id = list[A].id;
		strncpy(buff.name,list[A].name,51);
		strncpy(buff.lastName,list[A].lastName,51);
		buff.salary = list[A].salary;
		buff.sector = list[A].sector;

		list[A].id = list[B].id;
		strncpy(list[A].name,list[B].name,51);
		strncpy(list[A].lastName,list[B].lastName,51);
		list[A].salary = list[B].salary;
		list[A].sector = list[B].sector;

		list[B].id = buff.id;
		strncpy(list[B].name,buff.name,51);
		strncpy(list[B].lastName,buff.lastName,51);
		list[B].salary = buff.salary;
		list[B].sector = buff.sector;

		errorCode = 0;
	}

	return errorCode;
}

int sortAscending(Employee* list, int len)
{
	int i;
	int j;
	int errorCode = -1;
	if(list != NULL && len>0)
	{
		errorCode = 0;
		for(i=0;i<len-1;i++)
		{
			//impArray(array,len);
			if(list[i].isEmpty == 0)
			{
				for(j=(i+1);j<len;j++)
				{
					if(list[j].isEmpty == 0)
					{
						if(list[i].sector>list[j].sector)
						{
							errorCode = swapEmployee(list,len, i, j);
						}
						else
						{
							if(list[i].sector==list[j].sector)
							{
								if(stricmp(list[i].lastName,list[j].lastName)>0)
								{
									errorCode = swapEmployee(list,len, i, j);
								}
							}
						}
					}
					if(errorCode != 0)
					{
						break;
					}
				}
			}
		}
	}
	return errorCode;
}

int sortDescending(Employee* list, int len)
{
	int i;
	int j;
	int errorCode = -1;
	if(list != NULL && len>0)
	{
		errorCode = 0;
		for(i=0;i<len-1;i++)
		{
			//impArray(array,len);
			if(list[i].isEmpty == 0)
			{
				for(j=(i+1);j<len;j++)
				{
					if(list[j].isEmpty == 0)
					{
						if(list[i].sector<list[j].sector)
						{
							errorCode = swapEmployee(list,len, i, j);
						}
						else
						{
							if(list[i].sector==list[j].sector)
							{
								if(stricmp(list[i].lastName,list[j].lastName)<0)
								{
									errorCode = swapEmployee(list,len, i, j);
								}
							}
						}
					}
					if(errorCode != 0)
					{
						break;
					}
				}
			}
		}
	}
	return errorCode;
}

int sortEmployees(Employee* list, int len, int order)
{
	int errorCode = -1;
	if(list != NULL && len>0)
	{
		switch(order)
		{
			case 1:
				errorCode = sortAscending(list, len);
				break;
			case 2:
				errorCode = sortDescending(list, len);
				break;
			default:
				printf("Opcion invalida");
		}
	}
	printEmployees(list, len);

	return errorCode;
}

int promSalary(Employee* list, int len)
{
	int i;
	float acumulator = 0;
	int counter = 0;
	int counterMajProm = 0;
	float prom;
	int errorCode = -1;
	if(list != NULL && len>0)
	{
		for(i = 0; i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumulator = acumulator + list[i].salary;
				counter++;
			}
		}

		prom = acumulator/counter;

		for(i = 0; i<len;i++)
			{
				if(list[i].isEmpty == 0 && list[i].salary > prom)
				{
					counterMajProm++;
				}
			}

		printf("Usuarios contados: %d\n",counter);
		printf("El promedio de salario es: %.2f\n",prom);
		printf("Cantidad de usuarios por encima del promedio: %d\n",counterMajProm);

		errorCode = 0;
	}
	return errorCode;
}

int protectedInfo(Employee* list, int len)
{
	int errorCode = -1;
	int option;

	if(list != NULL && len>0)
	{
		showInfo();

		errorCode = getMyInt(&option);
		if(errorCode == 0)
		{
			switch(option)
			{
				case 1:
					showSort();
					errorCode = getMyInt(&option);
					if(errorCode == 0)
					{
						errorCode = sortEmployees(list, len, option);
					}
					break;
				case 2:
					errorCode = promSalary(list, len);
					break;
				default:
					printf("Opcion Invalida\n");
					errorCode = -1;
			}
		}
	}
	return errorCode;
}

int findEmpty(Employee* list, int len)
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

int findEmployeeById(Employee* list, int len,int id)
{
	int errorCode = -1;
	int i;

	if(list !=NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].id==id)
			{
				errorCode = i;
				break;
			}
		}
	}

	return errorCode;
}

