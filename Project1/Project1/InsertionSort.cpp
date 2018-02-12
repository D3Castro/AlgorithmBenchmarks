#include "stdafx.h"
#include "InsertionSort.h"


InsertionSort::InsertionSort(int *A, int n)
{
	int j;

	for (int i = 0; i < n; i++) {
		j = i;

		while (j > 0 && A[j] < A[j - 1]) {
			swapElements(A, j, j - 1);
			j--;
		}
	}
}


InsertionSort::~InsertionSort()
{
}

void InsertionSort::swapElements(int *A, int x, int y) 
{
	int temp;

	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}