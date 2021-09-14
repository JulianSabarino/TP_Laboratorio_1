/*
 ============================================================================
 Name        : TP1.c
 Author      : Julian Sabarino
 Version     :
 Copyright   : 9/8/2021
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "essentialsCalc.h"	//Calucladora basica que pide el enunciado
#include "classic.h"		//Calculadora clasica que permite acumulacion (una version reducida de windows)

#define MODE 1				//Modo de la calculadora 1 es basica 0 es clasica

int main(void)
{
	setbuf(stdout,NULL);
	//codigo preparado para incluir en un Arduino dadas ligeras modificaciones
	//utilizamos maquinas de estado y diagramas de flujo para optimizarlo
	while(1)
	{
		if(MODE)
		{
			essentials();	//calculadora basica
		}
		else
		{
			classic();		//calculadora clasica
		}
	}


}
