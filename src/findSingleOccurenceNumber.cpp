/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
int nonduplicate(int *,  int );
int sort(int *, int );
int findSingleOccurenceNumber(int *A, int len) 
{
	if (A == NULL)
		return -1;
	int result;
	sort(A,len);
	result=nonduplicate(A, len);
	return result;
}
int sort(int *arr, int size)
{
	int swap;
	for (int index = 0; index < (size - 1); index++)
	{
		for (int index1 = 0; index1 < size - index - 1; index1++)
		{
			if (arr[index1] > arr[index1 + 1]) /* For decreasing order use < */
			{
				swap = arr[index1];
				arr[index1] = arr[index1 + 1];
				arr[index1 + 1] = swap;
			}
		}
	}
	return *arr;
}
int nonduplicate(int *arr, int len)
{
	for (int index = 0; index < len - 1; index++){
		if (arr[index] == arr[index + 1]){
			do{
				index++;
			} while (index < len - 1 && arr[index] == arr[index + 1]);
		}
		else{
			return arr[index];
		}
	}
	if (arr[len - 1] != arr[len - 2]){
		return arr[len - 1];
	}
}