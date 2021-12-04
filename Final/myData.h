#ifndef MYDATA_H
#define MYDATA_H
#include "Point.h"
#include "Cluster.h"
#include <iostream>

class myData{
    friend std::istream & operator>>(std::istream &lhs, myData &rhs);  //continute here
    public:
        myData();
        myData(const long int nobserv, const int _nvals, const double val);
        //myData(const long int nobserv, const int _nvals, const double **_data);
        myData(const myData &other);
        ~myData();

        long int getSize() const;
        int getNvals() const;
        int getNclust() const;
        Point * accessObserv(const int index);
        //Kmeans function()
        //cluster summary
        void summary() const;

        const myData & operator=(const myData &other); 
        bool operator==(const myData &other) const;
        bool operator!=(const myData &other) const;
        const myData operator+(const myData &other) const;

        void print() const;
    private:
        Point **data;
        long int size;
        int nvals;
        Cluster **clusters;  //initilized by first call to kmeans (num of clusters given) - null until then
        int nclust;
};

#endif