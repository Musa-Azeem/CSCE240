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
    init(_data, _size);
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
    Initializes data and size with values given
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
    /*
    Sets data array to given value at given index
    Modifies data array
    Input:  value to set and index of where to set value
    Output: None
    */
    if(index<0 || index >=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    data[index] = value;
}

template <class T>
T myArrayList<T>::get(const int index) const{
    /*
    Returns the value of data array at given index
    Input:  int Index
    Output: value at given index
    */
    if(index<0 || index >=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }

    return data[index];
}

template <class T>
int myArrayList<T>::length() const{
    /*
    Returns size variable, the length of the data array
    Input:  None
    Output: size of data array
    */
    return size;
}

template <class T>
void myArrayList<T>::clear(){
    /*
    Clears data array and sets size to 0
    Modifies data array
    Input:  None
    Output: None
    */
    delete [] data;
    init(NULL, 0);
}

template <class T>
bool myArrayList<T>::isEmpty() const{
    /*
    Returns true if the data array is empty - data array is NULL
    Modifies data array
    Input:  None
    Output: None
    */
    return(data==NULL);
}

template <class T>
const myArrayList<T> & myArrayList<T>::operator=(const myArrayList<T> &rhs){
    /*
    Overloads assignment operator - copies size and data array of rhs of assignment operator (instance of myArrayList)
    Returns the rhs for cascading
    Input:  Instance of myArrayList to set calling object equal to
    Output: Instance of myArrayList for cascading
    */
    delete [] data;
    size = rhs.length();
    init(rhs.data, size);
}

template <class T>
bool myArrayList<T>::operator==(const myArrayList<T> &rhs) const{
    /*
    Overloads == operator - checks if two instances have equal data and size
    Input:  instance of myArrayList to compare to
    Ouptut: bool - 1 if equal, 0 if not
    */
    if(size != rhs.length())
        return(0);
    for(int i(0); i<size; i++){
        if(get(i) != rhs[i])
            return(0);
    }
    return(1);
}
template <class T>
bool myArrayList<T>::operator!=(const myArrayList<T> &rhs) const{
    /*
    Overloads != operator - returns opposite of operator==
    Input:  Instance of myArrayList to compare to
    Output: bool - 1 if not equal, 0 if equal
    */
    return(!operator==(rhs));
}

template <class T>
const myArrayList<T> myArrayList<T>::operator+(const myArrayList<T> &rhs) const{
    /*
    Overloads addition operator - returns new instance of myArrayList with the rhs concatonated to calling object
    Input:  Instance of myArrayList to concatonate to end of calling object on new instance
    Output: New instance of myArrayList
    */
    myArrayList<T> ret(size+rhs.length());
    for(int i(0); i<length(); i++){
        ret[i] = get(i);
    }
    for(int i(length()); i<length()+rhs.length(); i++){
        ret[i] = rhs[i-length()];
    }
}

template <class T>
const myArrayList<T> myArrayList<T>::operator-(const myArrayList<T> &rhs) const{
    /*
    Overloads subtraction operator - returns a copy of calling object with any occurance of rhs removed
    Input:  Instance of myArrayList to remove from calling object
    Ouptut: New instance of myArrayList
    */
    myArrayList<T> ret(*this);
    if(rhs.length() > length()){
        return(ret);
    }
    T start = rhs[0];
    for(int i(0); i<length(); i++){
    }
}

template <class T>
const T myArrayList<T>::operator[](const int index) const{
    /*
    Overlaods get [] operator - returns the value of data array at given index
    Input:  Index to get value at
    Output: Value at given index
    */
    if(index<0 || index >=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    return(get(index));
}

template <class T>
T & myArrayList<T>::operator[](const int index){
    /*
    Overlaods set [] operator - returns referance of index of data array to be set 
    modifies data array
    Input:  Index to set value at
    Output: reference to data array to set at given index
    */
    if(index<0 || index >=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    return(get(index));
}