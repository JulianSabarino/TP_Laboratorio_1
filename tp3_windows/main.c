#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "menus.h"
#include "error.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). //LISTO
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado //LISTO
     4. Modificar datos de empleado//LISTO
     5. Baja de empleado//LISTO
     6. Listar empleados//LISTO
     7. Ordenar empleados//LISTO
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).//LISTO
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir//LISTO
*****************************************************/



int main()
{

	setbuf(stdout,NULL);


    int option;
    int currentID;
    char url[50];
    int errorCode;



    LinkedList* listaEmpleados = ll_newLinkedList();
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
        	   controller_sortEmployee(listaEmpleados);
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

