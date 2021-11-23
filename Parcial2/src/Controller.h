int controller_loadFromText(char* path , LinkedList* this);
int ll_parserText(FILE* fp , LinkedList* this);
int controller_ListSaloon(LinkedList* this);
int controller_ListArcade(LinkedList* this);
int controller_addSaloon(LinkedList* this);
int controller_findIndexOf(LinkedList* this, char* saloonName);
int controller_addArcade(LinkedList* this, int currentID);
int controller_modifyArcade(LinkedList* this);
int controller_deleteArcade(LinkedList* this);
int controller_deleteSaloon(LinkedList* this);

struct JointList
{
	int id;
	char gameName[63];
	char nation[51];
	char soundType[20];
	int cantPlayers;
	int maxToken;
	char saloonName[51];
};

typedef struct JointList JointList;

JointList* controller_newJoint();
LinkedList* controller_generateJoinList(LinkedList* this);
int controller_appendList(LinkedList* this, LinkedList* that);
int controller_setJoint(JointList* this,int id,char* gameName, char* nation, char* soundType, int cantPlayers, int maxToken, char* saloon);
int controller_getJoint(JointList* this,int* id,char* gameName, char* nation, char* soundType, int* cantPlayers, int* maxToken, char* saloon);
int controller_printJoint(JointList* this);
int controller_printAllJoin(LinkedList* this);
int controller_sortJoint(void* pElementA, void* pElementB);
int controller_filterMultiplayer(void* arcade);
int controller_saveMultiplayer(LinkedList* jointList);
int joint_getName(JointList* pElement, char* gameName);
LinkedList* controller_isDuplicated(LinkedList* jointList);
int controller_saveGames(LinkedList* this);
void controller_duplicateTokens(void* arcade);
int controller_saveKointAsText(LinkedList* this);
