/**
	Project1.cpp
	
	Purpose: Calculates the runtime of a user selected sorting algorithm on a array of user selected size n and sortedness. The
	runtime will be output in the form of Mean, Median, Mode, and Standard Deviation in nanoseconds, microseconds, and milliseconds. 
	A copy of this information will also be written to a file Data.txt for analysis purposes.

	@author Daniel Castro 
	@author Zachary Andersen
*/

#include "stdafx.h"

/**
	Returns the standard deviation of a vector.

	@param V Vector containing time values.
	@param mean The mean of the values in the vector
	@return The standard deviation
*/
double standardDev(std::vector<double>* V, double mean)
{
	//	Gets the squares of each value. 
	//	Squares = Squares + (currV)*(currV)
	double squares = inner_product(V->begin(), V->end(), V->begin(), 0.0);
	//	Standard deviation formula
	double result = sqrt(squares / V->size() - mean * mean);

	return result;
}

/**
	Returns the mode of a vector.

	@param V Vector containing time values.
	@return The mode.
*/
double findMode(vector<double>& V)
{
	int oldMode = 0;
	int oldCount = 0;
	for (size_t n = 0; n < V.size(); ++n)
	{
		int testMode = V.at(n);
		int currCount = count(V.begin() + n + 1, V.end(), testMode);

		if (currCount > oldCount)
		{
			oldMode = testMode;
			oldCount = currCount;
		}
	}
	return oldMode;
}

/**
	Returns the median of a vector.

	@param V Vector containing time values.
	@return The median.
*/
double findMedian(vector<double>& V)
{
	size_t n = V.size() / 2;
	//Gets the element that would be at location V.begin() + n in a sorted sequence.
	nth_element(V.begin(), V.begin() + n, V.end());
	int Vn = V.at(n);

	//Case: vector size is odd
	if (V.size() % 2 == 1)
	{
		return Vn;
	}
	//Case: vector size is even
	else
	{
		nth_element(V.begin(), V.begin() + n - 1, V.end());
		return 0.5*(Vn + V[n - 1]);
	}
}

/**
	Returns the runtime of a specified algorithm given an array.

	@param algoOpt The sorting algorithm that will be run.
	@param arr Array of values to sort.
	@param algoStr A string value of the algorithm name.
	@return The runtime in nanoseconds of the specified sorting algorithm.
*/
double runTest(int algoOpt, Array* arr, string& algoStr)
{
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	switch (algoOpt) {
	case 1:
		t1 = high_resolution_clock::now();
		arr->InsertionSort();
		t2 = high_resolution_clock::now();
		algoStr = "Insertion Sort";
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	case 2:
		t1 = high_resolution_clock::now();
		arr->SelectionSort();
		t2 = high_resolution_clock::now();
		algoStr = "Selection Sort";
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	case 3:
		t1 = high_resolution_clock::now();
		arr->BubbleSort();
		t2 = high_resolution_clock::now();
		algoStr = "Bubble Sort";
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	case 4:
		t1 = high_resolution_clock::now();
		arr->QuickSort(0, arr->getSize());
		t2 = high_resolution_clock::now();
		algoStr = "Quick Sort";
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	default:
		t1 = high_resolution_clock::now();
		arr->MergeSort(0, arr->getSize());
		t2 = high_resolution_clock::now();
		algoStr = "Merge Sort";
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	}
}

