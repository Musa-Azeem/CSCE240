/*
Musa Azeem
Completed: 9/24/21 - 00:54:09
This program prototypes functions that are defined in Array.h
Inputs: No inputs
Outputs: No outputs
*/
using namespace std;

void insert(double *&arr, int &size, const int index, const double num);
void remove(double *&arr, int &size, const int index);
double get(double *arr, const int size, const int index);
void set(double *arr, const int size, const int index, const double num);
void clear(double *&arr, int &size);
int find(double *arr, const int size, const double num);
bool equals(double *arr1, const int size1, double *arr2, const int size2);
void init(double *&arr, const int size);
void print(double *arr, const int size);