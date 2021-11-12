#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "myFunc.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int errorCode = 0;
	char buffer[128];
	int id;
	char nombre[128];
	int horas;
	int sueldo;

	int read;

	Employee *employee;

	FILE *fp = fopen(path,"r");
	if(fp != NULL)
	{
		fgets(buffer, sizeof(buffer),fp);
		printf("%s",buffer);
		while(!feof(fp))
		{
			employee= employee_new();
			read = fscanf(fp,"%d,%[^,],%d,%d\n",&id,nombre,&horas,&sueldo);
			if(read == 4 && employee != NULL)
			{
				errorCode = errorCode + employee_setId(employee, id);
				errorCode = errorCode + employee_setNombre(employee, nombre);
				errorCode = errorCode + employee_setHorasTrabajadas(employee, horas);
				errorCode = errorCode + employee_setSueldo(employee, sueldo);
				if(errorCode >= 0)
				{
					ll_add(pArrayListEmployee, employee);
					errorCode=id;
				}
			}
			else
			{
				errorCode=-1;
				break;
			}
		}
	}
	else
	{
		errorCode = -1;
	}

    return errorCode;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int errorCode = 0;
	int id;
	Employee *employee;

	FILE *fp = fopen(path,"rb");
	if(fp != NULL)
	{
		while(!feof(fp))
		{
			employee = employee_new();
			fread(employee, sizeof(Employee),1,fp);
			errorCode=employee_getId(employee, &id);
			if(id > 0)
			{
				ll_add(pArrayListEmployee, employee);
			}
		}
	}
	else
	{
		errorCode = -1;
	}

    return errorCode;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int currentID)
{
	int errorCode = -1;

	char nombre[128];
	int horasT;
	int sueldo;
	int id = currentID + 1;
	Employee* employee = employee_new();

	errorCode = get_employee_data(nombre, &horasT, &sueldo);
	printf("employee data: %d %d %s %d %d\n",errorCode,id,nombre, horasT, sueldo);
	if(errorCode == 0 && employee != NULL)
	{
		errorCode = errorCode + employee_setId(employee,id);
		errorCode = errorCode + employee_setNombre(employee, nombre);
		errorCode = errorCode + employee_setHorasTrabajadas(employee, horasT);
		errorCode = errorCode + employee_setSueldo(employee, sueldo);
		if(errorCode == 0)
		{
			errorCode = ll_add(pArrayListEmployee, employee);
			if(errorCode == 0)
			{
				errorCode = id;
			}
		}
		else
		{
			errorCode = -1;
		}
	}
	else
	{
		errorCode = -1;
	}

    return errorCode;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int errorCode;
	int idToSearch;
	int index;
	Employee* pElement;
	controller_ListEmployee(pArrayListEmployee);
	printf("Ingrese ID a modificar:");
	errorCode = getMyInt(&idToSearch);
	if(errorCode == 0)
	{
		pElement = searchById(pArrayListEmployee, idToSearch, &index);

		if(pElement != NULL)
		{
			errorCode = modify_all(pElement);
			if(errorCode == 0)
			{
				errorCode = ll_set(pArrayListEmployee, errorCode, pElement);
			}
		}
		else
		{
			errorCode = -1;
		}
	}

    return errorCode;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int errorCode;
	int idToSearch;
	int index;
	Employee* pElement;
	printf("Ingrese ID a Eliminar:");
	errorCode = getMyInt(&idToSearch);
	if(errorCode == 0)
	{
		pElement = searchById(pArrayListEmployee, idToSearch, &index);

		if(pElement != NULL)
		{
			errorCode = ll_remove(pArrayListEmployee,index);
			if(errorCode == 0)
			{
				free(pElement);
			}
		}
		else
		{
			errorCode = -1;
		}
	}

    return errorCode;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* ListEmployee)
{
	int errorCode = -1;
	Node* tempList = ListEmployee->pFirstNode;

	int id;
	char nombre[128];
	int hora;
	int sueldo;


	printf("ID | NOMBRE | HORAS | SUELDO \n");
	while(tempList!=NULL)
		{
			employee_getId(tempList->pElement, &id);
			employee_getNombre(tempList->pElement, nombre);
			employee_getHorasTrabajadas(tempList->pElement, &hora);
			employee_getSueldo(tempList->pElement, &sueldo);

			printf("%d %s %d %d\n",id,nombre,hora,sueldo);

			tempList = tempList->pNextNode;
		}


    return errorCode;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* listaEmpleados)
{
	int errorCode;
	errorCode = ll_sort(listaEmpleados, compare_employee,1);
    return errorCode;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* ListEmployee)
{
	FILE *fp = fopen(path,"w");
	//Node* tempList = ListEmployee->pFirstNode;
	Employee* employee;

	int id;
	char nombre[128];
	int horas;
	int sueldo;
	int errorCode = 0;
	int size = ListEmployee->size;

	if(fp != NULL)
	{
		fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
		for(int i = 0; i < size; i++)
		{
			employee = ll_get(ListEmployee,i);
			if(employee != NULL)
			{
				errorCode = errorCode + employee_getId(employee, &id);
				errorCode = errorCode + employee_getNombre(employee, nombre);
				errorCode = errorCode + employee_getHorasTrabajadas(employee, &horas);
				errorCode = errorCode + employee_getSueldo(employee, &sueldo);
				if(errorCode == 0)
				{
					fprintf(fp,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
				}
			}

		}
		fclose(fp);
	}
	else
	{
		errorCode = -1;
	}
	/*
	if(fp != NULL)
	{
		fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
		while(tempList!=NULL)
		{
			errorCode = errorCode + employee_getId(tempList->pElement, &id);
			errorCode = errorCode + employee_getNombre(tempList->pElement, nombre);
			errorCode = errorCode + employee_getHorasTrabajadas(tempList->pElement, &horas);
			errorCode = errorCode + employee_getSueldo(tempList->pElement, &sueldo);
			if(errorCode == 0)
			{
				fprintf(fp,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
				tempList = tempList->pNextNode;
			}
		}
		fclose(fp);
	}
	*/
    return errorCode;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* ListEmployee)
{
	FILE *fp = fopen(path,"wb");
	//Node* tempList = ListEmployee->pFirstNode;
	Employee* employee;

	int errorCode = 0;
	int size = ListEmployee->size;

	if(fp != NULL)
	{
		for(int i = 0; i < size; i++)
		{
			employee = ll_get(ListEmployee,i);
			if(employee != NULL )
			{
				fwrite(employee,sizeof(Employee),1,fp);
			}
		}
	}
	else
	{
		errorCode = -1;
	}

	/*
	if(fp != NULL)
	{
		while(tempList!=NULL)
		{
			fwrite(tempList->pElement,sizeof(Employee),1,fp);
			tempList = tempList->pNextNode;
		}
		fclose(fp);
	}
	*/


    return errorCode;
}

