#ifndef CLUST_H
#define CLUST_H
#include "Point.h"

struct Clust{
    Clust(): centroid(), nmembers(0), totalDistance(0) {}
    Clust(const int nvals, const double val, const int membership): 
        centroid(nvals, val, membership), nmembers(0), totalDistance(0) {}
    Clust(const Clust &other): centroid(other.centroid), nmembers(other.nmembers), totalDistance(other.totalDistance) {}
    Point centroid;
    int nmembers;
    double totalDistance;   //sum of all member points distances to the cluster's centroid
};

#endif