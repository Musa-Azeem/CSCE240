/*
Written by Musa Azeem
Completed:  11/28/21 - 15:44:34
Program defines functions and data for the myArrayListList
Input:  None
Ouput:  None
*/
#include <iostream>
#ifndef myArrayList_H
#define myArrayList_H
#endif

template <class T>
class myArrayList{
    template <class U>
    friend std::ostream & operator<<(std::ostream &lhs, const myArrayList &rhs);
    template <class U>
    friend std::istream & operator>>(std::istream &lhs, myArrayList &rhs);
    public:
        myArrayList();
        myArrayList(const int _size);
        myArrayList(const T _data[], const int _size);
        myArrayList(const int _size, const T _data[]);
        myArrayList(const myArrayList<T> &rhs);
        ~myArrayList();

        int length() const;
        void clear();
        bool isEmpty() const;

        const myArrayList<T> & operator=(const myArrayList<T> &rhs);
        bool operator==(const myArrayList<T> &rhs) const;
        bool operator!=(const myArrayList<T> &rhs) const;
        const myArrayList<T> operator+(const myArrayList<T> &rhs) const;   //try to make return by reference
        const myArrayList<T> operator-(const myArrayList<T> &rhs) const;
        T operator[](const int index) const;    //get
        T & operator[](const int index);        //set

        void set(const int index, const T value);
        T get(const int index) const;
        void print() const;

    private:
        T* data;
        int size;

        void init(const T _data[], const int _size);
};