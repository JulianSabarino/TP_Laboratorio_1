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
	fflush(stdin);
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

/*
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
*/
/*
int getMyFloat(int* number)
{
	int errorCode=-1;
	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	if(isNum(buffer))
	{
		*number = atof(buffer);
		errorCode = 0;
	}
	return errorCode;
}
*/

int myGets(char* charChain, int size)
{
	int errorCode = -1;
	if(charChain != NULL && size >0 && fgets(charChain,size,stdin)==charChain)
	{
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if(charChain[strlen(charChain)-1] == '\n')
		{
			charChain[strlen(charChain)-1] = '\0';
		}
		errorCode = 0;
	}
	return errorCode;
}



int getMyInt(int* number)
{
	int errorCode=-1;
	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	//puts(buffer);
	if(isNum(buffer)==0)
	{
		*number = atoi(buffer);
		errorCode = 0;
	}
	return errorCode;
}

int isNum(char* charChain)
{
	int i=0;
	int errorCode = -1;
	if(charChain != NULL && strlen(charChain) > 0)
	{
		while(charChain[i] != '\0')
		{
			if(charChain[i] < '0' || charChain[i] > '9' )
			{
				errorCode = 0;
				break;
			}
			i++;
		}
	}
	return errorCode;
}


/*
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

*/
/*
//INT FUNCTIONS
int calcMyFactorial(int number,int* result)//calculo un factorial del numero dado
{
	int factorial = 1;
	int i;
	int errorCode = -1;
	if(number > 0){
		for(i = number; i > 1; i--)
		{
			factorial = factorial * i;
		}
		*result = factorial;
		errorCode = 0;
	}
	return errorCode;
}
*/

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
