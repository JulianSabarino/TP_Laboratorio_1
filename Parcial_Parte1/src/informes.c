/*
 * informes.c
 *
 *  Created on: Oct 18, 2021
 *      Author: JS
 */

#include "informes.h"

int listMediumSaloon(Saloon* listS,int lenS,Arcade* listA,int lenA)
{
	int errorCode = -1;
	int i;
	int j;
	int counter;
	int totalCounter=0;
	if(listS != NULL && listA != NULL)
	{
		for(i=0;i<lenS;i++)
		{
			counter = 0;
			if(listS[i].isEmpty == 0)
			{
				for(j=0;j<lenA;j++)
				{
					if(listA[j].isEmpty == 0)
					{
						if(stricmp(listS[i].id,listA[j].saloonId) == 0)
						{
							counter++;
						}
					}
				}
				if(counter >= 4)
				{
					printf("ID: %s Name: %s Direc: %s Tipo: %s C.Arcades: %d\n",listS[i].id,listS[i].name,listS[i].direc,listS[i].type,counter);
					totalCounter++;
				}
			}

		}
		errorCode = totalCounter;
	}
	return errorCode;
}

int listMultiplayer(Arcade* list, int len)
{
	int errorCode = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].isEmpty == 0 && list[i].cantPlayers >=2)
			{
				printf("ID: %s C.Players: %d G.Name: %s ID Salon: %s\n",list[i].id,list[i].cantPlayers,list[i].gameName,list[i].saloonId);
			}
		}
	}
	return errorCode;
}

int listSaloonInfo(Saloon* listS,int lenS,Arcade* listA,int lenA, char* id)
{
	int errorCode = -1;
	int i;
	int j;
	int counter;
	int totalCounter=0;
	if(listS != NULL && listA != NULL)
	{
		i = findSaloonId(listS, lenS, id);
		counter = 0;
		if(listS[i].isEmpty == 0)
		{
			for(j=0;j<lenA;j++)
			{
				if(listA[j].isEmpty == 0)
				{
					if(stricmp(listS[i].id,listA[j].saloonId) == 0)
					{
						counter++;
					}
				}
			}
			printf("ID: %s Nombre: %s Direc: %s Typo: %s C.Arcades: %d\n",listS[i].id,listS[i].name,listS[i].direc,listS[i].type,counter);
		}
		errorCode = totalCounter;
	}
	return errorCode;
}

int listArcadeInfo(Saloon* listS,int lenS,Arcade* listA,int lenA, char* id)
{
	int errorCode = -1;
	int i;
	int j;
	int counter;
	if(listS != NULL && listA != NULL)
	{
		i = findSaloonId(listS, lenS, id);
		if(listS[i].isEmpty == 0)
		{
			counter = 0;
			printf("ID: %s Name: %s Direc: %s Tipo: %s\n",listS[i].id,listS[i].name,listS[i].direc,listS[i].type);
			printf("--------------------------------\n");
			for(j=0;j<lenA;j++)
			{
				if(listA[j].isEmpty == 0)
				{
					if(stricmp(listS[i].id,listA[j].saloonId) == 0)
					{
						printf("ID: %s G.Name: %s C.Players: %d Fichas: %d Nac: %s S.Type: %s\n", listA[j].id, listA[j].gameName, listA[j].cantPlayers, listA[j].maxToken, listA[j].nation, listA[j].soundType);
						counter++;
					}
				}
			}

		}
		errorCode = counter;
	}
	return errorCode;
}

int listBiggestSaloon(Saloon* listS,int lenS,Arcade* listA,int lenA)
{
	int errorCode = -1;
	int i;
	int j;
	int counter;
	int isFirst = 1;
	int maxID;
	int maxCounter = 0;
	if(listS != NULL && listA != NULL)
	{
		for(i=0;i<lenS;i++)
		{
			counter = 0;
			if(listS[i].isEmpty == 0)
			{
				for(j=0;j<lenA;j++)
				{
					if(listA[j].isEmpty == 0)
					{
						if(stricmp(listS[i].id,listA[j].saloonId) == 0)
						{
							counter++;
						}
					}
				}
				if(isFirst==1 || maxCounter < counter)
				{
					maxCounter=counter;
					maxID = i;
					isFirst = 0;
				}
			}

		}
		errorCode = maxID;
		listSaloonInfo(listS, lenS, listA, lenA, listS[errorCode].id);
	}
	return errorCode;
}

int listSaloonIncome(Saloon* listS,int lenS,Arcade* listA,int lenA, char* id, int tokenPrice)
{
	int errorCode = -1;
	int i;
	int j;
	int tokenAcumulator=0;
	if(listS != NULL && listA != NULL)
	{
		i = findSaloonId(listS, lenS, id);
		if(listS[i].isEmpty == 0)
		{
			for(j=0;j<lenA;j++)
			{
				if(listA[j].isEmpty == 0)
				{
					if(stricmp(listS[i].id,listA[j].saloonId) == 0)
					{
						tokenAcumulator = tokenAcumulator + (listA[j].maxToken * tokenPrice);
					}
				}
			}
			errorCode = tokenAcumulator;
		}

	}
	return errorCode;
}

int listArcadeGames(Arcade* list, int len, char* gameName)
{
	int errorCode = -1;
	int i;
	int counter = 0;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(stricmp(list[i].gameName,gameName)==0)
				{
					counter++;
				}
			}
		}
		errorCode = counter;
	}
	return errorCode;
}
