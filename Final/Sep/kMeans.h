#ifndef KMEANS_H
#define KMEANS_H
#include "Point.h"
#include "Clust.h"
#include <iostream>

class kMeans{
    friend std::istream & operator>>(std::istream &lhs, kMeans &rhs);
    friend std::ostream & operator<<(std::ostream &lhs, const kMeans &rhs);

    public:
        kMeans();
        kMeans(const int _nclust);
        double kMeansClustering(Point **data, int maxIter, const int toler);
        void ClusterSummary() const;
        double getFitness() const;

    private:
        const int nclust;
        Clust *clusters;

        void setMemberships();
        double moveCentroids();
};

#endif