int main()
{
	srand(time(NULL));
	double mean, median, mode, standardDeviation;
	vector<double>* times = new vector<double>;		//Times of each iteration of the sorting algorithm
	int sizeOpt, arrOpt, algoOpt;					//Values for user selection during run time
	string sizeStr, arrStr, algoStr;				//String values of user selection during run time
	Array* arr;										//Array to store values to be sorted

	//ios::app used to prevent overwriting data already stored
	ofstream odata("Data.txt", ios::app);

	//Ensure file integrity
	if (!odata.is_open()) {
		cout << "Error opening file.";
		return 0;
	}
	
	do {
		mean = 0, median = 0, mode = 0, standardDeviation = 0;

		system("CLS");	//Clear screen
		cout << "Welcome, this program will calculate the run time of a chosen algorithm over an array of chosen size and order."
			 <<	"\nEnter the number value of your option or -1 to exit. Note: Any erroneous input will default to option 1.\n\n";
		cout << "ARRAY SIZE:\n[1]10\n[2]1,000\n[3]10,000\n[4]100,000\n[5]1,000,000\nOption:";
		cin >> sizeOpt;
		if (sizeOpt == -1)
			break;
		cout << "\nARRAY TYPE:\n[1]Sorted\n[2]Full Shuffle\n[3]Reversed\n[4]Partial Shuffle\nOption:";
		cin >> arrOpt;
		if (arrOpt == -1)
			break;
		cout << "\nSORTING ALGORITHM:\n[1]Insertion Sort\n[2]Selection Sort\n[3]Bubble Sort\n[4]Quick Sort\n[5]Merge Sort\nOption:";
		cin >> algoOpt;
		if (algoOpt == -1)
			break;

		//To prevent issues with erroneous user input all default values will be option 1.
		//Set the sizeOpt and sizeStr to actual size value.
		switch (sizeOpt) {
			case 2:
				sizeStr = "1,000";
				sizeOpt = 1000;
				break;
			case 3:
				sizeStr = "10,000";
				sizeOpt = 10000;
				break;
			case 4:
				sizeStr = "100,000";
				sizeOpt = 100000;
				break;
			case 5:
				sizeStr = "1,000,000";
				sizeOpt = 1000000;
				break;
			default:
				sizeStr = "10";
				sizeOpt = 10;
				break;
		}

		//Create a new array of sizeOpt
		arr = new Array(sizeOpt);

		//Fill the array based on arrOpt and then utilize runTest to run the algorithm and get run time
		switch (arrOpt) {
			case 2:
				arrStr = "Fully Shuffled";
				for (int i = 0; i < 100; i++) {
					arr->randFill();
					times->push_back(runTest(algoOpt, arr, algoStr));
					mean += times->back();
				}
				break;
			case 3:
				arrStr = "Reversed";
				for (int i = 0; i < 100; i++) {
					arr->reverseArray();
					times->push_back(runTest(algoOpt, arr, algoStr));
					mean += times->back();
				}
				break;
			case 4:
				arrStr = "Partially Shuffled";
				for (int i = 0; i < 100; i++) {
					arr->partialRFill();
					times->push_back(runTest(algoOpt, arr, algoStr));
					mean += times->back();
				}
				break;
			default:
				arrStr = "Sorted";
				for (int i = 0; i < 100; i++) {
					arr->sortedFill();
					times->push_back(runTest(algoOpt, arr, algoStr));
					mean += times->back();
				}
		}

		//Calculate Mean, Median, Mode, and Standard Deviation
		mean /= 100;
		median = findMedian(*times);
		mode = findMode(*times);
		standardDeviation = standardDev(times, mean);

		//Output to command line
		cout << endl << arrStr << " array of size " << sizeStr << " using " << algoStr << ".\n"
			 << "Mean:\t\t\t " << mean << " ns\t " << mean / 1000 << " "  << char(230) << "s\t " << mean / 1000000 << " ms\n"
		     << "Median:\t\t\t " << median << " ns\t " << median / 1000 << " " << char(230) << "s\t " << median / 1000000 << " ms\n"
			 << "Mode:\t\t\t " << mode << " ns\t " << mode / 1000 << " " << char(230) << "s\t " << mode / 1000000 << " ms\n"
			 << "Standard Deviation:\t " << standardDeviation << " ns\t " << standardDeviation / 1000 << " " << char(230) << "s\t " << standardDeviation / 1000000 << " ms\n";

		//Output to file, flush is used to ensure data is written to file even in the case of a force exit
		odata << arrStr << " array of size " << sizeStr << " using " << algoStr << ".\n"
			  << "Mean:\t\t\t " << mean << " ns\t " << mean / 1000 << " " << char(230) << "s\t " << mean / 1000000 << " ms\n"
			  << "Median:\t\t\t " << median << " ns\t " << median / 1000 << " " << char(230) << "s\t " << median / 1000000 << " ms\n"
			  << "Mode:\t\t\t " << mode << " ns\t " << mode / 1000 << " " << char(230) << "s\t " << mode / 1000000 << " ms\n"
			  << "Standard Deviation:\t " << standardDeviation << " ns\t " << standardDeviation / 1000 << " " << char(230) << "s\t " << standardDeviation / 1000000 << " ms\n\n"
			  << flush;

		//Delete the array and clear the vector to prevent any data carry over.
		delete arr;
		times->clear();

		cout << "\n\nPress enter to restart program...";
		getchar();
		cin.get();

	} while (true);

	odata.close();
	return 0;
}
