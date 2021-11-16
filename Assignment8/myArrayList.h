#include <iostream>
#ifndef MYARRAYLIST_H
#define MYARRAYLIST_H
#endif

template <class T>
class myArrayList{
    friend std::ostream & operator<<(std::ostream &lhs, const myArrayList &rhs);
    friend std::istream & operator>>(std::istream &lhs, myArrayList &rhs);
    public:
        myArrayList();
        myArrayList(const int _size);
        myArrayList(const T _data[], const int _size);
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
        //int find(const T toFind[], const int index);

    private:
        T* data;
        int size;

        void init(const T _data[], const int _size);
};