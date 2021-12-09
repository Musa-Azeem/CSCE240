#include "kMeans.h"

using namespace std;

kMeans::kMeans(): nclust(0), clusters(nullptr) {}
kMeans::kMeans(const int _nclust): nclust(_nclust) {
    clusters = new Clust[nclust];
    for(int i(0); i<nclust; i++){
        clusters[i].centroid = Point();
    }
}