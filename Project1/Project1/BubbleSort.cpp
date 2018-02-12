#include "stdafx.h"
#include "BubbleSort.h"


BubbleSort::BubbleSort(int *A, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (A[j] > A[j + 1])
				swapElements(A, j, j + 1);
		}
	}
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::swapElements(int *A, int x, int y) 
{
	int temp;

	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}