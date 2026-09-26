//Use header we created
#include "header.h"

//Funcs to be used in the program

//Creates a node, parameter of a Record named newRecord. Malloc memory, 
//then if pMem is empty, sets pMem's pNext and pPrev to NUll, aka list of one,
//and sets the data in pMem to what was passed using newRecord

Node* createNodeFunc(Record newRecord)
{
	//Malloc memory, then check if successfull
	Node* pMem = malloc(sizeof(Node));

	if (pMem != NULL)
	{
		
		pMem->pNext = pMem->pPrev = NULL;
		pMem->recordData = newRecord; // Pulls the mewRecord we passed in and sets pMem as that record

		//printf("%s",newRecord.);
	}

	//Needs to set pMem's pNext to what is currently in pMem, data to what is passed using newRecord,
	//set pMem's pPrev to NULL, and set pMem's pPrev to NULL,

	else
	{


	}

	return pMem;
}

Record* readFunc(char* dataReader)// Needs to be  pointer, needs to return a Record pointer
{
	Record* pCurrData = NULL;

	printf("%s",dataReader);

	//Here is where a Record struct pointer called pCurrData pulls info from the data stream file

	char* token = strtok(dataReader, ","); //Grabs the first token of the file

	while (token != NULL)
	{


		//Artist
		//Read the token for the " character to denote a double name; The firs token is the name member of the struct

		char* search = strchr(token, '"'); //strchr returns a null pointer if character is not found

		if (search != NULL)
		{
			char* name = search;

			strcat(name, strtok(NULL, ",")); //Add a second token with the second half of the name to the name token

			strcpy(pCurrData->artist, name);
		}

		else
		{

			strcpy(pCurrData->artist, token);
		}

		// Album
		
		token = strtok(NULL, ",");
		strcpy(pCurrData->album, token);

		//Song Title
		 
		token = strtok(NULL, ",");
		strcpy(pCurrData->songTitle, token);
		
		//Genera
		
		token = strtok(NULL, ",");
		strcpy(pCurrData->genera, token);
		
		//Time Min, Sec is seperated by : character
		token = strtok(NULL, ":");
		pCurrData->minutes = atoi(token);

		token = strtok(NULL, ",");
		pCurrData->seconds = atoi(token);
		 
		//Repeats
		
		token = strtok(NULL, ",");
		pCurrData->timesPlayed = atoi(token);
		 
		//Rating
		token = strtok(NULL, ",");
		pCurrData->rating = atoi(token);
	}

	return pCurrData;
}