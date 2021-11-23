/*
 * arcade.c
 *
 *  Created on: Oct 17, 2021
 *      Author: JS
 */

#include "arcade.h"

Arcade* arcade_new()
{
	Arcade* this =(Arcade*)malloc(sizeof(Arcade));
	return this;
}

int arcade_setAll(Arcade* this,int id,char* gameName, char* nation, char* soundType, int cantPlayers, int maxToken)
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
		errorCode = 0;
	}
	return errorCode;
}

int arcade_getAll(Arcade* this,int* id,char* gameName, char* nation, char* soundType, int* cantPlayers, int* maxToken)
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
		errorCode = 0;
	}
	return errorCode;
}

int arcade_getId(Arcade* this, int* id)
{
	int errorCode = -1;
	if(this != NULL)
	{
		*id = this->id;
		errorCode = 0;
	}
	return errorCode;
}

Arcade* arcade_newParameters(int currentID)
{
	Arcade* arcade = NULL;
	Arcade* tempArcade;
	char gameName[63];
	char nation[51];
	int sound;
	char soundType[20];
	int cantPlayers;
	int maxToken;
	int errorCode = 0;

	arcade = arcade_new();
	if(arcade != NULL)
	{
		printf("Ingrese Nombre: ");
		errorCode = errorCode + myGets(gameName, sizeof(gameName));
		printf("Ingrese Nacionalidad: ");
		errorCode = errorCode + myGets(nation, sizeof(nation));
		printf("Ingrese Mono(0) o Estereo(1): ");
		errorCode = errorCode + getMyInt(&sound);
		if(errorCode == 1)
		{
			strncpy(soundType,"STEREO", sizeof(soundType));
		}
		else
		{
			strncpy(soundType,"MONO", sizeof(soundType));
		}
		printf("Ingrese Cantidad de Jugadores: ");
		errorCode = errorCode + getMyInt(&cantPlayers);
		if(cantPlayers<1)
		{
			cantPlayers = 1;
		}
		printf("Ingrese cant Tokens: ");
		errorCode = errorCode + getMyInt(&maxToken);
		if(maxToken<1)
		{
			maxToken = 1;
		}
		if(errorCode == 0 )
		{
			arcade_setAll(arcade, currentID, gameName, nation, soundType, cantPlayers, maxToken);
		}
		else
		{
			tempArcade = arcade;
			free(tempArcade);
			arcade = NULL;
			errorCode = -1;
		}
	}
	return arcade;
}

