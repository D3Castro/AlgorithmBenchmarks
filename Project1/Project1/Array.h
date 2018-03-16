#ifndef ARRAY_H
#define ARRAY_H
class Array
{
public:
	Array(); //Default Constructor for the class
	Array(int); //Copy Constructor with size
	~Array(); //Destructor for the class

	//	Returns the size of the array. (sizeOfArry)
	int getSize(); 

	//	Displays the content of the array. [0,1,2,3...n]
	void displayArray();

	//	Inverse the order of the array.
	void reverseArray(); 

	/**
		Swaps two elements in the array.

		@param int The location of the variable in the array
	*/
	void swapElements(int, int); //Swap two elements in the array

	//	Fill the array with values sorted in order.
	void sortedFill(); 

	//	Fill the array with random values.
	void randFill(); 

	//	Fill the array with sorted values then shuffle it 10%.
	void partialRFill(); 

	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void MergeSort(int low, int high);
	void Merge(int low, int mid, int high);
	void QuickSort(int low, int high);
	int partition(int low, int high);

	int sizeOfArry; //Array size
	int *arrData; //integer Array

protected:
private:
};
#endif // ARRAY_H