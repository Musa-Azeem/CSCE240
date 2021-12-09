#ifndef MYDATA_H
#define MYDATA_H
#include "Point.h"
#include "Clust.h"
#include <iostream>

class myData{
    friend std::istream & operator>>(std::istream &lhs, myData &rhs);
    friend std::ostream & operator<<(std::ostream &lhs, const myData &rhs);
    public:
        myData();
        myData(const long int nobserv, const int _nvals, const double val);
        myData(const double _data[][0], const long int nobserv, const int _nvals);
        myData(const myData &other);
        ~myData();

        long int getSize() const;
        int getNvals() const;
        int getNclust() const;
        
        double kMeansClustering(const int _nclust, const int maxIter, const double toler);
        void ClusterSummary() const;
        
        void Summary() const;
        double getMinValue(const int col) const;
        double getMaxValue(const int col) const;
        double getMean(const int col) const;
        double getStandDev(const int col, const double mean) const;
        double getFitness() const;

        const myData & operator=(const myData &other);
        bool operator==(const myData &other) const;         //TODO
        bool operator!=(const myData &other) const;         //TODO
        myData operator+(const myData &other) const;
        int operator[](int index) const;
        int & operator[](int index);

//        void print() const;
    private:
        Point *data;
        long int size;
        int nvals;
        Clust **clusters;
        int nclust;
        
        void setMemberships();
        double moveCentroids();

};

#endif