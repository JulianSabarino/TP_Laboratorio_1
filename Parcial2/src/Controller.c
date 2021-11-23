#include <stdio.h>
#include <stdlib.h>
#include "lList.h"
#include "arcade.h"
#include "saloon.h"
#include "Controller.h"
#include "myFunc.h"
#include "menus.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

static Arcade* controller_findArcade(LinkedList* this, int id);
static Saloon* controller_findArcadeSaloon(LinkedList* this, int id);

/** \brief cargar desde Texto
 *
 * \param path char*
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \llama a parserText para poder crear la LL
 */


int controller_loadFromText(char* path , LinkedList* this)
{
	int errorCode = 0;

	FILE *fp = fopen(path,"r");
	if(fp != NULL)
	{
		errorCode = ll_parserText(fp , this);
	}
	else
	{
		errorCode = -1;
	}

    return errorCode;
}

/** \brief Crear Lista de Salones
 *
 * \param this LinkedList*
 * \return int 0 si pudo crear la ll, -1 si no, -2 si pudo crearla pero no rellenarla
 * \a;ade un salon a la lista
 */

int controller_addSaloon(LinkedList* this)
{
	int errorCode = -1;
	char saloonName[51];
	Saloon* saloon;
	LinkedList* pFirstArcade;

	if(this != NULL)
	{
		printf("Ingrese Nombre de nuevo Salon: ");
		myGets(saloonName, sizeof(saloonName));

		errorCode = controller_findIndexOf(this, saloonName);

		if(errorCode == -2)
		{
			saloon = saloon_new();
			if(saloon != NULL)
			{
				pFirstArcade = ll_newLinkedList();
				saloon->pFirstArcade = pFirstArcade;

				saloon_setName(saloon, saloonName);
				ll_add(this, saloon);
			}
			errorCode = 0;
		}
		else
		{
			errorCode = -2;
		}
	}
	return errorCode;
}

/** \brief Buscar salon por Nombre
 *
 * \param name char*
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no, -2 si no pudo encontrarla.
 * \busca y devuelve la index de un salon por nombre
 */

int controller_findIndexOf(LinkedList* this, char* saloonName)
{
	int i;
	int errorCode = -1;
	Saloon* saloon;
	char tempSaloonName[51];
	if(this != NULL)
	{
		errorCode = -2;
		for(i = 0; i < ll_len(this);i++)
		{
		//rintf("%d",findFlag);
			saloon = (Saloon*)ll_get(this, i);
			if(saloon != NULL)
			{
				saloon_getName(saloon, tempSaloonName);
				//printf("%s,%s\n",saloonName, tempSaloonName);
				if(strncmp(saloonName,tempSaloonName,51)==0)
				{
					errorCode = i;
					break;
				}
			}
		}
	}
	return errorCode;
}

/** \brief cargar Arcade
 *
 * \param currentID int
 * \param this LinkedList*
 * \return devuelve el nuevo currentID o -1 si no agrego
 * \agrega a la lista de arcades de un salon un nuevo arcade
 */

int controller_addArcade(LinkedList* this, int currentID)
{
	int errorCode = -1;
	char saloonName[51];
	Arcade* arcade;
	Saloon* saloon;
	LinkedList* pFirstArcade;

	if(this != NULL)
	{
		printf("Ingrese Nombre de Salon al Agregar Arcade: ");
		myGets(saloonName, sizeof(saloonName));

		errorCode = controller_findIndexOf(this, saloonName);

		if(errorCode >= 0)
		{
			saloon =(Saloon*)ll_get(this, errorCode);
			arcade = arcade_newParameters(currentID);
			if(arcade != NULL && saloon!= NULL)
			{
				pFirstArcade = saloon->pFirstArcade;
				ll_add(pFirstArcade, arcade);
				errorCode = currentID + 1;
			}
			else
			{
				errorCode = -1;
			}
		}
		else
		{
			errorCode = -2;
		}
	}
	return errorCode;


}

/** \brief buscar arcade por id
 *
 * \param id int
 * \param this LinkedList*
 * \return puntero a arcade
 * \busca la direccion de un arcade en las listas
 */

