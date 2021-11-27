#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int errorCode = 0;
//	char buffer[128];
	int id;
	char nombre[128];
	int horas;
	int sueldo;

	int read;

	Employee *employee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		employee = employee_new();
		read = fscanf(pFile,"%d,%[^,],%d,%d\n",&id,nombre,&horas,&sueldo);
		if(read == 4 && employee != NULL)
		{
			errorCode = errorCode + employee_setId(employee, id);
			errorCode = errorCode + employee_setNombre(employee, nombre);
			errorCode = errorCode + employee_setHorasTrabajadas(employee, horas);
			errorCode = errorCode + employee_setSueldo(employee, sueldo);
			if(errorCode >= 0)
			{
				errorCode = ll_add(pArrayListEmployee, employee);
				if(errorCode == 0)
				{
					errorCode = id;
				}
			}
		}
	}
	else
	{
		errorCode = -1;
	}
	return errorCode;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int errorCode = -1;
	int id;

	Employee *employee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		employee = employee_new();
		fread(employee, sizeof(Employee),1,pFile);
		errorCode=employee_getId(employee, &id);
		if(id > 0)
		{
			errorCode = ll_add(pArrayListEmployee, employee);
			if(errorCode == 0)
			{
				errorCode = id;
			}
		}
	}
	return errorCode;
}
