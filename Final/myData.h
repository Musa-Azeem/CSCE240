#ifndef MYDATA_H
#define MYDATA_H
#include "Point.h"
#include "Clust.h"
#include <iostream>

class myData{
    friend std::istream & operator>>(std::istream &lhs, myData &rhs);
    //TODO <<
    public:
        myData();
        myData(const long int nobserv, const int _nvals, const double val);
        //myData(const long int nobserv, const int _nvals, const double **_data);
        myData(const myData &other);
        ~myData();

        void setSize(const long int _size);     //TODO and implement

        long int getSize() const;
        int getNvals() const;
        int getNclust() const;
        Point * accessObserv(const int index);
        
        bool kMeansClustering(int _nclust, int maxIter, double toler);//Kmeans function()
        //cluster summary
        
        void summary() const;
        double getMinValue(const int col) const;
        double getMaxValue(const int col) const;
        double getMean(const int col) const;
        double getStandDev(const int col, const double mean) const;

        const myData & operator=(const myData &other);
        bool operator==(const myData &other) const;         //TODO
        bool operator!=(const myData &other) const;         //TODO
        const myData operator+(const myData &other) const;  //TODO
        //TODO operator []

        void print() const;
    private:
        Point **data;
        long int size;
        int nvals;
        Clust **clusters;
        int nclust;
        

};

#endif