#ifndef ARRAY_H
#define ARRAY_H
class Array
{
public:
	Array(); //Default Constructor for the class
	Array(int); //Copy Constructor with size
	~Array(); //Destructor for the class

	int getSize(); //Function to access the size
	void displayArray(); //Display the content of the array
	void reverseArray(); //Function to Inverse the order of the elements in the array
	void swapElements(int, int); //Swap two elements in the array

	void sortedFill(); //Fill the array with sorted values
	void randFill(); //Fill the array with random values
	void partialRFill(); //Fill the array partially shuffled 10%

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