Arcade* controller_findArcade(LinkedList* this, int id)
{
	Arcade* arcade = NULL;
	int i;
	int j;
	Saloon* saloon;
	LinkedList* thisArcade;
	int currentId;
	int find;
	if(this != NULL)
	{
		//printf("\nEntre\n");
		for(i = 0; i < ll_len(this);i++)
		{
			find = 0;
			//rintf("%d",findFlag);
			saloon = (Saloon*)ll_get(this, i);
			if(saloon != NULL)
			{
				thisArcade = saloon->pFirstArcade;
				if(thisArcade != NULL)
				{
					for(j = 0; j < ll_len(thisArcade);j++)
					{
						arcade = (Arcade*)ll_get(thisArcade, j);
						if(arcade!=NULL)
						{
							arcade_getId(arcade, &currentId);
							if(currentId == id)
							{
								find = 1;
								break;
							}
						}
					}
				}
			}

			if(find == 1)
			{
				break;
			}
		}
	}
	return arcade;
}

/** \brief encontrar salon de un arcade
 *
 * \param int id
 * \param this LinkedList*
 * \return saloon
 * devuelve el puntero al salon que tiene un arcade especifico
 */

Saloon* controller_findArcadeSaloon(LinkedList* this, int id)
{
	Arcade* arcade;
	int i;
	int j;
	Saloon* saloon = NULL;
	LinkedList* thisArcade;
	int currentId;
	int find;
	if(this != NULL)
	{
		//printf("\nEntre\n");
		for(i = 0; i < ll_len(this);i++)
		{
			find = 0;
			//rintf("%d",findFlag);
			saloon = (Saloon*)ll_get(this, i);
			if(saloon != NULL)
			{
				thisArcade = saloon->pFirstArcade;
				if(thisArcade != NULL)
				{
					for(j = 0; j < ll_len(thisArcade);j++)
					{
						arcade = (Arcade*)ll_get(thisArcade, j);
						if(arcade!=NULL)
						{
							arcade_getId(arcade, &currentId);
							if(currentId == id)
							{
								find = 1;
								break;
							}
						}
					}
				}
			}

			if(find == 1)
			{
				break;
			}
		}
	}
	return saloon;
}

/** \brief modificar arcade
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \Intenta modificar un arcade dada una id
 */

int controller_modifyArcade(LinkedList* this)
{
	int errorCode = -1;
	int id;
	Arcade* arcade;

	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	int option;
	if(this != NULL)
	{
		printf("Ingrese ID de Arcade:");
		errorCode = getMyInt(&id);
		if(errorCode == 0)
		{
			arcade = controller_findArcade(this, id);
			if(arcade != NULL)
			{
				printf("Ingrese lo que quiere modificar Jugadores (1)/ Nombre (2):");
				getMyOption(&option);
				arcade_getAll(arcade, &id, gameName, nation, soundType, &cantPlayers, &maxToken);
				switch(option)
				{
					case 1:
						printf("Ingrese Cantidad de Jugadores: ");
						errorCode = errorCode + getMyInt(&cantPlayers);
						if(cantPlayers<1)
						{
							cantPlayers = 1;
						}
						break;
					case 2:
						printf("Ingrese Nombre: ");
						errorCode = errorCode + myGets(gameName, sizeof(gameName));
						break;
					default:
						errorCode = -1;
				}
				if(errorCode == 0 )
				{
					arcade_setAll(arcade, id, gameName, nation, soundType, cantPlayers, maxToken);
				}
			}

		}
	}
	return errorCode;
}

/** \brief eliminar arcade
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \borra un arcade
 */

