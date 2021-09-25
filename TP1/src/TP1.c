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
#include "calcTP.h"			//Calculadora del TP
#define MODE 0				//Modo de la calculadora 2 es basica 1 es clasica 0 es para el TP

int main(void)
{
	setbuf(stdout,NULL);
	int modo = MODE;
	int option = 0;
	float numA = 0;
	float numB = 0;
	float opResults[4] = {0,0,0,0};
	int	factResults[2] = {0,0};
	int couldDivide;
	int couldFactorial[2];
	int gotNum[2];
	int gotCalc;

	/**
	 * Este codigo permite 3 modos de usar la calculadora. Mantener MODE en 0 para poder usar el modo TP
	 *
	 * En modo TP se desplegara un menu permitiendo elegir la opcion
	 * Opcion 0> Ingresar opcion
	 * Opcion 1> Ingresar el primer numero
	 * Opcion 2> Ingresar segundo numero
	 * Opcion 3> Intentar calcular, fallara si no estan agregados ambos numeros
	 * Opcion 4> Mostrar todos los valores caclulados. Todas las operaciones estan Inicializadas en 0, Si no se apreto la opcion
	 * 3 todos los valores entregaran 0
	 * Opcion 5> Salir
	 */
	if(!modo)
	{
		//Codigo del tp base
		do
		{
			showMyMenu();//Mostrar Mi menu
			fflush(stdin);
			switch(option)
			{
				case 0:
					scanf("%d",&option);
					break;
				case 1:
					printf("\nIngrese Numero 1:\n");
					gotNum[0]=getMyFloat(&numA);
					option = 0;
					break;
				case 2:
					printf("\nIngrese Numero 2:\n");
					gotNum[1]=getMyFloat(&numB);
					option = 0;
					break;
				case 3:
					showMyOperations();//Muestra los calculos que se van a hacer
					if(gotNum[0]==0 && gotNum[1]==0)
					{
						myFloatCalculator(numA,numB,'+',&(opResults[0]));
						myFloatCalculator(numA,numB,'-',&(opResults[1]));
						myFloatCalculator(numA,numB,'*',&(opResults[2]));
						couldDivide = myFloatCalculator(numA,numB,'/',&opResults[3]);
						couldFactorial[0] = calcMyFactorial((int)numA, &factResults[0]);
						couldFactorial[1] = calcMyFactorial((int)numB, &factResults[1]);
						gotCalc = 0;
					}
					else
					{
						printf("Faltan Ingresar Datos\n");
					}
					option = 0;
					break;
				case 4:
					if(gotCalc == 0)
					{
						showMyResults(numA,numB,opResults,couldDivide,factResults,couldFactorial);//Funcion que quita peso visual en el main
					}
					else
					{
						printf("Falto calcular\n");
					}
					option = 0;
					break;
				default:
					option = 0;
			}
		}while(option != 5);
		printf("Adios!");
	}
	else
	{
		/*
		 * Vamos a comentarlo por si acaso
		//codigo preparado para incluir en un Arduino dadas ligeras modificaciones
		//utilizamos maquinas de estado y diagramas de flujo para optimizarlo
		while(1)
		{
			if(modo-1)
			{
				essentials();	//calculadora basica
			}
			else
			{
				classic();		//calculadora clasica
			}
		}
		*/
	}

}
