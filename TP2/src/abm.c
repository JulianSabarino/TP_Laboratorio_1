/*
 * abm.c
 *
 *  Created on: Oct 5, 2021
 *      Author: JS
 */
#include "abm.h"
#include "menu.h"

int printEmployee(Employee* list,int len, int i)
{
	int errorCode = -1;
	if(i >=0 && i<len && list != NULL)
	{
		printf("%d %s %s %d %.2f\n",list[i].sector,list[i].lastName,list[i].name,list[i].id,list[i].salary);
		errorCode = 0;
	}
	return errorCode;
}

int printEmployees(Employee* list,int len)
{
	int i;
	int errorCode = -1;
	if(len >=0 && list != NULL)
	{
		printf("SECTOR\tSURNAME\tNAME\tID\tSALARY\n");
		for(i = 0; i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				errorCode = printEmployee(list, len, i);
				if(errorCode == -1)
				{
					break;
				}
			}
		}
	}
	return errorCode;
}

int initEmployees(Employee* Employee, int size)
{
	int i;
	int errorCode = -1;
	if(size >= 0 && Employee != NULL)
	{
		for(i = 0;i < size;i++)
		{
			Employee[i].isEmpty = 1;
		}
		errorCode = 0;
	}
	return errorCode;
}

int setEmployee(Employee* list, int id, char* name,char* lastName,float salary,int sector, int postition)
{
	int errorCode = -1;
	if(postition >= 0 && list != NULL)
	{
		list[postition].id = id;
		strncpy(list[postition].name,name,51);
		strncpy(list[postition].lastName,lastName,51);
		list[postition].salary = salary;
		list[postition].sector = sector;
		list[postition].isEmpty = 0;
		errorCode = 0;
	}
	return errorCode;
}

int addEmployee(Employee* list, int len, char* name,char* lastName,float salary,int sector)
{
	static int currentID = 0;
	int i;
	int errorCode = -1;
	if(list != NULL && len > 0)
	{
		i = findEmpty(list,len);
		if(i >= 0)
		{
			errorCode = setEmployee(list, currentID, name, lastName, salary, sector, currentID);
			if(errorCode == 0)
			{
				currentID++;
			}
		}
	}

	return errorCode;
}

int protectedAdd(Employee* list,int len)
{
	int errorCode = -1;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	if(list!=NULL && len >=0)
	{
		errorCode = 0;

		printf("Ingrese el NOMBRE del trabajador: ");
		errorCode = errorCode + myGets(name, 51);

		printf("Ingrese el APELLIDO del trabajador: ");
		errorCode = errorCode + myGets(lastName, 51);

		printf("Ingrese el SALARIO del trabajador: ");
		errorCode = errorCode + getMyFloat(&salary);

		printf("Ingrese el SECTOR del trabajador(numerico): ");
		errorCode = errorCode + getMyInt(&sector);

		if(errorCode == 0 && (salary>0 && sector>=0 && isAlph(name)==0 && isAlph(lastName)==0))
		{
			errorCode = addEmployee(list,len,name,lastName,salary,sector);
		}
		else
		{
			errorCode = -1;
		}
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
				else
				{
					errorCode = -1;
				}
				break;
			case 2:
				printf("Ingrese nuevo apellido: ");
				errorCode = myGets(buff, 51);
				if(errorCode == 0 && isAlph(buff) == 0)
				{
					strncpy(list[i].lastName,buff,51);
				}
				else
				{
					errorCode = -1;
				}
				break;
			case 3:
				printf("Ingrese nuevo salario: ");
				errorCode = getMyFloat(&salary);
				if(errorCode == 0 && salary > 0)
				{
					list[i].salary = salary;
				}
				else
				{
					errorCode = -1;
				}
				break;
			case 4:
				printf("Ingrese nuevo sector: ");
				errorCode = getMyInt(&sector);
				if(errorCode == 0 && sector >= 0)
				{
					list[i].sector = sector;
				}
				else
				{
					errorCode = -1;
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
	int errorCode = -1;
	int id;
	int position;
	int option;
	if(list != NULL && len >= 0)
	{
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
	int errorCode = -1;
	int id;
	int position;
	if(len >= 0 && list != NULL)
	{
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


int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int j;
	int errorCode = -1;
	if(list != NULL && len>0 && (order == 0 || order == 1))
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
						if(order == 0)
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
						else
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

int getPromSalary(Employee* list,int len, float* prom)
{
	int errorCode = -1;
	float acumulator = 0;
	int counter = 0;
	int i;
	if(list != NULL && len>0 )
	{
		for(i = 0; i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumulator = acumulator + list[i].salary;
				counter++;
			}
		}

		*prom = acumulator/counter;
		errorCode = counter;
	}
	return errorCode;

}

int promSalary(Employee* list, int len)
{
	int i;
	int counterMajProm = 0;
	float prom;
	int errorCode = -1;
	int counter;
	if(list != NULL && len>0 )
	{

		counter = getPromSalary(list, len, &prom);
		if(counter != -1)
		{
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
			for(i = 0; i<len;i++)
				{
					if(list[i].isEmpty == 0 && list[i].salary > prom)
					{
						printEmployee(list, len, i);
					}
				}
			errorCode = 0;
		}
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
						if(errorCode == 0)
						{
							printEmployees(list, len);
						}
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

