/*
	Andrew Goatt 
	WSU Cpt_S 122 
	
	Music Manager V3.Sep.21
	A program using llists that sorts music

*/


//Use header we created
#include "header.h"

int userIn;
int songQuant = 0;
int index = 0;
char dataReader[100] = "";

main()
{
	Node* pHead = NULL; // Start with an empty list of just pHead
	Node* pMem = NULL;//pMem will watch for and relay data, 'holder' pointer
	Record* pRecord = NULL;

	FILE* fileReader = fopen("musicPlayList.csv", "r");

	//Checks if file opened correctly
	if (fileReader != NULL)
	{

		printf("%s", "File Opened\n\n");
	}

	//Menu
	printf("%s", "Select a funtion\n");

	printf("%s", "1: Load\n2: Store\n3: Display\n4: Insert\n5: Delete\n6: Edit\n7: Sort\n8: Rate\n9: Play\n10: Shuffle\n11: Exit\n\n");

	//Input will read until exit command is given
	scanf("%d", &userIn);

	while (userIn != 11)
	{

		switch (userIn)
		{

		case 1: //Case 1 loads the file

		{
			//Needs to read into the llist
			while (fgets(dataReader, 200, fileReader) != NULL) //Until we read the end of the line
			{


				//printf("%s\n",dataReader);

				pRecord = readFunc(dataReader); // Needs to be a pointer, points to the array of the string, needs to return a Record			
				songQuant++;
				//printf("%i", songQuant);	

			}

			//New Node function that loads songQ number of songs into new nodes
			//pRecord = pMem->recordData;

			while (index < songQuant)
			{
				//createNodeFunc();//Needs to pass in a Record
				printf("%s","Run createNodeFunc\n");
				index++;
			}

			printf("%s", "\nreadFunction ran\n");

			break;
		}

		case 2:
		{
			//printf("%s","Store\n");
			//storeFunc();
			break;
		}

		case 3:
		{
			//Needs to display songs by Artist
			printf("%s", "Display\n");
			//displayFunc();
			break;
		}

		case 4:
		{
			printf("%s", "Insert\n");
			break;
		}

		case 5:
		{
			printf("%s", "Delete\n");
			break;
		}

		case 6:
		{
			printf("%s", "Edit\n");
			break;
		}

		case 7:
		{
			printf("%s", "Sort\n");
			break;
		}

		case 8:
		{
			printf("%s", "Rate\n");
			break;
		}

		case 9:
		{
			printf("%s", "Play\n");
			break;
		}

		case 10:
		{
			printf("%s", "Shuffle\n");
			break;
		}

		case 11: //Case 11 exits the program
		{

			//printf("%s","Close the program");
			fclose("musicPlayList.csv");
			//exit(0);
		}

		}


		//Ask for more input
		scanf("%d", &userIn);
	}

	return;
}
	