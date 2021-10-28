/*
Musa Azeem
Completed: 9/24/21 - 00:54:09
This program defines multiple function to provide functionality to the primitive array type in C++
Inputs: Requires Array.h and Array.cpp for functions.
	First input n is a size to create an array of size n
	The next n inputs are values to populate the array
	The next input is a double value to insert into the array
	The next input is the index in which to insert the value jsut entered
	^last two lines twice again
	The next input is an index to remove the value at that index from the array
	The next input is an index to get the value at that index from the array
	The next input is an value to set in the array
	The next input is the index to set that value
	The next input is a value to find in the array
	The next input n is the size of a new array
	The next n inputs are values to populate this array
	The next input n is the size of another new array
	The next n inputs are values to populate this array

Outputs:Multiple outputs to cout to prompt inputs and printing a value or an array after modifications	
*/

#include <iostream>
#include "./Array.h"
using namespace std;

int main(int argv, char **arg){
	cout << "Enter size of the array: " << endl;
	int arrSize;
	cin >> arrSize;
	double *arr;

	//test init and print
	init(arr, arrSize);
	print(arr, arrSize);
	
	//test insert
	cout << "Enter a double to insert into the array, then the index where it will be inserted" << endl;
	double val;
	cin >> val;
	int index;
	cin >> index;
	insert(arr, arrSize, index, val);
	print(arr, arrSize);
	cout << arrSize << endl;

	cout << endl;
	cout << "Enter a double to insert into the array, then the index where it will be inserted" << endl;
	cin >> val;
	cin >> index;
	insert(arr, arrSize, index, val);	
	print(arr, arrSize);
	cout << arrSize << endl;
	
	cout << endl;
	cout << "Enter a double to insert into the array, then the index where it will be inserted" << endl;
	cin >> val;
	cin >> index;
	insert(arr, arrSize, index, val);	
	print(arr, arrSize);
	cout << arrSize << endl;
	
	cout << "Enter a double to insert into the array, then the index where it will be inserted" << endl;
	cin >> val;
	cin >> index;
	insert(arr, arrSize, index, val);	
	print(arr, arrSize);
	cout << arrSize << endl;
	

	//test remove
	cout << "Enter an index to remove the value at that index from the array" << endl;
	cin >> index;
	remove(arr, arrSize, index);
	print(arr, arrSize);
	cout << arrSize << endl;
	
	
	cout << "Enter an index to remove the value at that index from the array" << endl;
	cin >> index;
	remove(arr, arrSize, index);
	print(arr, arrSize);
	cout << arrSize << endl;

	//test get
	cout << "Enter an index to get the value of the array at that index" << endl;
	cin >> index;
	cout << get(arr, arrSize, index) << endl;
	
	//test set
	cout << "Enter a double to set in the array and then the index where it will be set" << endl;
	cin >> val;
	cin >> index;	
	set(arr, arrSize, index, val);
	print(arr, arrSize);
	
	//test find
	cout << "Enter a double to find in the array" << endl;
	cin >> val;
	cout << find(arr, arrSize,val) << endl;

	//equals
	int arrSize1,arrSize2;
	double *arr1, *arr2;
	cout << "Enter the size of arr1 and then enter values to populate it" << endl;
	cin >> arrSize1;
	init(arr1, arrSize1);
       	
	cout << "Enter the size of arr2 and then enter values to populate it" << endl;
	cin >> arrSize2;
	init(arr2, arrSize2);

	//cout << "Are arr1 and arr2 equal? " << equals(arr1, arrSize1, arr2, arrSize2) <<endl;

	//test clear
	clear(arr, arrSize);
	print(arr, arrSize);	
	cout << arrSize << endl;

	clear(arr1, arrSize1);
	print(arr1, arrSize1);	
	cout << arrSize1 << endl;

	clear(arr2, arrSize2);
	print(arr2, arrSize2);	
	cout << arrSize2 << endl;


	delete [] arr;
	delete [] arr1;
	delete [] arr2;
	return(0);
}
