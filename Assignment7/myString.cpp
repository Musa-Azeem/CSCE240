/*
Musa Azeem
Completed 11/11/2021 - 17:03:27
This program defines functionality of the myString object
Inputs: Several functions require input from main and/or stdin
Ouput:  Several functions return data or print data to stdout
*/
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
    Constructor - create char array of certain size, each element is an empty space
    Input:  Size of string
    Output: None
    */
    size = _size;
    str = new char[size];
    for(int i(0); i<size; i++){
        set(i, ' ');
    }
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
    Copy constructor - copies char array of rhs into this instance of object
    Does not modify rhs
    Input:  Another instance of myString class
    Output: None
    */
    size = rhs.length();
    str = new char[size];
    for(int i=0;i<size;i++){
        set(i, rhs.at(i));
    }
}
myString::~myString(){
    /*
    deconstructor
    deallocates memory for str array
    */
    delete [] str;
}
void myString::set(const int index, const char val){
    /*
    set value of str array at a given index. Terminates program if index is out of range
    Directly modifies str array
    Input:  index to set and value and value to set
    Output: Prints error message if index is out of range
    */
    if(index<size && index>=0){
        str[index]=val;
    }
    else{
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
}
char myString::at(const int index) const {
    /*
    Returns the value of the str array at a given index. Terminates program if index is out of range
    Does not modify object
    Input:  Index to get value at
    Output: Returns char value - prints error message and exits if out of range
    */
    if(index<size && index>=0){
        return(str[index]);
    }
    else{
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }

}

int myString::length() const{
    /*
    returns size of str array - does not modify object
    Input:  None
    Output: int, size of array
    */
   return(size);
}

const myString myString::substring(const int startIndex, const int length) const {
    /*
    returns a sub string of str of length "length", starting from startIndex
        Does not modify object
    Input:  index to start substring and length of the sub string
    Output: sub string of type myString
    */
   if(startIndex<0 || startIndex>=size || startIndex+length > size){
       //check that startIndex is valid and that length will not go out of bounds
       cout << "Index or length out of range: exit status 1" << endl;
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
    Output: None
    */
    delete [] str;
    size = 0;
    str = new char[size];
}

bool myString::empty() const{
    /*
    Returns 1 if the str array is empty and returns 0 if not
    Does not modify object
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
    Does not modify calling object or object passed as argument
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
    Finds how many times the substr occurs - repeated substr overlapping another occurance of substr are counted
        calls find function, starting from index 0 - if the function does not return -1, an instance of the substr was found
        if so, count is incremented to indicate another appearence of the substr
        index is then incremented, to start next search from the next index up
        if find returns -1, no more substr occur, and current count is returned
    Does not modify calling object or object passed as argument
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
    Does not modify calling object or object passed as argument
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
    concatonates myString passed as argument to the end of calling myString object
        creates new temp char pointer array of the combined size of two arrays
        copies content from first myString and then the other onto temp
        sets calling objects's str array to point at the new combined array
    Does not modify object passed as argument
    Input:  myString object
    Output: None
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

void myString::remove(const int index, const int length){
    /*
    Removes a section of str array
        starts removal at given index and removes a substring of the given length
        Terminates program if the given start index is invalid or if there is no possible substring of that length starting at that index

    Input:  int start index, int remove length
    Output: prints error message if index is invalid
    */
    if(index < 0 || index >= size || index+length > size){
        cout << "Index or length out of range: exit status 1" << endl;
        exit(1);
    }
    char *temp;
    int newSize = size-length;
    temp = new char[newSize];
    for(int i=0; i<index; i++){
        temp[i] = at(i);                //copy elements of str until the index
    }
    for(int i=index+length; i<size; i++){   //start copying again after index+length, skipping elements to be removed
        temp[i-length] = at(i);             //add elements from str to immediate next index of temp
    }
    delete [] str;
    str = temp;
    size = newSize; 
}

void myString::print() const{
    /*
    prints contents of str array to stdout
    Does not modify object
    Input:  None
    Output: prints contents of str array to stdout
    */
    for(int i=0; i<size;i++){
        cout << str[i];
    }
    cout << endl;
}
const myString & myString::operator=(const myString &rhs){
    /*
        Overloads = operator
            deletes current str array
            updates size to be size of rhs and creates str as new array of new size
            copies elements of the str array of rhs
            returns rhs for cascading
        Does not modify rhs object
        Input:  an instance of myString array, rhs of = operator
        Output: instance of myString array, same reference given as input
    */
    delete [] str;
    size = rhs.length();
    str = new char[size];
    for(int i=0;i<size;i++){
        set(i, rhs.at(i));
    }
    return(rhs);
}
bool myString::operator==(const myString &rhs) const{
    /*
    Overloads == operator
        calls equal() method and returns the result (1 if objects are equal, 0 if not)
    Does not modify calling object or rhs
    Input:  instance of myString, rhs of == operator
    Output: bool indicating whether or not the objects are equal
    */
    return(equal(rhs));
}

bool myString::operator!=(const myString &rhs) const{
    /*
    Overlaods != operator
        calls equal() method and returns the opposite of the result (0 if objects are equal, 1 if not)
    Does not modify calling object or rhs
    Input:  instance of myString 
    Output: bool indicating whether or not the objects are equal 
    */
    return(!equal(rhs));
}

const myString myString::operator+(const myString &rhs) const{
    /*
    Overloads + operator
        Creates a new myString object and copies this instance, then concatonates rhs after it
        Returns new object
    Does not modify the calling object or rhs
    Input:  instance of myString
    Output: instance of myString - calling object concatonated with rhs 
    */
    int retSize(length()+rhs.length());
    myString ret(retSize);    //create new myString of combined size
    for(int i=0; i<size; i++){
        ret.set(i, at(i));
    }
    for(int i=size; i<retSize; i++){
        ret.set(i, rhs.at(i-size));
    }
    return(ret);
}

const myString myString::operator-(const myString &rhs) const{
    /*
    Overloads - operator
        creates a new myString object and copies this instance,
        it then removes any instance of rhs in calling object - calls find function and removes substring if found
    Does not modify the calling object or rhs
    Input:  instance of myString
    Output: instance of myString - calling object with any substring equal to rhs removed 
    */
    myString ret(*this);    //copy of calling object
    while(1){
        //loop until there are no instances of rhs in calling object
        int found(ret.find(rhs, 0));    //search for an instance of rhs starting at beginning of calling object
        if(found==-1){
            //done if no instance found
            break;
        }
        ret.remove(found, rhs.length());    //remove substr matching rhs from calling object
    }
    return(ret);
}

const myString & myString::operator++(){
    /*
    Overloads pre increment ++ operator
    increments the string by adding empty char to end of array
        returns calling object after it has been incremented
    Input:  None
    Output: instance of myString - this instance
    */
    myString blank(" ", 1);
    add(blank);
    return(*this);
}

const myString myString::operator++(int){
    /*
    Overloads post increment ++ operator
        makes copy of the calling object before it increments it.
        string is incremented by adding empty char to end of array
        copy of original is retunred
    Input:  None
    Output: instance of myString - copy of calling object before modifiction
    */
    myString ret(*this);
    myString blank(" ",1);
    add(blank);
    return(ret);
}

char myString::operator[](const int index) const{
    /*
    Overloads get [] operator
        Returns the char of the str[] array at the given index
        Checks if index is out of bounds - if so, program terminates
    Does not modify object
    Input:  Index to get char at
    Output: Char at the given index
    */
    if(index<0 || index>=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    return str[index];
}

char & myString::operator[](const int index){
    /*
    Overloads set [] operator
        Returns address of char at the given index to be set by assignment
        Checks if index is out of bounds - if so, program terminates
    Input:  Index to set char at
    Output: Address of char to set
    */
    if(index<0 || index>=size){
        cout << "Index out of range: exit status 1" << endl;
        exit(1);
    }
    return str[index];
}

ostream & operator<<(ostream &lhs, const myString &rhs){
    /*
    Friend function: overloads ostream's stream insertion operator
        prints str array to stdout through ostream
    Does not modify rhs
    input:  an instance of myString (and ostream)
    output: modified ostream for cascading
        object's data will be printed to stdout
    */
    for(int i(0); i<rhs.length(); i++){
        cout << rhs[i];
    }
    return(lhs);
}
istream & operator>>(istream &lhs, myString &rhs){
    /*
    overloads istream's stream extraction operator
        object must have previously been defined with a size n
        function recieves n elements from stdin
    input:  instance of myString (and istream)
        myString object of size n will recieve n elements from stdin
    output: istream for cascading
    */
    for(int i(0); i<rhs.length(); i++){
        lhs >> rhs[i];
    }
    return(lhs);
}