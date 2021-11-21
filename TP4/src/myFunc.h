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

int myGets(char* , int); //recibe un string y le saca el \n del final
int getMyInt(int* ); //recibe un string y si es entero lo convierte a entero, positivo o negativo dependiendo
int getMyFloat(float* );//recibe un string si es float lo vonvierte a float, positivo o negativo dependiendo

int isNum(char*); // checkea que un string sea entero
int isFloat(char*); // checkea que un string sea float
int isAlph(char*); //checkea que un string solo tenga letras
int charAlpha(char);//checkea que un caracter sea una letra
//FLOAT FUNCTIONS


//INT FUNCTIONS


#endif /* MYFUNC_H_ */
