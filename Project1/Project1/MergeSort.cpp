#include "stdafx.h"
#include "MergeSort.h"


MergeSort::MergeSort(int *A, int low, int high)
{
	int mid;

	if (low < high) {
		mid = (low + high) / 2;

		//Split the data
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);

		//Merge data to sort
		Merge(A, low, mid, high);
	}
}


MergeSort::~MergeSort()
{
}

void MergeSort::Merge(int *A, int low, int mid, int high)
{
	int *temp = new int[high - low + 1];
	int i = low;
	int k = 0;
	int j = mid + 1;

	//Sort while merging
	while (i <= mid && j <= high) {
		if (A[i] < A[j]) {
			temp[k] = A[i];
			k++; i++;
		}
		else {
			temp[k] = A[j];
			k++; j++;
		}
	}

	//Ensure all values were input
	while (i <= mid) {
		temp[k] = A[i];
		k++; i++;
	}

	while (j <= high) {
		temp[k] = A[j];
		k++; j++;
	}

	//Put sorted values back into array A
	for (i = low; i <= high; i++) {
		A[i] = temp[i - low];
	}
}
