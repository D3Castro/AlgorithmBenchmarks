#include <iostream>
#include <chrono>
#include <fstream>
#include "stdafx.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

//TO-DO -- Implement Merge/Quick sorts
//		-- Get actual metrics 

// NOTE -- WHEN TESTING MERGESORT/QUICKSORT INPUT N-1 AS SIZE
using namespace std;
using namespace std::chrono;


int main()
{
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//Do something
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//Calculate run time
	//auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	
	ofstream odata;
	odata.open(""/*Placeholder*/);
	//odata << "Placeholder Algorithm (Placeholder Array of Size Placeholder) << duration << endl;

	//Sorted Array size 10
	const int *arr = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };
	


	odata.close();

}
