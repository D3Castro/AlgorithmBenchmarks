#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort(int *A, int low, int high)
{
	if (low < high) {
		int partitionIndex = partition(A, low, high);

		QuickSort(A, low, partitionIndex - 1);
		QuickSort(A, partitionIndex + 1, high);
	}
}


QuickSort::~QuickSort()
{
}

int QuickSort::partition(int *A, int low, int high) 
{
	int pivot = A[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (A[j] <= pivot) {
			i++;
			swapElements(A, i, j);
		}
	}

	swapElements(A, i + 1, high);

	return i + 1;
}

void QuickSort::swapElements(int *A, int x, int y)
{
	int temp;

	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}
