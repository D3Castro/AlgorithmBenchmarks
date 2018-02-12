#pragma once
class QuickSort
{
public:
	QuickSort(int *A, int low, int high);
	~QuickSort();

	int partition(int *A, int low, int high);
	void swapElements(int *A, int x, int y);
};