int controller_deleteArcade(LinkedList* this)
{
	int errorCode = -1;
	int id;
	Arcade* arcade;
	Saloon* saloon;
	LinkedList* pArcade;
	int indexOf;

	if(this != NULL)
	{
		printf("Ingrese ID de Arcade:");
		errorCode = getMyInt(&id);
		if(errorCode == 0)
		{
			arcade = controller_findArcade(this, id);
			saloon = controller_findArcadeSaloon(this, id);
			if(arcade != NULL && saloon != NULL)
			{
				pArcade = saloon->pFirstArcade;
				indexOf = ll_indexOf(pArcade, arcade);
				errorCode = ll_remove(pArcade, indexOf);
			}

		}
	}
	return errorCode;

}
/** \brief borrar salon
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \borra un salon y todos los arcades cargados de el
 */
int controller_deleteSaloon(LinkedList* this)
{
	int errorCode = -1;
	char saloonName[51];
	Saloon* saloon;
	LinkedList* pFirstArcade;

	if(this != NULL)
	{
		printf("Ingrese nombre de Salon a Eliminar: ");
		myGets(saloonName, sizeof(saloonName));

		errorCode = controller_findIndexOf(this, saloonName);

		if(errorCode >= 0)
		{
			saloon = ll_get(this, errorCode);
			if(saloon != NULL)
			{
				pFirstArcade = saloon->pFirstArcade;
				ll_deleteLinkedList(pFirstArcade);
				ll_remove(this, errorCode);
			}
			errorCode = 0;
		}
		else
		{
			errorCode = -1;
		}
	}
	return errorCode;
}

/** \brief Listar salones
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \lista todos los arcades de un salon y los agrupa por salon
 */
int controller_ListSaloon(LinkedList* this)
{
	int errorCode = -1;
	Node* tempList = this->pFirstNode;

	char nombre[51];
	Saloon* saloon;

	//printf("ID | NOMBRE | HORAS | SUELDO \n");
	while(tempList!=NULL)
		{
			saloon = (Saloon*)tempList->pElement;
			saloon_getName(saloon, nombre);
			printf("\nSALON:%s\n",nombre);
			controller_ListArcade(saloon->pFirstArcade);
			tempList = tempList->pNextNode;
		}


    return errorCode;
}

/** \brief listar Arcade
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \Lista todos los arcades de un Salon especifico
 */

int controller_ListArcade(LinkedList* this)
{
	int errorCode = -1;
	Node* tempList = this->pFirstNode;

	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;

	Arcade* arcade;

	printf("ID | NOMBRE | NACIONALIDAD | SONIDO | JUGADORES | TOKENS \n");
	while(tempList!=NULL)
		{
			arcade =(Arcade*)tempList->pElement;
			arcade_getAll(arcade, &id, gameName, nation, soundType, &cantPlayers, &maxToken);
			printf("%d|%s|%s|%s|%d|%d\n",id,gameName,nation,soundType,cantPlayers,maxToken);

			tempList = tempList->pNextNode;
		}


    return errorCode;
}

/** \brief parser Text
 *
 * \param path FILE*
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \crea una linked list de salones y a cada salon le crea una linked list con los arcades que posee
 */

