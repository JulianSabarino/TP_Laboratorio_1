/*
 * calcTP.c
 *
 *  Created on: Sep 16, 2021
 *      Author: JS
 */


#include "calcTP.h"

void showMyMenu()
{
	/*
	2. Ingresar 2do operando (B=y)
	3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
	4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir
	*/
	printf("1. Ingresar 1er operando\n");
	printf("2. Ingresar 2do operando\n");
	printf("3. Mostrar las operaciones y Calcularlas\n");
	printf("4. Informar resultados Calculados\n");
	printf("5. Salir\n");
}

void showMyOperations()
{
	printf("Calcular todas las operaciones\n");
	printf("\ta.Calcular la suma (A+B)\n");
	printf("\tb.Calcular la resta (A-B)\n");
	printf("\tc.Calcular la division (A/B)\n");
	printf("\td.Calcular la multiplicacion (A*B)\n");
	printf("\te.Calcular el factorial (A!)\n");
}

void showMyResults(float numA,float numB,float* opResults,int couldDivide,int* factResults,int* couldFactorial)
{
	printf("El resultado de %.2f + %.2f es: %.2f\n",numA,numB,opResults[0]);
	printf("El resultado de %.2f - %.2f es: %.2f\n",numA,numB,opResults[1]);
	printf("El resultado de %.2f * %.2f es: %.2f\n",numA,numB,opResults[2]);

	if(couldDivide)
	{
		printf("No se puede dividir por 0\n");
	}
	else
	{
		printf("El resultado de %.2f / %.2f es: %.2f\n",numA,numB,opResults[3]);
	}

	if(couldFactorial[0])
	{
		printf("No se pudo hacer el factorial de %.2f\n",numA);
	}
	else
	{
		printf("El facorial de la parte entera de %.2f es: %d\n",numA,factResults[0]);
	}
	if(couldFactorial[0])
	{
		printf("No se pudo hacer el factorial de %.2f\n",numB);
	}
	else
	{
		printf("El facorial de la parte entera de %.2f es: %d\n",numB,factResults[1]);
	}

}
