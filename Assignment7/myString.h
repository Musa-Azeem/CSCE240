#include <iostream>
using namespace std;

class myString
{
    friend ostream & operator<<(ostream &lhs, const myString &rhs);
    friend istream & operator>>(istream &lhs, myString &rhs);
    private:
        int size;
        char* str;
        void remove(const int index, const int length);
    public:
        myString();
        myString(const int _size);
        myString(const char _str[], const int _size);
        myString(const myString &rhs);
        ~myString();


        void set(const int index, const char val);
        char at(const int index) const;
        int length() const;
        myString substring(const int startIndex, const int length) const;
        void clear();
        bool empty() const;
        int find(const myString &substr, const int startIndex) const;
        int count(const myString &subtr) const;
        bool equal(const myString &other) const;
        bool add(const myString &other);
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
};
