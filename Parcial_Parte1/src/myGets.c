/*
 * myGets.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */


#include "myGets.h"

int myGets(char* charChain, int size)
{
	int errorCode = -1;
	fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
	if(charChain != NULL && size >0 && fgets(charChain,size,stdin)==charChain)
	{
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
	int errorCode;
	char buffer[64];
	errorCode = myGets(buffer, sizeof(buffer));
	if(errorCode == 0)
	{
		if(isNum(buffer)==0)
		{
			*number = atoi(buffer);
		}
		else
		{
			errorCode = -1;
		}
	}
	return errorCode;
}

int getMyFloat(float* number)
{
	int errorCode;
	char buffer[64];
	errorCode = myGets(buffer, sizeof(buffer));
	if(errorCode == 0)
		{
			if(isFloat(buffer)==0)
			{
				*number = atof(buffer);
			}
			else
			{
				errorCode = -1;
			}
		}
	return errorCode;
}


int isNum(char* charChain)
{
	int i=0;
	int errorCode = 0;
	if(charChain != NULL && strlen(charChain) > 0)
	{
		while(charChain[i] != '\0')
		{
			if(i == 0)
			{
				if((charChain[i] < '0' || charChain[i] > '9') && charChain[i] != '-')//el primer digito no es - o numerico
				{
					errorCode = -1;
					break;
				}
			}
			else
			{
				if(charChain[i] < '0' || charChain[i] > '9' )
				{
					errorCode = -1;
					break;
				}
			}
			i++;
		}
	}
	return errorCode;
}

int isFloat(char* charChain)
{
	int i;
	int countSigno = 0;
	int errorCode = 0;

	if(strlen(charChain) > 0)
	{
		for (i = 0; i < strlen(charChain); i++)
		{
			if(i==0)
			{
				if((charChain[i] < '0' || charChain[i] > '9') && charChain[i] != '-')//el primer digito no es - o numerico
				{
					errorCode = -1;
					break;
				}
			}
			else
			{
				if(charChain[i] == '.' || charChain[i] == ',')
				{
					countSigno++;
				}
				else
				{
					if(charChain[i] < '0' || charChain[i] > '9')//el primer digito no es - o numerico
					{
						errorCode = -1;
						break;
					}
				}
			}
		}
		if(countSigno > 1)
		{
			errorCode = -1;
		}
	}

	return errorCode;
}

int isAlph(char* charChain)
{
	int i=0;
	int errorCode = 0;
	if(charChain != NULL && strlen(charChain) > 0)
	{
		while(charChain[i] != '\0')
		{
			if(charAlpha(charChain[i])!=0)
			{
				errorCode = -1;
				break;
			}
			i++;
		}
	}
	return errorCode;
}

int charAlpha(char letter)
{
	int errorCode = -1;

	if((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
	{
		errorCode = 0;
	}

	return errorCode;
}
