/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int convert(char *);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL)
		return NULL;
	int count = 0;
	struct student *temp;
	for (int i = 0; i < ALen; i++)
	{
		int date1 = convert(A[i].date);
		int date2 = convert(B[i].date);
		if (date1 == date2)
			count++;
	}
	if (count == ALen)
		return A;
	if (count == 0)
		return NULL;
	else
	{
		for (int i = 0; i < ALen; i++)
		{
			for (int j = 0; j < BLen; j++)
			{
				int date1 = convert(A[i].date);
				int date2 = convert(B[j].date);
				if (date1 == date2)
					return B;
			}
		}
	}
}

int convert(char *date)
{
	int day = strtol(date, &date, 10);
	int month = strtol(++date, &date, 10);
	int year = strtol(++date, &date, 10);
	return (year * 12 + month) * 31 + day;
}




