/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdlib.h>
int convert_int(char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int count = 0;
	 
	for (int i = 0; i < sizeof(Arr); i++)
	{
		int date1 = convert_int(Arr[i].date);
		int date2 = convert_int(date);
		if (date1 == date2)
			count++;
	}
	if (count != sizeof(Arr))
	{
		count = 0;
		for (int i = 0; i < sizeof(Arr); i++)
		{
			int date1 = convert_int(Arr[i].date);
			int date2 = convert_int(date);
			if (date1 >= date2)
				count++;
		}
		return count;
	}
	else return 0;

}
	
int convert_int(char *date) 
{
	int day = strtol(date, &date, 10);
	int month = strtol(++date, &date, 10);
	int year = strtol(++date, &date, 10);
	return (year * 12 + month) * 31 + day;
}



