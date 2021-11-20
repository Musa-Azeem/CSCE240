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
    Alternate Constructor - initilizes object with given size
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
        if size is zero, data is set to null
        if size is nonzero but _data is null, data array is created but no values are assigned
        if size if nonzero and _data has values, data array is created of that size and set to values
    Input:  array and the size of the array
    Output: None
    */
    size = _size;
    if(size == 0){
        data = NULL;
        return;
    }
    data = new T[size];
    if(_data!=NULL){
        for(int i(0); i<size; i++){
            set(i, _data[i]);
        }
    }
    else{
        for(int i(0); i<size; i++){
            data[i] = {};   //works on c++ 11
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
    return(data[index]);
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
    return(rhs);
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
    return(ret);
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
    for(int index(0); index<ret.length()-rhs.length(); index++){
        if(ret.get(index)==start){
            bool rem(1);
            for(int i(index); i<index+rhs.length(); i++){
                if(ret.get(i)!=rhs[i-index])
                    rem=0;
            }
            if(rem){
                T *temp = new T[ret.length()-rhs.length()];
                for(int i(0); i<index; i++)
                    temp[i] = ret.get(i);
                for(int i(index+rhs.length()); i<ret.length(); i++)
                    temp[i-rhs.length()] = ret.get(i);
                
                delete [] ret.data;
                ret.data = temp;
                ret.size = ret.length()-rhs.length();

                index--;
            }
        }
    }
    return(ret);
}

template <class T>
T myArrayList<T>::operator[](const int index) const{
    /*
    Overlaods get [] operator - returns the value of data array at given index
    Input:  Index to get value at
    Output: Value at given index
    */
    if(index<0 || index >=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    return(data[index]);
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
    return(data[index]);
}

template <class U>
ostream & operator<<(ostream &lhs, const myArrayList<U> &rhs){
    /*
    Overloads the << operator - prints contents of rhs data to stdout
    Input:  instance ostream and instance of myArrayList to print
    Output: Modified ostream - prints data to stdout
    */
    if(rhs.isEmpty())
        return(lhs);
    for(int i(0); i<rhs.length(); i++){
        lhs << rhs[i] << " ";
    }
    return(lhs);
}

template <class U>
istream & operator>>(istream &lhs, myArrayList<U> &rhs){
    /*
    Overloads >> operator - takes n inputs for rhs of size n, setting each value in rhs data
        size of rhs must be previously set
    Input:  instance of istream and instance of myArrayList to set values of
    Output: Modified istream
    */
    for(int i(0); i<rhs.length(); i++){
        int inp;
        lhs >> rhs[i];
    }
    return(lhs);
}


template <class T>
void myArrayList<T>::print() const{
    for(int i(0); i<length(); i++){
        cout << get(i) << " ";
    }
    cout << endl;
}