int ll_parserText(FILE* fp , LinkedList* this)
{
	char buffer[128];
	int read;
	int errorCode = 0;
	int findFlag;
	int i;

	int id;
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonName[51];
	char gameName[63];

	LinkedList* pFirstArcade;
	Saloon*saloon;
	Arcade* arcade;

	char tempSaloonName[51];

	fgets(buffer, sizeof(buffer),fp);
	//printf("%s",buffer);
	while(!feof(fp))
	{
		//saloon= saloon_new();
		read = fscanf(fp,"%d,%[^,],%[^,],%d,%d,%[^,],%[^\n]\n",&id,nation,soundType,&cantPlayers,&maxToken,saloonName,gameName);
		//printf("%d,%s,%s,%d,%d,%s,%s\n",id,nation,soundType,cantPlayers,maxToken,saloonName,gameName);

		if(read==7)
		{
			//printf("%d,%s,%s,%d,%d,%s,%s\n",id,nation,soundType,cantPlayers,maxToken,saloonName,gameName);

			findFlag = 0;
			for(i = 0; i < ll_len(this);i++)
			{
				//rintf("%d",findFlag);
				saloon = (Saloon*)ll_get(this, i);
				if(saloon != NULL)
				{
					saloon_getName(saloon, tempSaloonName);
					//printf("%s,%s\n",saloonName, tempSaloonName);
					if(strncmp(saloonName,tempSaloonName,51)==0)
					{
						findFlag=1;
						break;
					}
				}
			}
			//printf("%d\n",findFlag);
			if(findFlag == 1)
			{
				pFirstArcade = saloon->pFirstArcade;
				arcade = arcade_new();
				if(arcade != NULL)
				{
					arcade_setAll(arcade, id, gameName, nation, soundType, cantPlayers, maxToken);
					ll_add(pFirstArcade, arcade);
					//printf("%s %d %d\n",arcade->gameName,arcade->id, ll_add(pFirstArcade, arcade));
				}

			}
			else
			{
				saloon = saloon_new();
				if(saloon != NULL)
				{
					pFirstArcade = ll_newLinkedList();
					saloon->pFirstArcade = pFirstArcade;

					saloon_setName(saloon, saloonName);
					ll_add(this, saloon);

					arcade = arcade_new();

					if(arcade != NULL && pFirstArcade != NULL)
					{
						arcade_setAll(arcade, id, gameName, nation, soundType, cantPlayers, maxToken);
						ll_add(pFirstArcade, arcade);
					}
				}
			}

		}
		else
		{
			errorCode=-1;
			break;
		}
		errorCode = id;
	}
	fclose(fp);
    return errorCode;
}

/** \brief generar Tabla cruzada
 *
 * \param this LinkedList*
 * \return LinkedList*
 * \crea una nueva linked list juntando todos los arcades en una unica guardando todos los datos
 */

LinkedList* controller_generateJoinList(LinkedList* this)
{
	LinkedList* newJointList = NULL;
	JointList* pElementJoin;

	Arcade* arcade;
	Saloon* saloon;
	int i;
	int j;

	LinkedList* thisArcade;

	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonName[51];

	newJointList = ll_newLinkedList();
	if(this != NULL && newJointList != NULL)
	{
		//printf("\nEntre\n");
		for(i = 0; i < ll_len(this);i++)
		{
			//rintf("%d",findFlag);
			saloon = (Saloon*)ll_get(this, i);
			if(saloon != NULL)
			{
				thisArcade = saloon->pFirstArcade;
				if(thisArcade != NULL)
				{
					for(j = 0; j < ll_len(thisArcade);j++)
					{
						arcade = (Arcade*)ll_get(thisArcade, j);
						if(arcade!=NULL)
						{
							pElementJoin = controller_newJoint();
							if(pElementJoin != NULL)
							{
								arcade_getAll(arcade, &id, gameName, nation, soundType, &cantPlayers, &maxToken);
								saloon_getName(saloon, saloonName);
								controller_setJoint(pElementJoin, id, gameName, nation, soundType, cantPlayers, maxToken, saloonName);
								ll_add(newJointList, pElementJoin);
							}
						}
					}
				}
			}
		}
	}
	//controller_printAllJoin(newJointList);
	return newJointList;
}

/** \brief appendList
 *
 * \param this LinkedList*
 * \param that LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \copia todos los pElement de una linked list a la otra al final.
 */

int controller_appendList(LinkedList* this, LinkedList* that)
{
	int errorCode = -1;
	int i;
	void* pElement;
	if(this!=NULL && that!=NULL)
	{
		for(i=0;i<ll_len(that);i++)
		{
			pElement=ll_get(that, i);
			if(pElement!=NULL)
			{
				ll_add(this, pElement);
			}
		}
		errorCode = 0;
	}
	return errorCode;
}

/** \brief new tabla cruzada
 *
 * \return Tabla Cruzada
 * \crea un puntero de elemento tabla cruzada
 */

JointList* controller_newJoint()
{
	JointList* this = (JointList*)malloc(sizeof(JointList));
	return this;
}

/** \brief setear tabla cruzada
 *
 * \param all Jont paramenters
 * \param this JointList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \setea todos los valores de un elemento de tabla cruzada
 */

