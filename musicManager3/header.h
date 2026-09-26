//Important format and library stuff
#ifndef header_h
#define header_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structs to be used throughout the program; Duration to hold time data, records to hold song data, and node for llist

struct duration
{

	int minutes;
	int seconds;
};

typedef struct records
{
	char artist[20];
	char album[30];
	char songTitle[30];
	char genera[20];
	struct duration;
	int timesPlayed;
	int rating;


}Record;

typedef struct node
{
	Record recordData; //holds the data of a record

	struct node* pPrev; //pointers to previous and next node in the llist
	struct node* pNext;
}Node;

//Funcs to be used in program
Record* readFunc(char* dataReader); // Reads the file, parameter of reading the fall, returns a Record pointer
Node* createNodeFunc(Record newRecord); // Creates a new node, parameter of Record, called newRecord, returns a Node pointer

#endif
