#include "stdafx.h"
#include "SelectionSort.h"


SelectionSort::SelectionSort(int *A, int n)
{
	int minIndex;

	for (int i = 0; i < n - 1; i++) {
		minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[minIndex])
				minIndex = j;
		}

		swapElements(A, minIndex, i);
	}

}


SelectionSort::~SelectionSort()
{
}


void SelectionSort::swapElements(int *A, int x, int y) 
{
	int temp;

	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}