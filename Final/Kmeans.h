#ifndef KMEANS_H
#define KMEANS_H

class Kmeans{
    //gets data (array of Point objects) from myData - shallow copies data for effieciency and to modify it (memberships)
    //gets clusters from myData to assign points to them

    public:
        Kmeans();
        Kmeans(long int nObserv, int nvals, Point **data, int nclust, Cluster **clusters, int maxIter, double termTol, );
};

#endif