int controller_setJoint(JointList* this,int id,char* gameName, char* nation, char* soundType, int cantPlayers, int maxToken, char* saloon)
{
	int errorCode = -1;
	if(this != NULL)
	{
		this->id = id;
		strncpy(this->gameName, gameName, 63);
		strncpy(this->nation,nation,51);
		strncpy(this->soundType,soundType,20);
		this->cantPlayers = cantPlayers;
		this->maxToken = maxToken;
		strncpy(this->saloonName,saloon,51);
		errorCode = 0;
	}
	return errorCode;
}

/** \brief imprimir tabla cruzada
 *
 * \param this JointList=
 * \return int 0 si pudo abrir el archivo -1 si no
 * \Imprime todos los elementos de un elemento de tabla cruzada
 */

int controller_printJoint(JointList* this)
{
	int errorCode = -1;

	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonName[51];
	if(this != NULL)
	{
		controller_getJoint(this, &id, gameName, nation, soundType, &cantPlayers, &maxToken, saloonName);
		printf("%d|%s|%s|%s|%d|%d|%s\n",id,gameName,nation,soundType, cantPlayers,maxToken,saloonName);
		errorCode = 0;
	}
	return errorCode;
}

/** \brief imprimir todos
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \Imprime todos los elementos de todos los elementos de tabla cruzada
 */


int controller_printAllJoin(LinkedList* this)
{
	int errorCode = -1;
	JointList* list;
	if(this != NULL)
	{
		for(int i = 0; i <ll_len(this); i++)
		{
			list = (JointList*)ll_get(this, i);
			if(list != NULL)
			{
				controller_printJoint(list);
			}
		}
	}
	return errorCode;
}

/** \brief conseguir datos de tabla cruzada
 *
 * \param this JointList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \devuelve todos los paramentros de un elemento de tabla cruzada
 */


int controller_getJoint(JointList* this,int* id,char* gameName, char* nation, char* soundType, int* cantPlayers, int* maxToken, char* saloon)
{
	int errorCode = -1;
	if(this != NULL)
	{
		*id = this->id;
		strncpy(gameName,this->gameName, 63);
		strncpy(nation,this->nation,51);
		strncpy(soundType,this->soundType,20);
		*cantPlayers = this->cantPlayers;
		*maxToken = this->maxToken;
		strncpy(saloon,this->saloonName,51);
		errorCode = 0;
	}
	return errorCode;
}

/** \brief ordenar juntura
 *
 * \param this void*
 * \param that void*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \compara dos elementos de tabla cruzada por nombre
 */


int controller_sortJoint(void* pElementA, void* pElementB)
{
	int errorCode = 0;
	JointList* elementA =(JointList*)pElementA;
	JointList* elementB =(JointList*)pElementB;
	if(elementA != NULL && elementB != NULL)
	{
		errorCode = stricmp(elementA->gameName,elementB->gameName);
	}
	return errorCode;
}


/** \brief filtrar por multi
 *
 * \param this void*
 * \return int -1 si no pudo abrir. 1 Si es multiplayer 0 si no lo es
 * \compara si un elemento es multyplayer
 */

int controller_filterMultiplayer(void* arcade)
{
	int errorCode = 0;
	JointList* list = (JointList*)arcade;
	if(list->cantPlayers > 1)
	{
		errorCode = 1;
	}
	return errorCode;
}


/** \brief salvar multijugador txt
 *
 * \param this LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \guarda un archivo de texto con todos los arcades multyplayer
 */

int controller_saveMultiplayer(LinkedList* jointList)
{
	FILE *fp = fopen("multiplayer.txt","w");
	//Node* tempList = ListEmployee->pFirstNode;
	JointList* pElement;

	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonName[51];

	int errorCode = 0;
	int size = ll_len(jointList);

	if(fp != NULL)
	{
		fprintf(fp,"id,nombre,nacionalidad,tipo,cantidadJugadores,tokensMaximos,saloon\n");
		for(int i = 0; i < size; i++)
		{
			pElement = ll_get(jointList,i);
			if(pElement != NULL)
			{
				errorCode = controller_getJoint(pElement, &id, gameName, nation, soundType, &cantPlayers, &maxToken, saloonName);
				if(errorCode == 0)
				{
					fprintf(fp,"%d,%s,%s,%s,%d,%d,%s\n",id,gameName,nation,soundType, cantPlayers, maxToken, saloonName);
				}
			}

		}
		fclose(fp);
	}
	else
	{
		errorCode = -1;
	}

    return errorCode;
}


