/*
 * error.c
 *
 *  Created on: Nov 12, 2021
 *      Author: JS
 */

#include "error.h"

void showError(int number)
{
	switch(number)
	{
	case 1:
		printf("\nVARIABLE ASSIGNMENT ERROR\n");
		break;
	case 2:
		printf("\nFILE MANAGMENT ERROR\n");
		break;
	case 3:
		printf("\nPOINTER ASSIGNMENT ERROR\n");
		break;
	case 4:
		printf("\n DATA FIND ERROR\n");
		break;


	}



}
