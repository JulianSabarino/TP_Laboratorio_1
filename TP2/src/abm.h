/*
 * abm.h
 *
 *  Created on: Oct 5, 2021
 *      Author: JS
 */

#ifndef ABM_H_
#define ABM_H_

#include "myFunc.h"

struct Employee
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
};

typedef struct Employee Employee;

void showMyMenu();//Imprime el menu principal
void showModify();//imprime el submenu para modificar y los empleados
void showInfo();//imprime el submenu para hacer informes
void showSort();//imprime el sub sub menu para el orden de los informes

void printEmployee(Employee*, int, int); //imprime los datos de un empleado separados por un tab
void printEmployees(Employee*, int);//imprime todos los empleados

void initEmployees(Employee*, int);//inicializa el struct empleados con un 1 en is empty

int addEmployee(Employee*, int, int, char* ,char* ,float ,int ); //funcion base de agregar empleados
int protectedAdd(Employee*, int);//funcion donde yo pido y corroboro los datos para agregar empleados

int modifyEmployee(Employee*,int,  int, int); //funcion base para modificar empleados
int protectedModify(Employee*,int);//funcion donde pido y corroboro los datos para modificar empleados

int removeEmployee(Employee*, int, int); //funcion base para eliminar empleados
int protectedDelete(Employee*, int); //funcion donde pido y corroboro el id del empleado a eliminar

int swapEmployee(Employee*,int, int, int); //funcion para swapear dos posiciones de un struct miembro a miembro

int sortAscending(Employee* , int ); //funcion de ordenar ascendente
int sortDescending(Employee* , int );//funcion de ordenar descendente
int sortEmployees(Employee*, int, int);//funcion donde pido y corroboro tipo de ordenamiento

int promSalary(Employee* , int); //funcion donde busco el promedio del salario y cantidad de personas que superan la media

int protectedInfo(Employee*, int); //funcion base donde voy a pedir el tipo de informe

int findEmployeeById(Employee*, int,int); //busca un empleado por id y devuelve la posicion o -1 si no existe
int findEmpty(Employee*, int); //busca el vacio mas proximo en orden y devuelve la posicion o -1 si no hay vacio

#endif /* ABM_H_ */
