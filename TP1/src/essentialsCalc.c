/*
 * essentialsCalc.c
 *
 *  Created on: Sep 10, 2021
 *      Author: JS
 */

#include "essentialsCalc.h"
#include "myFunc.h"			//funciones bascias que incluyo en los programas importantes

void essentials()
{
	static int estado = DATOA;	//inicializo el primer estado como tomar numero 1

	static float	numA;		//mantengo los numeros a lo largo de la ejecuccion
	static float	numB;
	float	operation;			//donde guardo el resultado

	int		errorCode = 0;		//para fijarme que los numeros sean validos
	int		operationINT;		//resultado para facorial(se necesita un entero)

	switch(estado)
	{
		case DATOA:	//estado tomo numero 1
			do
			{
				printf("Ingrese NumA: \n");
				errorCode = getMyFloat(&numA);
			}while(errorCode != 0);	//escribo mi float hasta que sea un valor valido
			estado = DATOB;			//paso al estado de tomar numero 2
			break;
		case DATOB:	//estado tomo numero 2
			do
			{
				printf("Ingrese NumB: \n");
				errorCode = getMyFloat(&numB);
			}while(errorCode != 0);	//escribo mi float hasta que sea un valor valido
			estado = PRINTABD;		//paso al estado de impresion de calculos
			break;
		case PRINTABD:
			myFloatCalculator(numA,numB,'+',&operation);		//calculo e imprimo +
			printf("%.2f + %.2f = %.2f \n",numA,numB,operation);

			myFloatCalculator(numA,numB,'-',&operation);		//calculo e imprimo -
			printf("%.2f - %.2f = %.2f \n",numA,numB,operation);

			myFloatCalculator(numA,numB,'*',&operation);		//calculo e imprimo *
			printf("%.2f * %.2f = %.2f \n",numA,numB,operation);

			if(myFloatCalculator(numA,numB,'/',&operation))		//intento dividir
			{
				printf("No se puede dividir por 0 \n");			//si devolvio -1 no pudo dividir
			}
			else
			{
				printf("%.2f / %.2f = %.2f \n",numA,numB,operation); // si devolvio 0 puedo dividir e imprimo
			}

			errorCode = calcMyFactorial((int)numA,&operationINT);	//hago el factorial de la parte entera
			printf("El factorial de la parte entera de %.2f es %d \n",numA,operationINT);
			estado = DATOA;	//vuelvo al estado para tomar el primer dato
	}

}
