/*
 * myFunc.c
 *
 *  Created on: Sep 10, 2021
 *      Author: JS
 */

#include "myFunc.h"
//FLOAT FUNCTIONS
int getMyFloat(float* number)
{
	int errorCode;
	float buffer;
	if(scanf("%f",&buffer)==1)//intento guardar un float si no puedo devuelvo un -1
	{
		*number = buffer;
		errorCode=0;
	}
	else
	{
		errorCode=-1;
	}
	return errorCode;
}

int getMyInt(int* number)//intento guardar un int si no puedo devuelvo un -1
{
	int errorCode;
	int buffer;
	if(scanf("%d",&buffer)==1)
	{
		*number = buffer;
		errorCode=0;
	}
	else
	{
		errorCode=-1;
	}
	return errorCode;
}


int myFloatCalculator(float numA, float numB, char operation, float* result) //intento hacer cuentas basicas
{
	int errorCode = 0;
	switch(operation)
	{
		case '+':
			*result = numA + numB;
			break;
		case '-':
			*result = numA - numB;
			break;
		case '*':
			*result = numA * numB;
			break;
		case '/':
			if(numB)
			{
				*result = numA / numB;
			}
			else
			{
				errorCode=-1;
			}
			break;
	}
	return errorCode;

}



//INT FUNCTIONS
int calcMyFactorial(int number,int* result)//calculo un factorial del numero dado
{
	int factorial = 1;
	int i;
	for(i = number; i > 1; i--)
	{
		factorial = factorial * i;
	}
	*result = factorial;

	return 0;
}

int getMyOperation(int* operation)
{
	int errorCode = 0;
	char buffer;

	fflush(stdin);
	if(scanf("%c",&buffer)==1)//tomo el valor como char, pero lo trabajo como un int a niveles de punteros
	{
		*operation = buffer;
		//printf("%c",operation);
		if(*operation != '+' && *operation != '-' && *operation != '*' && *operation != '/' && *operation != '!'&& *operation != 'C')
		{
			errorCode=-1;
		}
	}
	else
	{
		errorCode=-1;
	}

	return errorCode;
}
