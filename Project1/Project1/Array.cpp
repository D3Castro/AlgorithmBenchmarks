#include "stdafx.h"
#include "Array.h"

using namespace std;

Array::Array() {} //Default Constructor for the class

Array::Array(int value) //Copy Constructor with size
{
	sizeOfArry = value; //User Pass size
	arrData = new int[sizeOfArry];
	for (int i = 0; i<sizeOfArry; i++)
		arrData[i] = i;
}

Array::~Array() { } // Destructor for the class

int Array::getSize()
{
	return sizeOfArry;
}

void Array::displayArray()
{
	cout << "[";
	for (int i = 0; i<sizeOfArry; i++)
		cout << arrData[i] << ", ";
	cout << "]";
}

void Array::reverseArray()
{
	int temp;
	for (int i = 0; i<sizeOfArry / 2; i++)
	{
		temp = arrData[i];
		arrData[i] = arrData[sizeOfArry - i - 1];
		arrData[sizeOfArry - i - 1] = temp;
	}
}

void Array::swapElements(int x, int y) 
{
	int temp;
	temp = arrData[x];
	arrData[x] = arrData[y];
	arrData[y] = temp;
}

void Array::sortedFill()
{
	for (int i = 0; i<sizeOfArry; i++)
		arrData[i] = i;
}

void Array::randFill()
{
	int i = 0;
	while (i < sizeOfArry) {
		arrData[i] = rand() % 100;
		i++;
	}
}

void Array::partialRFill()
{
	int swapI, temp;
	int toShuffle = int(sizeOfArry * .1);
	while (toShuffle >= 0) {
		swapI = rand() % sizeOfArry;
		temp = arrData[toShuffle];
		arrData[toShuffle] = arrData[swapI];
		arrData[swapI] = temp;
		toShuffle--;
	}

}

void Array::BubbleSort()
{
	for (int i = 0; i < sizeOfArry - 1; i++) {
		for (int j = 0; j < sizeOfArry - i - 1; j++) {
			if (arrData[j] > arrData[j + 1])
				this->swapElements(j, j + 1);
		}
	}
}

void Array::InsertionSort()
{
	int j;

	for (int i = 0; i < sizeOfArry; i++) {
		j = i;

		while (j > 0 && arrData[j] < arrData[j - 1]) {
			this->swapElements(j, j - 1);
			j--;
		}
	}
}

void Array::SelectionSort()
{
	int minIndex;

	for (int i = 0; i < sizeOfArry - 1; i++) {
		minIndex = i;

		for (int j = i + 1; j < sizeOfArry; j++) {
			if (arrData[j] < arrData[minIndex])
				minIndex = j;
		}

		this->swapElements(minIndex, i);
	}

}

void Array::MergeSort(int low, int high)
{
	int mid;

	if (low < high) {
		mid = (low + high) / 2;

		//Split the data
		MergeSort(low, mid);
		MergeSort(mid + 1, high);

		//Merge data to sort
		Merge(low, mid, high);
	}
}

void Array::Merge(int low, int mid, int high)
{
	int *temp = new int[high - low + 1];
	int i = low;
	int k = 0;
	int j = mid + 1;

	//Sort while merging
	while (i <= mid && j <= high) {
		if (arrData[i] < arrData[j]) {
			temp[k] = arrData[i];
			k++; i++;
		}
		else {
			temp[k] = arrData[j];
			k++; j++;
		}
	}

	//Ensure all values were input
	while (i <= mid) {
		temp[k] = arrData[i];
		k++; i++;
	}

	while (j <= high) {
		temp[k] = arrData[j];
		k++; j++;
	}

	//Put sorted values back into array A
	for (i = low; i <= high; i++) {
		arrData[i] = temp[i - low];
	}
}

void Array::QuickSort(int low, int high)
{
	if (low < high) {
		int partitionIndex = partition(low, high);

		QuickSort(low, partitionIndex - 1);
		QuickSort(partitionIndex + 1, high);
	}
}

int Array::partition(int low, int high)
{
	int pivot = arrData[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (arrData[j] <= pivot) {
			i++;
			this->swapElements(i, j);
		}
	}

	this->swapElements(i + 1, high);

	return i + 1;
}