#include "stdafx.h"

double standardDev(std::vector<double>* V, double mean)
{
	double squares = inner_product(V->begin(), V->end(), V->begin(), 0.0);
	double result = sqrt(squares / V->size() - mean * mean);
	V->clear();

	return result;
}

double runTest(int algoOpt, Array* arr)
{
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	switch (algoOpt) {
	case 1:
		t1 = high_resolution_clock::now();
		arr->InsertionSort();
		t2 = high_resolution_clock::now();
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	case 2:
		t1 = high_resolution_clock::now();
		arr->SelectionSort();
		t2 = high_resolution_clock::now();
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	case 3:
		t1 = high_resolution_clock::now();
		arr->BubbleSort();
		t2 = high_resolution_clock::now();
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	case 4:
		t1 = high_resolution_clock::now();
		arr->QuickSort(0, arr->getSize());
		t2 = high_resolution_clock::now();
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	default:
		t1 = high_resolution_clock::now();
		arr->MergeSort(0, arr->getSize());
		t2 = high_resolution_clock::now();
		return (double)duration_cast<nanoseconds>(t2 - t1).count();
	}
}

int main()
{
	srand(time(NULL));
	double mean;
	double standardDeviation;
	vector<double>* times = new vector<double>;
	
	ofstream odata;
	odata.open("Data.txt");
	//Ensure file integrity
	if (!odata.is_open()) {
		cout << "Error opening file.";
		return 0;
	}

	int sizeOpt;
	int arrOpt;
	int algoOpt;
	Array* arr;
	
	do {
		mean = 0;
		standardDeviation = 0;

		system("CLS");
		cout << "Program opener.\n\n";
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

		switch (sizeOpt) {
			case 2:
				sizeOpt = 1000;
				break;
			case 3:
				sizeOpt = 10000;
				break;
			case 4:
				sizeOpt = 100000;
				break;
			case 5:
				sizeOpt = 1000000;
				break;
			default:
				sizeOpt = 10;
				break;
		}

		arr = new Array(sizeOpt);
		switch (arrOpt) {
			case 2:
				for (int i = 0; i < 100; i++) {
					arr->randFill();
					times->push_back(runTest(algoOpt, arr));
					mean += times->back();
				}
				break;
			case 3:
				for (int i = 0; i < 100; i++) {
					arr->reverseArray();
					times->push_back(runTest(algoOpt, arr));
					mean += times->back();
				}
				break;
			case 4:
				for (int i = 0; i < 100; i++) {
					arr->partialRFill();
					times->push_back(runTest(algoOpt, arr));
					mean += times->back();
				}
				break;
			default:
				for (int i = 0; i < 100; i++) {
					arr->sortedFill();
					times->push_back(runTest(algoOpt, arr));
					mean += times->back();
				}
		}

		//Calculate Mean and Standard Deviation
		mean /= 100;
		standardDeviation = standardDev(times, mean);

		cout << "Mean:\t\t\t " << mean << " ns\t " << mean / 1000 << " "  << char(230) << "s\t " << mean / 1000000 << " ms\n";
		cout << "Standard Deviation:\t " << standardDeviation << " ns\t " << standardDeviation / 1000 << " " << char(230) << "s\t " << standardDeviation / 1000000 << " ms\n";;

		delete arr;
		cout << "\n\nPress enter to restart program...";
		getchar();
		cin.get();

	} while (true);

	odata.close();
	return 0;
}
