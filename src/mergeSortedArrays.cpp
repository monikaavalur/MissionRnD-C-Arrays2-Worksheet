/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL)
		return NULL;
	int len = ALen + BLen;
	struct transaction *temp =( struct transaction*)malloc(len*sizeof(struct transaction));
	int index = 0, index1 = 0, index2 = 0;
	while (index < ALen&&index1 < BLen)
	{
		if (A[index].amount <= B[index1].amount)
		{
			temp[index2] = A[index];
			index++;
			index2++;
		}
		if (A[index].amount>B[index1].amount)
		{
			temp[index2] = B[index1];
			index1++;
			index2++;
		}

	}
	if (index == ALen)
	{
		for (index1 = index1; index1 < BLen; index1++)
		{
			temp[index2] = B[index1];
			index2++;
		}
	}
    if (index1 == BLen)
	{
		for (index = index; index < ALen; index++)
		{
			temp[index2] = A[index];
			index2++;
		}
	}
	return temp;
}



	