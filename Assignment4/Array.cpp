/*
Musa Azeem
Completed: 9/24/21 - 00:54:09
This program defines multiple function to provide functionality to the primitive array type in C++:
	insert: insert a value in an array
	remove: remove a value from an array
	get: get a value at an index in an array
	set: sets a value at an index in an array
	clear: clears all values from an array
	find: finds a value at the first index in an array
	equals: tests if two arrays are equal
	init: initializes an array with values from user input
	print: prints the contents of an array	
Inputs: No inputs. Requires Array.h for function prototypes. Several included funtions require array and value inputs
Outputs: Outputs of functions include values related to arrays and multiple cout statements
*/
#include <iostream>
#include "./Array.h"

using namespace std;

void insert(double *&arr, int &size, const int index, const double num){
    /*
    Function inserts a value at a specified location in an array, updating the size of the array.
    The given index may be anywhere within the array or the immediate end of the array. If it is beyond the size of the array,
        an error message will be printed
    Inputs: a pointer variable pointing to a double array, passed by reference
            the size of the array, an int, passed by reference
            the index, and int, where the value should be inserted
            the double value to be inserted into the array
    Output: If the given index is beyond the current range of the array, an error message is printed.
            This function directly modifies the value of the array and the size passed into it
    */
   //check if index is valid - the maximum index should be equal to the size of the array
    if(index>size || index < 0){
        cout << "The provided index value is out of range of the array." << endl;
        return;
    }

    //copy array into temporary array of new size and copy back to increment size
    double *temp = new double[size+1];
    for(int i(0); i<size;i++){
        temp[i] = arr[i];
    }
    
    delete [] arr;
    arr = new double[size+1];
    for(int i(0); i<size; i++){     //copy back values of array to new array of new size - last element is not assigned yet
        arr[i] = temp[i];
    }
    delete [] temp;
    size ++; //increment value of size, since this is the new size of the array 

    //insert new value by shifting other elements of array up an index to make an open spot at the given index
    for(int i(size-1);i>index;i--){        //shift elements up one index until the given index is reached
        arr[i] = arr[i-1];
    }
    arr[index] = num;                      //insert new value where the array stopped being shifted
}
void remove(double *&arr, int &size, const int index){
    /*
    This functions removes an element at a given index from an array, updating the size of the array. If the provided index is
    out of range of the array, an error message is printed
    Inputs: a pointer variable that points to a double array, passed by reference
            the size of the array, an int, passed by reference
            index, an int, of element to be removed
    Outputs:if given index is out of bounds, an error message is printed to cout.
            This function directly modifies the array and size passed into it.
    */
    if(index>size-1 || index <0){    //check for invalid index
        cout << "The provided index value is out of range of the array" << endl;
        return;
    }

    //remove element from array by shifting array elements down one index until the index of the element to be
    //removed, overwriting this element
    for(int i(index); i<size-1; i++){     //shift elements down one index
        arr[i] = arr[i+1];
    }
    //recreate array as an array with one less element by copying values to temp array, recreating arr, and copying back values
    double *temp = new double[size-1];
    for(int i(0); i<size-1; i++){
        temp[i] = arr[i];
    }
    delete [] arr;
    size --;                //decrement size for new array size
    arr = new double[size];
    for(int i(0); i<size; i++){    //copy values back to arr
        arr[i] = temp[i];
    }
    delete [] temp;
}

double get(double *arr, const int size, const int index){
    /*
    This function returns the value at a given index. It prints an error message if the given index is out of range of the array
    Inputs: a pointer variable that points to a double array
            the size of the array, an int
            the index, an int, of the element to be returned
    Outputs:returns the value, a double, at the given index
            If the provided index is out of range of the array, an error message is printed to cout and 0 is returned
    This function does not modify the array or size passed into it
    */
    if(index>size-1 || index <0){
        cout << "The provided index value is out of range of the array" << endl;
        return(0);
    }
    return(arr[index]);
}

void set(double *arr, const int size, const int index, const double num){
    /*
    This function sets the element of an array at a given index to a given value. An error message is printed
    if the given index is out of range of the array
    Inputs: a pointer variable that points to a double array
            the size of the array, an int
            the index of the array, an int, whose value is to be set
            the value, a double, that is set at the given index
    Output: if the given index is out of the range of the array, an error message is printed to cout
            this function directly modifies the array passed into it
    */
    if(index > size-1 || index <0){     //check if index is valid
        cout << "The provided index value is out of range of the array" << endl;
        return;
    }
    arr[index] = num;       //return element of array at index
}

void clear(double *&arr, int &size){
    /*
    This function clears an array of all values, and resets its size to 0
    Inputs: a pointer variable that points to a double array, passed by reference
            size of the array, passed by reference
    Outputs:This function directly modifies the array and size passed into it
    */
    //clear array by deleting it and creating new array of size 0
    delete [] arr;      //CHECK
    size = 0;
    arr = new double[size];
}

int find(double *arr, const int size, const double num){
    /*
    This function finds the first index of a given in an array. It returns -1 if the value is not found
    Inputs: a pointer variable that points to a double array
            size of the array, an int
            number to find, a double
    Outputs:Function returns the first index of the given value in the array
            Function returns -1 if the value is not found
    This function does not modify the array or the size passed into it
    */
    int foundIndex(-1);            //value stays at -1 if not found
    for(int i(0); i<size; i++){       //search for value in array with for loop. stop for loop if value is found
        if(arr[i] == num){
            foundIndex = i;
            break;
        }
    }
    return(foundIndex);
}

bool equals(double *arr1, const int size1, double *arr2, const int size2){
    /*
    This function checks if two arrays are equal
    Input:  first array - pointer variable that points to a double array
            size of first array, an int
            second array - pointer variable that points to a double array
            size of second array, an int
    Output: function returns true if the arrays are equal
            function returns false if the arrays are not equal
    This function does not modify the arrays or sizes passed into it
    */
    if(size1 != size2){      //first check if the sizes of the two arrays are equal. If not, return false because 
        return(false);              //they are not the same
    }

    bool equal = true;
    for(int i(0);i<size1;i++){    //compare each value in the arrays of same size
        if(arr1[i] != arr2[i]){       //if any of their elements are not equal, the arrays are not equal
            equal = false;
        }
    }
    return equal;
}

void init(double *&arr, const int size){
    /*
    This function initializes an array of a given size and recieves values from cin to populate it
    Inputs: pointer variable that points to a double array, passed by reference
            size of the array
            elements of array from cin
    Outputs:Function directly modifies the array passed into it
    */
    arr = new double[size];
    int val;
    cout << "Enter " << size << " values to populate the array: ";
    for(int i(0); i<size;i++){
        cin >> val;
        arr[i] = val;
    }
    cout << endl;
}

void print(double *arr, const int size){
    /*
    This function prints out an array to cout
    Inputs: A pointer variable pointing to a double array
            The size of the array
    Output: no return value. Outputs the elements of the array to cout
    Function does not modify the array or size passed into it
    */
    for(int i(0); i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
