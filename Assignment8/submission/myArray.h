#include <iostream>
#ifndef MYARRAY_H
#define MYARRAY_H
#endif

template <class T>
class myArray{
    template <class U>
    friend std::ostream & operator<<(std::ostream &lhs, const myArray &rhs);
    template <class U>
    friend std::istream & operator>>(std::istream &lhs, myArray &rhs);
    public:
        myArray();
        myArray(const int _size);
        myArray(const T _data[], const int _size);
        myArray(const int _size, const T _data[]);
        myArray(const myArray<T> &rhs);
        ~myArray();

        int length() const;
        void clear();
        bool isEmpty() const;

        const myArray<T> & operator=(const myArray<T> &rhs);
        bool operator==(const myArray<T> &rhs) const;
        bool operator!=(const myArray<T> &rhs) const;
        const myArray<T> operator+(const myArray<T> &rhs) const;   //try to make return by reference
        const myArray<T> operator-(const myArray<T> &rhs) const;
        T operator[](const int index) const;    //get
        T & operator[](const int index);        //set

        void set(const int index, const T value);
        T get(const int index) const;
        //int find(const T toFind[], const int index);
        
        void print() const;

    private:
        T* data;
        int size;

        void init(const T _data[], const int _size);
};