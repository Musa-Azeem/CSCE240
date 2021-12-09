#include "kMeans.h"

using namespace std;

kMeans::kMeans(): nvals(0), nclust(0), clusters(nullptr), fitness(0) {}
kMeans::kMeans(const int _nvals, const int _nclust, const double range): nvals(_nvals), nclust(_nclust), fitness(0) {
    clusters = new Clust[nclust];
    for(int i(0); i<nclust; i++){
        srand48(time(NULL));
        double random = drand48()*range;  //get semi-random number (use given value for range)
        clusters[i].centroid = Point(nvals, random, i); //initialize centroids
    }
}
kMeans::kMeans(const kMeans &other): nvals(other.nvals), nclust(other.nclust), fitness(other.fitness) {
    if(nclust==0){
        clusters = nullptr;
    }
    else{
        clusters = new Clust[nclust];
        for(int i(0); i<nclust; i++){
            clusters[i] = Clust(other.clusters[i]);
        }
    }
}
kMeans::~kMeans(){
    delete [] clusters;
}
const kMeans & kMeans::operator=(const kMeans &rhs){
    nvals = rhs.nvals;
    nclust = rhs.nclust;
    fitness = rhs.fitness;
    if(nclust==0){
        clusters = nullptr;
    }
    else{
        clusters = new Clust[nclust];
        for(int i(0); i<nclust; i++){
            clusters[i] = Clust(rhs.clusters[i]);
        }
    }
    return(rhs);
}
void kMeans::ClusterSummary() const{
    if(!clusters){
        cout << "kMeans Clustering has not been completed for this dataset" << endl;
        return;
    }
    cout << "Total fitness: " << fitness << endl;
    cout << "Numbers of Clusters: " << nclust << endl << endl;
    for(int i(0); i<nclust; i++){                        
        cout << "Cluster " << i << ": " << endl;
        cout << "Centroid: ";
        for(int j(0); j<nvals; j++){
            cout << clusters[i].centroid[j] << " ";
        }
        cout << endl << "Number of Members: " << clusters[i].nmembers << endl;
        cout << "Average Distance: " << clusters[i].totalDistance / clusters[i].nmembers << endl << endl;
    }
}

double kMeans::kMeansClustering(Point *data, const int size, const int maxIter, const double toler){
    clusters[0].nmembers = size;    //all points in data start with memberships to first cluster
    for(int i(0); i<size; i++){
        data[i].setMembership(0);
    }
    int iter(0);
    Point prevCentroids[nclust];
    bool cont(1);
    while(cont){
        for(int i(0); i<nclust; i++){
            prevCentroids[i] = Point(clusters[i].centroid);
        }

        setMemberships(data, size);   //call method to calc distances and set memberships
        moveCentroids(data, size);    //move centroids to mean of all points assigned to it

        cont = 0;
        for(int i(0); i<nclust; i++){
            if(clusters[i].centroid.distance(prevCentroids[i])>toler){
                //if difference between new and old centroid locations is not less than tolerance for each centroid, continue iteration
                cont = 1;
            }
        }
        if(iter>=maxIter){  //if max number of iterations   is reached, end iteration
            cont = 0;
        }
        iter++;
    }
    //clean up - set all points' centroidDistance and calculate the fitness (total distances of each cluster)
    double tempDist;
    for(int i(0); i<size; i++){
        for(int id(0); id<nclust; id++){                
            if(data[i].getMembership() == id){
                tempDist = data[i].distance(clusters[id].centroid);
                data[i].setCentroidDistance(tempDist);
                clusters[id].totalDistance += tempDist;
            }
        }
    }
    calcFitness(size);
    return(fitness);
}

void kMeans::setMemberships(Point *data, const int size){
    //calculate distance between every point and each cluster
    //assign membership of each point to closest cluster
    double leastDist;
    double prevDist;
    double dist;
    int id;
    int prevMember;
    for(int i(0); i<size; i++){
        //loop through every data point
        id = data[i].getMembership();    //save the old membership of point before changing it
        data[i].setCentroidDistance(data[i].distance(clusters[id].centroid));  //set each points centroid distance to moved centroid
        leastDist = data[i].getCentroidDistance();   //initially set leastDist to distance to current centroid
        prevMember = id;
        for(int j(0); j<nclust; j++){
            //loop through clusters - calculate distance of current point to each cluster
            //set leastDist to the distance to the nearest cluster
            dist = data[i].distance(clusters[j].centroid);
            if(dist < leastDist){
                //if the distance to this cluster is less, set membership of point to it
                leastDist = dist;
                id = j;
            }
        }
        if(id != prevMember){   //change membership of point if there is a new shortest distance
            data[i].setMembership(id);
            clusters[id].nmembers++;    //incremenent counter of members for centroid
            clusters[prevMember].nmembers--; //decrement old centroid since it lost a member
        }
    }
}

void kMeans::moveCentroids(Point *data, const int size){
//moves centroids to the mean of all points assigned to it
    //return new average distance
    //also sets clusters total distance and each points centroid distance for next iteration
    double means[nclust][nvals];    //hold mean of each coordinate of data points assigned to each cluster
    for(int i(0); i<nclust; i++){
        for(int j(0); j<nvals; j++){
            means[i][j]=0;
        }
    }
    for(int i(0); i<size; i++){ //loop through all points
        for(int id(0); id<nclust; id++){ //loop through cluster ids
            if(data[i].getMembership() == id){
                //if point is a member of this cluster, add its coordinates to array
                for(int j(0); j<nvals; j++){
                    means[id][j] += data[i][j];
                }
                data[i].setCentroidDistance(data[i].distance(clusters[id].centroid));
            }
        }
    }
    for(int i(0); i<nclust; i++){   //loop through clusters to find means and assign new location
        for(int j(0); j<nvals; j++){
            if(clusters[i].nmembers!=0){
                means[i][j] = means[i][j] / clusters[i].nmembers;
                clusters[i].centroid[j] = means[i][j];
            }
        }
    }
}

void kMeans::calcFitness(const int size){
    for(int i(0); i<nclust; i++){
        fitness += clusters[i].totalDistance;
    }
    fitness = fitness / size;
}

ostream & operator<<(ostream &lhs, const kMeans &rhs){
    for(int i(0); i<rhs.nclust; i++){
        lhs << rhs.clusters[i].centroid << endl;
    }
    return(lhs);
}