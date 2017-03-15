// athleteMedalsWeek22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstdlib>
#include <cstring>

void readFile();
void findAthlete(int iyear, char *isport);

struct athletes
{
	char *name;
	int age;
	char *country;
	int year;
	char *sport;
	int gold;
	int silver;
	int bronze;
	int total;
	athletes *next;
};
struct athletes *first;

void main(int argc, char *argv[])
{
	int year = atoi(argv[1]);
	char *sport = argv[2];
	printf("\nName\t\t\t\tAge\tCountry\t\t#Gold\t\t#Silver\t\t#Bronze\t\t#Total");
	printf("\n======================================================================\n");
	readFile();
	findAthlete(year, sport);
}

void readFile()
{
	FILE *ptr;
	char line[200];
	char *token;
	char delim[2] = "\t";
	struct athletes *current = NULL;
	struct athletes *after = NULL;

	ptr = fopen("athletes.txt", "r");

	while(!feof(ptr))
	{
		fgets(line, 200, ptr);
		if (first == NULL)
		{
			first = (struct athletes*) malloc(sizeof(athletes));
			first->next = NULL;
			current = first;
		}
		else
		{
			after = (struct athletes*)malloc(sizeof(athletes));
			current->next = after;
			current = after;
			after->next = NULL;
		}
		if ((token = strtok(line, delim)) != NULL)
		{
			current->name = (char*)malloc(sizeof(token));
			strcpy(current->name, token);
		}
		if ((token = strtok(NULL, delim)) != NULL) current->age = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL)
		{
			current->country = (char*)malloc(sizeof(token));
			strcpy(current->country, token);
		}
		if ((token = strtok(NULL, delim)) != NULL) current->year = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL)
		{
			current->sport = (char*)malloc(sizeof(token));
			strcpy(current->sport, token);
		}
		if ((token = strtok(NULL, delim)) != NULL) current->gold = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) current->bronze = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) current->silver = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) current->total = atoi(token);
	}
	fclose(ptr);
}

void findAthlete(int iyear, char *isport)
{
	struct athletes *current;
	current = first;
	while(current != NULL)
	{
		if((current->year == iyear) && (strcmp(current->sport, isport) == 0))
		{
			printf("%s\t\t\t%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
				current->name,
				current->age,
				current->country,
				current->gold,
				current->silver,
				current->bronze,
				current->total);
		}
		current = current->next;
	}
	return;
}
