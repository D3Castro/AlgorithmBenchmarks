#pragma once
class MergeSort
{
public:
	MergeSort(int *A, int low, int high);
	~MergeSort();

	void Merge(int *A, int low, int mid, int high);
};

