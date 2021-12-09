#ifndef KMEANS_H
#define KMEANS_H
#include "Point.h"
#include "Clust.h"
#include <iostream>

class kMeans{
    friend std::ostream & operator<<(std::ostream &lhs, const kMeans &rhs);

    public:
        kMeans();
        kMeans(const int _nvals, const int _nclust, const double seed);
        kMeans(const kMeans &other);
        ~kMeans();
        const kMeans & operator=(const kMeans &rhs);
        double kMeansClustering(Point *data, const int size, const int maxIter, const double toler);
        void ClusterSummary() const;

    private:
        int nclust;
        Clust *clusters;
        int nvals;
        double fitness;

        void setMemberships(Point *data, const int size);
        void moveCentroids(Point *data, const int size);
        void calcFitness(const int size);
};

#endif