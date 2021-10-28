#include <iostream>
#include "myString.h"

using namespace std;

myString::myString(){
    /*
    Default Constructor - creates an empty char array
    Inputs: None
    Output: None
    */
    size = 0;
    str = new char[size];
}
myString::myString(const int _size){
    /*
    Constructor - create char array of certain size
    Input:  Size of string
    Output: None
    */
    size = _size;
    str = new char[size];
}
myString::myString(const char _str[], const int _size){
    /*
    Constructor - create char array from a given array of a certain size
    Input:  Size of array, char array
    Output: None
    */
    size = _size;
    str = new char[size];
    for(int i=0; i<size; i++){
        set(i, _str[i]);
    }
}
myString::myString(const myString &rhs){
    /*
    Copy constructor - copies charr array of rhs into this instance of object
    Input:  Another instance of myString class
    Output: None - sets str array of this instance
    */
    size = rhs.length();
    str = new char[size];
    for(int i=0;i<size;i++){
        set(i, rhs.at(i));
    }
}
void myString::set(const int index, const char val){
    /*
    set value of str array at a given index. Will not set if index is out of range
    Input:  index to set and value and value to set
    Output: Prints error message if index is out of range - modifies str array
    */
    if(index<size && index>=0){
        str[index]=val;
    }
    else{
        cout << "Index out of range, value not set" << endl;
    }
}
char myString::at(const int index) const {
    /*
    Returns the value of the str array at a given index. Will end program if index is out of range
    Input:  Index to get value at
    Output: Returns char value - prints error message returns '0' if out of range
    */
    if(index<size && index>=0){
        return(str[index]);
    }
    else{
        cout << "Index out of range" << endl;
        return('0');
    }
}

int myString::length() const{
    /*
    returns size of str array
    Input:  None
    Output: int, size of array
    */
   return(size);
}

myString myString::substring(const int startIndex, const int length) const {
    /*
    returns a sub string of str
    Input:  index to start substring and length of the returned sub string
    Output: sub string of type myString
    */
   if(startIndex<0 || startIndex>=size || startIndex+length > size){
       //check that startIndex is valid and that length will not go out of bounds
       cout << "Index or length out of range" << endl;
       exit(1);
   }
   char ret[length];
   int retI(0);
   for(int i=startIndex; i<startIndex+length; i++){
       ret[retI] = at(i);
       retI++;
   }
   myString substr(ret, length);
   return(substr);
}

void myString::clear(){
    /*
    Clears str array 
        deallocates memory str currently points to, and allocates memory of an empty array instead
        sets size to 0
    Input:  None
    Output: None - modifies str array
    */
    delete [] str;
    size = 0;
    str = new char[size];
}

bool myString::empty() const{
    /*
    Returns 1 if the str array is empty and returns 0 if not
    Input:  None
    Output: boolean signifying whether or not the str array is empty
    */
    return(size==0);
}

int myString::find(const myString &substr, const int startIndex) const{
    /*
    Searches for a sub string within the str array
        starts by finding a char in str after or at the start index that matches the first char of the substr
        if the sub string of str following this char, of length of substr, is equal to substr, the substr has been found
        it then returns the start index of this sub string of str
        If the sub string is not equal to substr, the next char in the str array is looked at
        If substr is not found in str, -1 is returned
    Input:  A myString object and an integer index to start search from
    Output: Index that substr was found at - returns -1 if not found
    */
    char startChar = substr.at(0);
    int subLength = substr.length();
    if(startIndex+subLength > size){
        //not possibile for a substring of this length to be found with that start index
        return(-1);
    }
    for(int i=startIndex; i<(size+1)-subLength; i++){
        //loop from startIndex to the size of str +1 minus the length of substr, which is last index substr could possible be
        if(at(i)==startChar){
            //myString tempSubStr(substring(i,subLength));
            if(substring(i,subLength) == substr){
                return(i);
            }
        }
    }
    return(-1);
}

int myString::count(const myString &substr) const{
    /*
    Finds how many times the substr occurs - repeated substr overlapping another instance of substr are counted
        calls find function, starting from index 0 - if the function does not return -1, an instance of the substr was found
        if so, count is incremented to indicate another appearence of the substr
        index is also incremented, so that the next iteration the search starts from the next index up
        if find returns -1, no more substr occur, and current count is returned
    Input:  a myString object
    Output: count of number of times substr appears
    */
    int count(0);
    int index(0);
    while(1){
        index = find(substr, index);
        if(index == -1){
            break;
        }
        count++;
        index++;
    }
    return(count);
}


bool myString::equal(const myString &rhs) const{
    /*
    returns 1 if two myString objects are equal and returns 0 if not
    input:  instance of myString type
    Output: boolean signifying whether or not the myString objects are equal
    */
    if(length() != rhs.length()){
        return(0);
    }
    for(int i=0;i<size;i++){
        if(at(i)!=rhs.at(i)){
            return(0);
        }
    }
    return(1);
}

bool myString::add(const myString &other){
    /*
    concatonates two myString objects
        creates new temp char pointer array of the combined size of two arrays
        copies content from first myString and then the other onto temp
        sets this classes str array to point at the new combined array
    Input:  myString object
    Output: None - modifies str array
    */
    int otherLen(other.length());
    int newSize = size+otherLen;
    char *temp = new char[newSize];

    for(int i=0; i<size; i++){
        //copy contents of this myStrings str onto temp
        temp[i] = at(i);
    }
    for(int i=size; i<newSize; i++){
        //copy content of other myString str onto temp
        temp[i] = other.at(i-size);
    }
    delete [] str;  //deallocate memory of old str array
    size = newSize;
    str = temp;     //point str to the array temp points to
    return(1);
}

void myString::print() const{
    /*
    prints contents of str array
    Input:  None
    Output: prints contents of str array to stdout
    */
    for(int i=0; i<size;i++){
        cout << str[i];
    }
    cout << endl;
}

bool myString::operator==(const myString &other) const{
    /*
    Overloads == operator by calling equal method
    */
    return(equal(other));
}
myString::~myString(){
    /*
    deconstructor
    deallocates memory for str array
    */
    delete [] str;
}
