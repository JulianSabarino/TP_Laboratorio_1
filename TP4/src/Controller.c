#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "myFunc.h"
#include "parser.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int errorCode = -1;
	char buffer[128];

	FILE *fp = fopen(path,"r");
	if(fp != NULL && pArrayListEmployee != NULL)
	{
		fgets(buffer, sizeof(buffer),fp);
		printf("%s",buffer);
		while(!feof(fp))
		{
			errorCode = parser_EmployeeFromText(fp, pArrayListEmployee);
			if(errorCode == -1)
			{
				break;
			}
		}
		fclose(fp);
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
	int errorCode = -1;

	FILE *fp = fopen(path,"rb");
	if(fp != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(fp))
		{
			errorCode = parser_EmployeeFromBinary(fp, pArrayListEmployee);
			if(errorCode == -1)
			{
				break;
			}
		}
		employee_getId(ll_get(pArrayListEmployee, ll_len(pArrayListEmployee)-1), &errorCode);
		fclose(fp);
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
	//printf("employee data: %d %d %s %d %d\n",errorCode,id,nombre, horasT, sueldo);
	if(employee != NULL && pArrayListEmployee != NULL)
	{
		errorCode = get_employee_data(nombre, &horasT, &sueldo);
		if(errorCode == 0)
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
	int errorCode = -1;
	int idToSearch;
	int index;
	Employee* pElement;
	if(pArrayListEmployee != NULL)
	{
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
	int errorCode = -1;
	int idToSearch;
	int index;
	Employee* pElement;
	if(pArrayListEmployee != NULL)
	{
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
	Employee * employee;
	int id;
	char nombre[128];
	int hora;
	int sueldo;

	if(ListEmployee != NULL)
	{
		printf("ID | NOMBRE | HORAS | SUELDO \n");
		for(int i = 0; i < ll_len(ListEmployee); i++)
		{
			employee = (Employee*)ll_get(ListEmployee, i);
			employee_getId(employee, &id);
			employee_getNombre(employee, nombre);
			employee_getHorasTrabajadas(employee, &hora);
			employee_getSueldo(employee, &sueldo);

			printf("%d %s %d %d\n",id,nombre,hora,sueldo);
		}
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
	Employee* employee;

	int id;
	char nombre[128];
	int horas;
	int sueldo;
	int errorCode = 0;
	int size = ListEmployee->size;

	if(fp != NULL && ListEmployee != NULL)
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
	Employee* employee;

	int errorCode = 0;
	int size = ll_len(ListEmployee);

	if(fp != NULL && ListEmployee != NULL)
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

    return errorCode;
}

