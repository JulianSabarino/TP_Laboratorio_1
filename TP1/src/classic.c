/*
 * classic.c
 *
 *  Created on: Sep 12, 2021
 *      Author: JS
 */


#include "classic.h"
#include "myFunc.h"

void classic()
{
	static int estado = DATOA;

		static float	numA;	//numero 1 y 2 que se mantienen a lo largo de los estados
		static float	numB;
		static float	result;
		static int		operation;//operacion que se mantiene a lo largo de los estados

		static int		errorCode = 0;

		int resultInt;

		switch(estado)
		{
			case DATOA:
				printf("Ingrese NumA: \n");
				errorCode = errorCode + getMyFloat(&numA); // tomo numero 1, si es invalido errorCode deja de ser 0
				estado = OPERATION; //voy a estado tomar operacion
				break;
			case OPERATION:
				printf("Ingrese Operacion(+ - * / ! C): \n");
				errorCode = errorCode + getMyOperation(&operation); // tomo la operacion, si es invalido errorCode deja de ser 0
				// se agrega la operacion C que es para empezar desde Cero
				switch(operation)
				{
					case '!':
						estado = FACTORIAL;	//no necesito tomar dato 2, voy a calcular factorial
						break;
					case 'C':
						estado = DATOA;		//empiezo de cero
						errorCode = 0;
						break;
					default:
						estado = DATOB;		//ccualquier otro valor voy a tomar numero 2
				}
				break;
			case DATOB:
				printf("Ingrese NumB: \n");
				errorCode = errorCode + getMyFloat(&numB); // tomo numero 2, si es invalido errorCode deja de ser 0
				estado = CALCDATA; //Voy a intentar calcular
				break;

			case CALCDATA:
				if(errorCode)
				{
					printf("SYNTAX ERROR \n"); // si errorCode no es 0 (pusieron un dato invalido) imprimo que pusieron mal la sintaxus
					estado = DATOA; //vuelvo al principio y reseteo el contador de errores
					errorCode = 0;
				}
				else
				{
					errorCode = myFloatCalculator(numA,numB,(char)operation,&result);//aca intento calcular la operacion elegida
					if(errorCode)
					{
						printf("MATH ERROR \n"); //si no puedo (por ejemplo dividir por 0) me toma como math error
						estado = DATOA; //vuelvo al principio y reseteo el contador de errores
						errorCode = 0;
					}
					else
					{
						printf("%.2f %c %.2f = %.2f \n",numA,operation,numB,result);//si pude calcularlo lo imprimo
						numA = result;//acumulo el valor como la calculadora de windows
						estado = OPERATION;//vuelvo para hacer otra operacion
					}

				}

				break;
			case FACTORIAL:
				calcMyFactorial(numA,&resultInt);//calculo el facorial y lo acunulo para seguir calculando
				printf("El factorial de la parte entera de %.2f es %d \n",numA,resultInt);
				numA = resultInt;
				estado = OPERATION;
				break;
		}


}
