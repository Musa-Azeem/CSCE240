/*
Musa Azeem
Completed 11/11/2021 - 17:03:27
This program defines function headers of the myString object
Inputs: None
Ouput:  None
*/
#include <iostream>
using namespace std;

class myString
{
    friend ostream & operator<<(ostream &lhs, const myString &rhs);
    friend istream & operator>>(istream &lhs, myString &rhs);
    
    public:
        myString();
        myString(const int _size);
        myString(const char _str[], const int _size);
        myString(const myString &rhs);
        ~myString();


        void set(const int index, const char val);
        char at(const int index) const;
        int length() const;
        const myString substring(const int startIndex, const int length) const;
        void clear();
        bool empty() const;
        int find(const myString &substr, const int startIndex) const;
        int count(const myString &subtr) const;
        bool equal(const myString &other) const;
        bool add(const myString &other);
        void remove(const int index, const int length);
        void print() const;
        
        const myString & operator=(const myString &rhs);
        bool operator==(const myString &rhs) const;
        bool operator!=(const myString &rhs) const;
        const myString operator+(const myString &rhs) const;
        const myString operator-(const myString &rhs) const;
        const myString & operator++();      //pre increment
        const myString operator++(int);   //post increment
        char operator[](const int index) const;   //get
        char & operator[](const int index);   //set

    private:
        int size;
        char* str;
        
};
