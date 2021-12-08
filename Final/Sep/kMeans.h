#ifndef KMEANS_H
#define KEANS_H
#include "Point.h"
#include "Clust.h"
#include <iostream>

class kMeans{
    friend std::istream & operator>>(std::istream &lhs, kMeans &rhs);
    friend std::ostream & operator<<(std::ostream &lhs, const kMeans &rhs);

    public:
        kMeans();
        kMeans(Point **data, int maxIter, const int toler);

    private:
        int nclusts;
        Clust *clusters;

        void setMemberships();
        double moveCentroids();
};

#endif