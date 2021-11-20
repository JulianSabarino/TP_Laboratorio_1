#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);//LISTO
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList));
	if(this !=NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}

    return this;

}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* temp = NULL;

	if (this != NULL &&  (nodeIndex < ll_len(this) && nodeIndex >= 0) )
	{
		temp = this->pFirstNode;
		for (int i = 0; i < nodeIndex; i++)
		{
			temp = temp->pNextNode;
		}
	}
	return temp;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int errorCode = -1;
    Node* temp;//aux
    Node* newNode;//nuevo nodo
    int size = ll_len(this);
    if (this != NULL && (nodeIndex <= size && nodeIndex >= 0))// 0 1 2 3 4
    {
    	newNode = (Node*)malloc(sizeof(Node));
    	if(newNode!=NULL)
    	{
			if(nodeIndex == 0)
			{
				temp = getNode(this, nodeIndex);
				newNode->pNextNode = temp;
				this->pFirstNode = newNode;
				errorCode = 0;

			}
			else
			{
				temp = getNode(this, nodeIndex-1);
		  		newNode->pNextNode = temp->pNextNode;
				temp->pNextNode=newNode;
				errorCode = 0;

			}
			if(errorCode == 0)
			{
				newNode->pElement = pElement;
				size++;
				this->size=size;
			}
    	}
    }

    return errorCode;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int errorCode = addNode(this, ll_len(this), pElement);

    return errorCode;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node* temp = getNode(this, index);
    void* errorCode = NULL;

    if(temp != NULL)
    {
    	errorCode = temp->pElement;
    }

    return errorCode;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int errorCode = -1;
    Node* temp;
    if(this != NULL && (index < ll_len(this) && index >= 0))
    {
    	temp = getNode(this, index);
    	if(temp != NULL)
    	{
    		temp->pElement = pElement;
    		errorCode = 0;
    	}
    	//errorCode = addNode(this, index, pElement);
    }

    return errorCode;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int errorCode = -1;
	Node* temp;
	Node* removeNode;
	if(this != NULL && (index < ll_len(this) && index >= 0) )
	{
		if(index == 0)
		{
			temp = getNode(this, (index));
			if(temp != NULL)
			{
				this->pFirstNode = temp->pNextNode;
				removeNode = temp;
				errorCode = 0;
			}
		}
		else
		{
			temp = getNode(this, (index-1)); // 0 1 2 3(si quiero eliminar 4) 4
			if(temp !=NULL)
			{
				removeNode=temp->pNextNode;
				if(index == ll_len(this-1))
				{
					temp->pNextNode = NULL;
				}
				else
				{
					temp->pNextNode = removeNode->pNextNode;
				}
				errorCode = 0;
			}
		}
		if(errorCode == 0)
		{
			this->size--;
			free(removeNode->pElement);
			free(removeNode);
		}
	}

    return errorCode;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int errorCode = -1;
    if(this != NULL)
    {
		for(int i = (ll_len(this)-1);i>=0;i--)
		{
			errorCode = ll_remove(this, i);
			if(errorCode == -1)
			{
				break;
			}
		}
    }
    return errorCode;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int errorCode = -1;
    if(this != NULL)
    {
    	errorCode = ll_clear(this);
    	if(errorCode == 0)
    	{
    		free(this);
    	}
    }

    return errorCode;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int errorCode = -1;
    Node* temp;
    if(this!=NULL)
    {
    	for(int i = 0; i < ll_len(this);i++)
    	{
    		temp = getNode(this, i);
    		if(temp!=NULL)
    		{
    			if(pElement == temp->pElement)
    			{
    				errorCode = i;
    				break;
    			}
    		}
    	}
    }

    return errorCode;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int errorCode = -1;
    if(this != NULL)
    {
    	if(ll_len(this)>0)
    	{
    		errorCode = 0;
    	}
    	else
    	{
    		errorCode = 1;
    	}
    }

    return errorCode;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int errorCode = -1;
    if(this != NULL && (index <= ll_len(this) && index >= 0))
    {
    	errorCode = addNode(this, index, pElement);
    }

    return errorCode;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* errorCode = NULL;

	errorCode= ll_get(this,index);
	ll_remove(this,index);

	return errorCode;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int errorCode = -1;

	if(this != NULL)
	{
		errorCode = ll_indexOf(this, pElement);
		if(errorCode >= 0)
		{
			errorCode = 1;
		}
		else
		{
			errorCode = 0;
		}
	}

    return errorCode;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int errorCode = -1;
	void* pElement;

	if(this != NULL && this2 != NULL)
	{
		errorCode = 0;
		for(int i = 0; i<ll_len(this2);i++)
		{
			pElement = ll_get(this2, i);
			errorCode = ll_contains(this, pElement);
			if(errorCode == 0)
			{
				break;
			}
		}
	}
	return errorCode;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* errorCode = NULL;
	void* temp;
	int size=ll_len(this);

	if(this!= NULL && from >= 0 && to <= size && from <= to)
	{
		errorCode=ll_newLinkedList();
	    for (int i=from; i<to; i++)
	    {
	    	temp=ll_get(this,i);
	    	if(temp!=NULL)
	    	{
	    		ll_add(errorCode,temp);
	    	}
	    }
	}

	return errorCode;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* errorCode = ll_subList(this, 0, ll_len(this));

    return errorCode;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int i;
	int j;
	int errorCode = -1;
	int len = ll_len(this);
	void* pElementA;
	void* pElementB;

	if(this != NULL && len>0 && pFunc != NULL && (order == 0 || order == 1))
	{
		if(len>=2)
		{
			for(i=0;i<len-1;i++)
			{
				errorCode = 1;
				for(j=(i+1);j<len;j++)
				{
					pElementA=ll_get(this,i);
					pElementB=ll_get(this,j);
					if(pElementA!= NULL && pElementB!= NULL)
					{
						if (order == 1)
						{
							if(pFunc(pElementA, pElementB)>0)
							{
								ll_set(this, i, pElementB);
								ll_set(this, j, pElementA);

								errorCode=0;
							}
						}
						else
						{
							if(pFunc(pElementA, pElementB)<0)
							{
								ll_set(this, i, pElementB);
								ll_set(this, j, pElementA);
								errorCode=0;
							}
						}
					}
				}
				if(errorCode != 0)
				{
					break;
				}
			}
		}
		errorCode = 0;
	}
	return errorCode;
}

