/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"
#include "error.h"

int main(void)
{
	/*
	startTesting(1);  // ll_newLinkedList //LISTO
	startTesting(2);  // ll_len //LISTO
	startTesting(3);  // getNode - test_getNode //LISTO
	startTesting(4);  // addNode - test_addNode //LISTO
	startTesting(5);  // ll_add //LISTO
	startTesting(6);  // ll_get //LISTO
	startTesting(7);  // ll_set //LISTO
	startTesting(8);  // ll_remove //LISTO
	startTesting(9);  // ll_clear //LISTO
	startTesting(10); // ll_deleteLinkedList //LISTO
	startTesting(11); // ll_indexOf //LISTO
	startTesting(12); // ll_isEmpty //LISTO
	startTesting(13); // ll_push //LISTO
	startTesting(14); // ll_pop //LISTO
	startTesting(15); // ll_contains //LISTO
	startTesting(16); // ll_containsAll //LISTO
	startTesting(17); // ll_subList //LISTO
	startTesting(18); // ll_clone //LISTO
	startTesting(19); // ll_sort //LISTO
*/
	setbuf(stdout,NULL);


    int option;
    int currentID;
    char url[50];
    int errorCode;



    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaSorted = ll_newLinkedList();
	do{
		   showMenu();
		   getMyOption(&option);
	       switch(option)
	       {
	       	   case 1:
	       		   printf("Ingrese URL a abrir en modo texto(tiene que aclarar la extencion): ");
	       		   errorCode = myGets(url, sizeof(url));
	       		   if(errorCode == 0)
	       		   {
	       			   currentID = controller_loadFromText(url , listaEmpleados);
	        		   if(currentID == -1)
	        		   {
	        			   ERROR(2);
	        		   }
	       		   }
	       		   else
	       		   {
	       			   ERROR(1);
	       		   }
	               break;
	           case 2:
	        	   printf("Ingrese URL a abrir en modo binario(tiene que aclarar la extencion): ");
	        	   errorCode = myGets(url, sizeof(url));
	        	   if(errorCode == 0)
	        	   {
	        		   currentID = controller_loadFromBinary("prueba.bin", listaEmpleados);
	        		   if(currentID == -1)
	        		   {
	        			   ERROR(2);
	        		   }
	        	   }
	        	   else
	        	   {
	       			   ERROR(1);
	        	   }
	        	   break;
	           case 3:
	        	   printf("Va a agregar un nuevo usuario. \n");
	        	   errorCode = controller_addEmployee(listaEmpleados, currentID);
	        	   if(errorCode != 0)
	        	   {
	        		   ERROR(3);
	        	   }
	        	   break;
	           case 4:
	        	   printf("Va a modificar un usuario completo. \n");
	        	   errorCode = controller_editEmployee(listaEmpleados);
	        	   if(errorCode != 0)
	        	   {
	        		   ERROR(4);
	        	   }
	        	   break;
	           case 5:
	        	   printf("Va a eliminar un usuario completo. \n");
	        	   errorCode = controller_removeEmployee(listaEmpleados);
	        	   if(errorCode != 0)
	        	   {
	        		   ERROR(4);
	        	   }
	        	   break;
	           case 6:
	        	   controller_ListEmployee(listaEmpleados);
	        	   break;
	           case 7:
	        	   printf("Desea guardar la lista ordenada en una copia y luego mostrarla o desea afectar la original? (1Copia/2Original)");
	        	   getMyOption(&option);
	        	   switch(option)
	        	   {
	        	   	   case 1:
	        	   		   listaSorted = ll_clone(listaEmpleados);
	        	   		   controller_sortEmployee(listaSorted);
	        	   		   controller_ListEmployee(listaSorted);
	        	   		   break;
	        	   	   case 2:
	    	        	   controller_sortEmployee(listaEmpleados);
	    	        	   break;
	        	   }
	        	   break;
	           case 8:
	       		   printf("Ingrese URL a guardar en modo texto(tiene que aclarar la extencion): ");
	       		   errorCode = myGets(url, sizeof(url));
	       		   if(errorCode == 0)
	       		   {
	       			   errorCode = controller_saveAsText(url , listaEmpleados);
	       			   if(errorCode != 0)
	       			   {
	       				   ERROR(2);
	       			   }
	       		   }
	       		   else
	       		   {
	       			   ERROR(1);
	       		   }
	        	   break;
	           case 9:
	       		   printf("Ingrese URL a guardar en modo ninario(tiene que aclarar la extencion): ");
	       		   errorCode = myGets(url, sizeof(url));
	       		   if(errorCode == 0)
	       		   {
	       			   errorCode = controller_saveAsBinary(url , listaEmpleados);
	       			   if(errorCode != 0)
	       			   {
	       				   ERROR(2);
	       			   }
	       		   }
	       		   else
	       		   {
	       			   ERROR(1);
	       		   }
	        	   break;
	           case 10:
	        	   ll_clear(listaEmpleados);
	        	   ll_deleteLinkedList(listaEmpleados);
	        	   printf("Adios!");
	        }
	    }while(option != 10);
    return 0;
}

































