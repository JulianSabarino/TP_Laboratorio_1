/*
 * myFunc.h
 *
 *  Created on: Sep 10, 2021
 *      Author: JS
 */

#ifndef MYFUNC_H_
#define MYFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNum(char*);
int myGets(char* , int);

//FLOAT FUNCTIONS
int getMyFloat(float* );
int myFloatCalculator(float , float , char , float* );


//INT FUNCTIONS
int getMyInt(int* );
int calcMyFactorial(int ,int* );
int getMyOperation(int* );

#endif /* MYFUNC_H_ */
