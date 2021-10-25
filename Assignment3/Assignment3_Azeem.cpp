/*
Musa Azeem
Date Completed: 9/10/21
Time Completed: 20:32:41

This program sorts an array of doubles by ascending order and calculates statistics for the array, 
including the minimum, maximum, mean, and median. 

Inputs: The inputs to the program are the size of the array and the elements of the array. The size of the array should
be the first input, followed by the elements of the array, deliminated by whitespace.

Output: The output of the program is the inital array, the array in sorted format, and the minimum, maximum, mean, and median
values of the array. The initial array is the first output, followed by the sorted array, followed by the statistics
in the order mentioned.
*/

#include <iostream>
using namespace std;

void readArray(double arr[], const int size);
void printArray(const double arr[], const int size);
void sort(double arr[], const int size);
void basicStatistic(const double arr[], const int size);
double min(const double arr[], const int size);
double max(const double arr[], const int size);
double mean(const double arr[], const int size);
double median(const double arr[], const int size);



int main(int argc, char **args){
    //get size and initialize array
    int tempSize;
    cout << "Please enter the size of your array: ";
    cin >> tempSize;
    const int arrSize(tempSize);
    double arr[arrSize];

    //get values, populate array, and output it
    cout << "Please enter " << arrSize << " elements to populate the array." << endl; 
    readArray(arr, arrSize);
    cout << endl << "The elements of the array are: " << endl;
    printArray(arr, arrSize);

    //sort array, output result
    sort(arr, arrSize);
    cout << "The elements of the array sorted in ascending order: " << endl;
    printArray(arr, arrSize);

    //output statistics
    cout << endl;
    basicStatistic(arr, arrSize);
}

void readArray(double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array. 
    It then recieves the specfied number of inputs (based on the size of the array) from the console or a file to populate the array.
    This function does not return a value, it directly modifies the array passed into it.
    */
    for(int i(0); i<size; i++){
        cin >> arr[i];
    }
}

void printArray(const double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array.
    It then uses this size to loop through every element in the array and outputs them
    This function outputs the elements of the array and does not modify the array passed into it
    */
    for(int i(0); i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array.
    It then sorts the array in ascending order using the bubble sort algorithm.
    This function does not produce any output, it simply modifies the array passed into it
    */
    bool swapped(true);
    while(swapped){
        swapped = false;
        for(int i(0); i<size-1; i++){
            if(arr[i] > arr[i+1]){
                double temp(arr[i]);
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    }
}

void basicStatistic(const double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array
    It calls upon other functions, passing in the array and its size to them, to get the minimum, maximum, mean, and 
    median values of the array.
    The function outputs these values
    This function does not return a value or modify the array passed into it
    */

    //call statistic methods and print
    cout << "The min of the array is: " << min(arr, size) << endl;
    cout << "The max of the array is: " << max(arr, size) << endl;
    cout << "The mean of the array is: " << mean(arr, size) << endl;
    cout << "The median of the array is: " << median(arr, size) << endl;
}

double min(const double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array
    It then uses a loop to find the smallest value in the array
    This function returns the minimum value of the array, and does not modify the array
    */
    double smallest = arr[0];
    for(int i(1); i<size; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    return(smallest);
}

double max(const double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array
    It then uses a loop to find the largest value in the array
    This function returns the maximum value of the array, and does not modify the array
    */
    double largest(arr[0]);
    for(int i(1); i<size; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return(largest);
}

double mean(const double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array
    It then uses a loop to find the mean value of the array
    This function returns the mean value of the array, and does not modify the array
    */
    double total(0);
    double mean;
    for(int i(0); i<size; i++){
        total += arr[i];
    }
    mean = total / size;
    return(mean);

}

double median(const double arr[], const int size){
    /*
    This function takes in a reference to an array and the size of this array
    It then uses the known size of the array to create a clone of the array in order to manipulate it
    The sort function defined previously is then called to sort the clone of the array
    The known size of the array is used to find the middle element
    If the array has an even number of elements, the median is calculated by taking the mean of the two middle elements
    This function returns the median value of the array, and does not modify the original array passed into the function
    */

    //clone the array
    double tempArr[size];
    for(int i=0; i<size; i++){
        tempArr[i] = arr[i];
    }
    sort(tempArr, size); //sort the clone of the array

    double median;
    if(size%2 == 0){
        median = (tempArr[size/2-1] + tempArr[size/2]) / 2;
    }
    else{
        median = tempArr[size/2];
    }
    return(median);
}