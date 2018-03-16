# AlgorithmBenchmarks - Project 1

Calculates the runtime of a user selected sorting algorithm on a array of user selected size n and sortedness. The
runtime will be output in the form of Mean, Median, Mode, and Standard Deviation in nanoseconds, microseconds, and milliseconds. 
A copy of this information will also be written to a file Data.txt for analysis purposes.
	
# How to use 

When the program is executed the user will be prompted to input a size for the array from the list n=10, 1000, 10000, 100000, 1000000.
Next the user will select the type of array from the list type=sorted, completely shuffled, reversed, partially shuffled.
Next the user will select the sorting algorithm to use from the list algorithm=insertion, selection, bubble, quick, merge.

In the case the user inputs -1 for any of these values the program will exit. If an erroneous value is input the program will use option
1 as the default to prevent runtime errors. 

After the selections have been made the Mean, Median, Mode, and Standard Deviation will be output in the command line as well as the file
in nanoseconds, microseconds, and milliseconds.

The program will pause until enter is pressed, at which point it will restart.

# Files

stdafx.h and stdafx.cpp	: Precompiled header and cpp file with the includes necessary to run the program.
Array.h and Array.cpp	: Contains the Array class which has the functions for every type of array and sorting algorithm.
main.cpp				: Contains functions to calculate time anlaysis measurements as well as the main control of the program.