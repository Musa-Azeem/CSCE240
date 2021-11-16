#ifndef MYARRAYLIST_H
#include "myArrayList.h"
#endif

using namespace std;

template <class T>
myArrayList<T>::myArrayList(){
    /*
    Default Constructor - initilizes object with null array and size 0
    Input:  None
    Output: None
    */
    init(NULL, 0);
}

template <class T>
myArrayList<T>::myArrayList(const int _size){
    /*
    Alternate Constructor - initilizes object with null array and given size
    Input:  Size to create object
    Output: None
    */
    init(NULL, _size);
}

template <class T>
myArrayList<T>::myArrayList(const T _data[], const int _size){
    /*
    Alternate Constructor - initilizes object with given array and size
    Input:  Array of data and size of array
    Output: None
    */
    init(&_data, _size);
}

template <class T>
myArrayList<T>::myArrayList(const myArrayList<T> &rhs){
    /*
    Copy Constructor - initilizes object using data and size of another instance
    Input:  Instance of myArrayList object
    Output: None
    */
    init(rhs.data, rhs.length());
}

template <class T>
void myArrayList<T>::init(const T _data[], const int _size){
    /*
    Initializes data and size with values given from constructors
    Input:  array and the size of the array
    Output: None
    */
    size = _size;
    if(_data==NULL){
       data = NULL;
    }
    else{
        for(int i(0); i<size; i++){
            set(i, _data[i]);
        }
    }
}

template <class T>
myArrayList<T>::~myArrayList(){
    /*
    Deconstructor - deallocates memory of data
    Input:  None
    Output: None
    */
    delete [] data;
}

template <class T>
void myArrayList<T>::set(const int index, const T value){
    if(index<0 || index >=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    data[index] = value;
}