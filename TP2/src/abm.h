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

void initEmployees(Employee*, int);
void showMyMenu();
void showModify();
void showInfo();
void showSort();
void printEmployees(Employee*, int);
void printEmployee(Employee*, int, int);
int swapEmployee(Employee*, int, int);
int addEmployee(Employee*, int, int, char* ,char* ,float ,int );
int protectedAdd(Employee*, int);
int modifyEmployee(Employee*, int, int);
int protectedModify(Employee*,int);
int removeEmployee(Employee*, int, int);
int protectedDelete(Employee*, int);
int sortAscending(Employee* , int );
int sortDescending(Employee* , int );
int sortEmployees(Employee*, int, int);
int promSalary(Employee* , int);
int protectedInfo(Employee*, int);
int findEmployeeById(Employee*, int,int);
int findEmpty(Employee*, int);

#endif /* ABM_H_ */