/*


int initArcade(Arcade* list,int len)
{
	int i;
	int errorCode = -1;
	if(list !=NULL && len > 0)
	{
		for(i = 0;i < len;i++)
		{
			list[i].isEmpty = 1;
		}
		errorCode = 0;
	}
	return errorCode;
}


int addArcade(Arcade* list, int len, char* nation, char* soundType, int cantPlayers, int maxToken, char* saloonId, char* gameName, char* id)
{
	int errorCode;
	int i;


	if(list != NULL && len > 0)
	{
		i = findArcadeEmpty(list, len);
		if(i >= 0)
		{
			strncpy(list[i].nation,nation,51);
			strncpy(list[i].soundType,soundType,20);
			list[i].cantPlayers = cantPlayers;
			list[i].maxToken = maxToken;
			strncpy(list[i].saloonId,saloonId,7);
			strncpy(list[i].gameName,gameName,63);
			strncpy(list[i].id,id,7);

			myGames(2, gameName);

			list[i].isEmpty = 0;

			errorCode = i;
		}
	}
	return errorCode;
}


int protectedAddArcade(Arcade* listA,int lenA, Saloon* listS,int lenS)
{
	int errorCode = -1;

	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonId[7];
	char gameName[63];
	char id[7];

	//static int ID = 0; // USO ESTO SI QUIERO CREAR UN ID AUTOINCREMENTAL

	errorCode = printSaloon(listS, lenS, 3);

	if(errorCode == 0)
	{
		printf("Seleccione Salon a agregar Arcade (ID): ");
		errorCode = myGets(saloonId, 7);
		if(errorCode == 0)
		{
			errorCode = findSaloonId(listS, lenS, saloonId);
		}
	}

	if(errorCode >= 0)
	{
		printf("Ingrese Nacionalidad del Arcade: ");
		errorCode = myGets(nation,51);

		printf("Ingrese Tipo de Sonido: ");
		errorCode = errorCode + myGets(soundType,20);

		printf("Ingrese canitdad de jugadores posibles: ");
		errorCode = errorCode + getMyInt(&cantPlayers);

		printf("Ingrese canitdad de fichas maximas: ");
		errorCode = errorCode + getMyInt(&maxToken);

		printf("Ingrese nombre del Juego: ");
		errorCode = errorCode + myGets(gameName,63);

		//if(errorCode == 0 && maxToken>0 && cantPlayers>0 && (stricmp(soundType,"Mono") == 0 || stricmp(soundType,"Estereo")==0)){}
		if(errorCode == 0)
		{
			strncpy(id,nation,2);
			strncat(id,gameName,2);
			strncat(id,saloonId,2);

			id[6] = '\0';

			errorCode = addArcade(listA, lenA, nation, soundType, cantPlayers, maxToken, saloonId, gameName, id);
			//ID++;
		}

	}

	return errorCode;
}

int deleteArcade(Arcade* list, int len, char* id)
{
	int errorCode = -1;
	errorCode = findArcadeId(list,len,id);
	if(errorCode >= 0)
	{
		list[errorCode].isEmpty = 1;
	}

	return errorCode;
}

int deleteArcadeSaloonID(Arcade* list, int len, char* id)
{
	int errorCode = -1;
	int i;
	if(list != NULL && len > 0)
	{
		errorCode=0;
		for(i = 0;i<len;i++)
		{
			if(stricmp(list[i].saloonId,id)==0)
			{
				list[i].isEmpty = 1;
				errorCode++;
			}
		}
	}

	return errorCode;
}

int protectedDeleteArcade(Arcade* list, int len)
{
	int errorCode;
	char id[7];
	errorCode = printArcade(list, len);
	if(errorCode == 0)
	{
		printf("Seleccione Arcade a eliminar (ID): ");
		errorCode = myGets(id, 7);
		if(errorCode == 0)
		{
			errorCode = deleteArcade(list,len,id);
		}
	}

	return errorCode;
}

int modifyGameArcade(Arcade* list, int len, char* id, char* gameName)
{
	int errorCode = -1;
	errorCode = findArcadeId(list,len,id);
	if(errorCode >= 0)
	{
		strncpy(list[errorCode].gameName,gameName,sizeof(list[errorCode].gameName));
		myGames(2, gameName);
	}
	return errorCode;
}
int modifyPlayArcade(Arcade* list, int len, char* id, int canPlayers)
{
	int errorCode = -1;
	errorCode = findArcadeId(list,len,id);
	if(errorCode >= 0)
	{
		list[errorCode].cantPlayers = canPlayers;
	}
	return errorCode;
}
int protectedModifyArcade(Arcade* list, int len)
{
	int errorCode = -1;
	char id[7];
	char gameName[63];
	int cantPlayers;
	int option;
	errorCode = printArcade(list, len);
	if(errorCode == 0)
	{
		printf("Seleccione Arcade a Modificar (ID): ");
		errorCode = myGets(id, 7);
		if(errorCode == 0)
		{
			printf("\t1.Nombre del Juego\n");
			printf("\t2.Cantidad de Jugadores\n");
			errorCode = getMyInt(&option);
			if(errorCode == 0)
			{
				switch(option)
				{
					case 1:
						myGames(1, NULL);
						printf("Ingrese Nuevo Nombre: ");
						errorCode = myGets(gameName, sizeof(gameName));
						if (errorCode == 0)
						{
							errorCode = modifyGameArcade(list,len,id,gameName);
						}
						break;
					case 2:
						printf("Ingrese Nueva Cantidad dew Jugadores: ");
						errorCode = getMyInt(&cantPlayers);
						if (errorCode == 0)
						{
							errorCode = modifyPlayArcade(list, len,id,cantPlayers);
						}
						break;
				}
			}
		}
	}
	return errorCode;
}

int findArcadeEmpty(Arcade* list, int len)
{
	int errorCode = -1;
	int i;

	if(list !=NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				errorCode = i;
				break;
			}
		}
	}

	return errorCode;
}

int findArcadeId(Arcade* list, int len, char* id)
{
	int errorCode = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(stricmp(list[i].id,id)==0)
			{
				errorCode = i;
				break;
			}
		}
	}

	return errorCode;
}


int printArcade(Arcade* list, int len)
{
	int errorCode = -1;
	int i;
	if(list !=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("ID: %s ID Salon: %s GName: %s Players: %d Sonido: %s Nacionalidad: %s Fichas: %d \n",list[i].id, list[i].saloonId, list[i].gameName, list[i].cantPlayers,list[i].soundType,list[i].nation,list[i].maxToken);
			}
		}
		errorCode = 0;

	}
	return errorCode;
}

int deleteSaloon(Saloon* list, int len, char* id, Arcade* listA, int lenA)
{
	int errorCode = -1;
	errorCode = findSaloonId(list,len,id);
	if(errorCode >= 0)
	{
		list[errorCode].isEmpty = 1;
		errorCode = deleteArcadeSaloonID(listA, lenA, id);
	}

	return errorCode;
}

int protectedDeleteSaloon(Saloon* listS, int lenS, Arcade* listA, int lenA)
{
	int errorCode;
	char id[7];
	errorCode = printSaloon(listS, lenS, 3);
	if(errorCode == 0)
	{
		printf("Seleccione Salon a eliminar (ID): ");
		errorCode = myGets(id, 7);
		if(errorCode == 0)
		{
			errorCode = deleteSaloon(listS,lenS,id,listA,lenA);
		}
	}

	return errorCode;
}


//

int myGames(int option,char* newGame)
{
	int errorCode = -1;
	static Games gameList[1000];

	switch(option)
	{
		case 0:
			errorCode = initGames(gameList,1000);
			break;
		case 1:
			errorCode = printMyGames(gameList,1000);
			break;
		case 2:
			errorCode = addNewGames(gameList,1000,newGame);
			break;
	}

	return errorCode;
}

int initGames(Games* list,int len)
{
	int i;
	int errorCode = -1;
	if(list !=NULL && len > 0)
	{
		for(i = 0;i < len;i++)
		{
			list[i].isEmpty = 1;
		}
		errorCode = 0;
	}
	return errorCode;
}

int printMyGames(Games* list, int len)
{
	int errorCode = -1;
	int i;
	if(list !=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("%s\n",list[i].gameName);
			}
		}
		errorCode = 0;
	}

	return errorCode;
}

int addNewGames(Games* list, int len, char* newGame)
{
	int errorCode = -1;
	int i;
	int flag = 0;
	if(list !=NULL && len > 0)
	{
		for(i = 0; i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(stricmp(list[i].gameName,newGame)==0)
				{
					flag = 1;
					break;
				}
			}
		}

		if(flag == 0)
		{
			for(i = 0; i<len;i++)
			{
				if(list[i].isEmpty == 1)
				{
					strncpy(list[i].gameName,newGame,63);
					list[i].isEmpty = 0;
					break;
				}
			}

		}
		errorCode = 0;
	}
	return errorCode;
}
*/
