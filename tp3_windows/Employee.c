#include "Employee.h"
#include "LinkedList.h"
int employee_setId(Employee* this,int id)
{
	int errorCode = -1;
	if(this != NULL)
	{
		this->id = id;
		errorCode = 0;
	}
	return errorCode;
}
int employee_getId(Employee* this,int* id)
{
	int errorCode = -1;
	if(this != NULL)
	{
		*id = this->id;
		errorCode = 0;
	}
	return errorCode;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int errorCode = -1;
	if(this != NULL)
	{
		strncpy(this->nombre, nombre, 128);
		errorCode = 0;
	}
	return errorCode;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int errorCode = -1;
	if(this != NULL)
	{
		strncpy(nombre,this->nombre, 128);
		errorCode = 0;
	}
	return errorCode;
}

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