/** \brief conseguir nombre
 *
 * \param name char*
 * \param this JoinList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \devuelve el elemento nombre de una tabla cruzada
 */

int joint_getName(JointList* pElement, char* gameName)
{
	int errorCode = -1;
	if(pElement != NULL)
	{
		strncpy(gameName,pElement->gameName,63);
	}
	return errorCode;
}


/** \brief es duplicado
 *
 * \param this LinkedList*
 * \return LinkedList*
 * \devuelve una tabla sin duplicados de nombre de una tabla cruzada
 */

LinkedList* controller_isDuplicated(LinkedList* jointList)
{
	int i;
	int j;
	JointList* pElementA;
	JointList* pElementB;
	char gameNameA[63];
	char gameNameB[63];

	LinkedList* ll_temp = ll_newLinkedList();
	int flag;

	if(ll_temp != NULL)
	{
		for(j = 0; j < ll_len(jointList);j++)
		{
			flag = 0;
			pElementA = (JointList*)ll_get(jointList, j);
			joint_getName(pElementA, gameNameA);
			if(ll_len(ll_temp)==0)
			{
				ll_add(ll_temp, pElementA);
			}
			else
			{
				for(i = 0;i<ll_len(ll_temp);i++)
				{
					pElementB = (JointList*)ll_get(ll_temp, i);
					joint_getName(pElementB, gameNameB);

					if(stricmp(gameNameB,gameNameA)==0)
					{
						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					ll_add(ll_temp, pElementA);
				}
			}
		}
	}
	return ll_temp;
}


/** \brief salvar juegos
 *
 * \param that LinkedList*
 * \return int 0 si pudo abrir el archivo -1 si no
 * \cguarda un txt con los juegos sin duplicar
 */

int controller_saveGames(LinkedList* this)
{
	int errorCode = -1;
	LinkedList* ll_temp;
	char gameName[63];
	FILE *fp = fopen("games.txt","w");
	JointList* pElement;
	int i;
	if(fp != NULL)
	{
		ll_temp = controller_isDuplicated(this);
		for(i = 0; i <ll_len(ll_temp);i++)
		{
			pElement=(JointList*)ll_get(ll_temp, i);
			joint_getName(pElement, gameName);
			fprintf(fp,"%s\n",gameName);
		}
		fclose(fp);
		ll_deleteLinkedList(ll_temp);
	}
	return errorCode;
}


/** \brief duplicar tokens
 *
 * \param this void*
 * \return void
 * \duplica los tokens maximos de un arcade
 */

void controller_duplicateTokens(void* arcade)
{
	JointList* list = (JointList*)arcade;
	list->maxToken = list->maxToken *2;

}


/** \brief appendList
 *
 * \param this LinkedList
 * \return int 0 si pudo abrir el archivo -1 si no
 * \guarda en un archivo de texto una tabla cruzada, para el ejemplo se le dio un nombre especifico
 */

int controller_saveKointAsText(LinkedList* this)
{
	int errorCode = -1;
	FILE *fp = fopen("arcadesDuply.txt","w");
	JointList* pElement;
	int i;

	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonName[51];

	if(fp != NULL)
	{
		fprintf(fp,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game");
		for(i = 0; i <ll_len(this);i++)
		{
			pElement=(JointList*)ll_get(this, i);
			controller_getJoint(pElement, &id, gameName, nation, soundType, &cantPlayers, &maxToken, saloonName);
			fprintf(fp,"%d,%s,%s,%d,%d,%s,%s\n",id,nation,soundType,cantPlayers,maxToken,saloonName,gameName);
		}
		fclose(fp);
	}
	return errorCode;

}

