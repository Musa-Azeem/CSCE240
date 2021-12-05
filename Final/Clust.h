#ifndef CLUST_H
#define CLUST_H
#include "Point.h"

struct Clust{
    Clust(const int nvals, const int val, const int membership, const int _nmembers): 
        centroid(nvals, val, membership), nmembers(_nmembers) {}
    Clust(const Clust &other): centroid(other.centroid), nmembers(other.nmembers) {}
    Point centroid;
    int nmembers;
};

#endif