#include "myData.h"
#include <math.h>

using namespace std;

myData::myData(): data(nullptr), size(0), nvals(0), clusters(nullptr), nclust(0) {}
myData::myData(const long int nobserv, const int _nvals, const double val=0): size(nobserv), nvals(_nvals), clusters(nullptr), nclust(0){
    //initilize array to be used to populate object (from given value)
    //initialize data of object with given value and inital membership to first cluster
    data = new Point*[size];
    for(int i(0); i<size; i++){
        data[i] = new Point(nvals, val, 0);
    }
}
myData::myData(const myData &other){
    size = other.size;
    nvals = other.nvals;
    if(size != 0){ 
        data = new Point*[size];
        for(int i(0); i<size; i++){
            data[i] = new Point(*other.data[i]);
        }
    }
    else{
        data = nullptr;
    }
    nclust = other.nclust;
    if(nclust != 0){
        clusters = new Clust*[nclust];
        for(int i(0); i<nclust; i++){
            clusters[i] = new Clust(*other.clusters[i]);
        }
    }
    else{
        clusters = nullptr;
    }
}
myData::~myData(){
    for(int i(0); i<nclust; i++){
        delete clusters[i];
    }
    delete [] clusters;
    for(int i(0); i<size; i++){
        delete data[i];
    }
    delete [] data;
}

const myData & myData::operator=(const myData &rhs){
    for(int i(0); i<nclust; i++){
        delete clusters[i];
    }
    delete [] clusters;
    for(int i(0); i<size; i++){
        delete data[i];
    }
    delete [] data;

    size = rhs.size;
    nvals = rhs.nvals;
    if(size != 0){ 
        data = new Point*[size];
        for(int i(0); i<size; i++){
            data[i] = new Point(*rhs.data[i]);
        }
    }
    else{
        data = nullptr;
    }
    nclust = rhs.nclust;
    if(nclust != 0){
        clusters = new Clust*[nclust];
        for(int i(0); i<nclust; i++){
            clusters[i] = new Clust(*rhs.clusters[i]);
        }
    }
    else{
        clusters = nullptr;
    }
    return(rhs); 
}

long int myData::getSize() const{return(size);}
int myData::getNvals() const{return(nvals);}
int myData::getNclust() const{return(nclust);}

void myData::print() const{
    for(int i(0); i<size; i++){
        cout << *data[i] << endl;
    }
}

void myData::Summary() const{
    cout << "Number of points in each column: " << size << endl << endl;;
    for(int i(0); i<nvals; i++){
        cout << "Column " << i << endl;
        cout << "Minimum Value: " << getMinValue(i) << endl;
        cout << "Maximum Value: " << getMaxValue(i) << endl;
        double mean(getMean(i));
        cout << "Mean: " << mean << endl;
        cout << "Standard Deviation: " << getStandDev(i, mean) << endl;
        cout << endl;
    }
}
double myData::getMinValue(const int col) const{
    if(size==0){
        cout << "no data" << endl;
        exit(1);
    }
    double min((*data[0])[col]);    //get value at given column of first Point in data array
    for(int i(1); i<size; i++){
        double next((*data[i])[col]);
        if(next<min){
            min = next;
        }
    }
    return(min);
}
double myData::getMaxValue(const int col) const{
    if(size==0){
        cout << "no data" << endl;
        exit(1);
    }
    double max((*data[0])[col]);    //get value at given column of first Point in data array
    for(int i(1); i<size; i++){
        double next((*data[i])[col]);
        if(next>max){
            max = next;
        }
    }
    return(max);
}
double myData::getMean(const int col) const{
    if(size==0){
        cout << "no data" << endl;
        exit(1);
    }
    double sum(0);
    for(int i(0); i<size; i++){
        sum += (*data[i])[col];
    }
    return(sum/size);
}
double myData::getStandDev(const int col, const double mean) const{
    if(size==0){
        cout << "no data" << endl;
        exit(1);
    }
    double sum(0);
    for(int i(0); i<size; i++){
        sum += pow(((*data[i])[col]-mean), 2);
    }
    return(sqrt(sum/size));
}
double myData::getFitness() const{
    double fitness(0);
    for(int i(0); i<nclust; i++){
        fitness += (*clusters[i]).totalDistance;
    }
    fitness = fitness / size;
    return(fitness);
}

istream & operator>>(istream &lhs, myData &rhs){
    //requires number of observations (size) to be set beforehand
    if(rhs.getSize()==0){
        cout << "Size not set" << endl;
        exit(1);
    }
    cout << "Enter " << rhs.getSize() << " observations of " << rhs.getNvals() << " values:" << endl;
    for(int i(0); i<rhs.getSize(); i++){
        //lhs >> *rhs.accessObserv(i);
        lhs >> *rhs.data[i];
    }
    return(lhs);
}
ostream & operator<<(ostream &lhs, const myData &rhs){  //TODO convert to ' ' delim
    //prints data points and their memberships to stdout
    //then prints centroid information
    for(int i(0); i<rhs.getSize(); i++){
        for(int j(0); j<rhs.getNvals(); j++){
            lhs << (*rhs.data[i])[j] << " ";    //TODO call point <<
        }
        lhs << "\t Membership: " << (*rhs.data[i]).getMembership() << endl;
    }
    //centroids
    
    lhs << "Centroids:" << endl;
    for(int i(0); i<rhs.getNclust(); i++){
        //TODO call point <<
        lhs << "Cluster "<< i << ": \t";
        for(int j(0); j<rhs.getNvals(); j++){
            lhs << (*rhs.clusters[i]).centroid[j] << " ";
        }
        lhs << "\t Num Members: " << (*rhs.clusters[i]).nmembers;
        lhs << "\t Ave Dist: " << (*rhs.clusters[i]).totalDistance/(*rhs.clusters[i]).nmembers;
        lhs << endl;
    }
    return(lhs);
}

void myData::ClusterSummary() const{
    if(!clusters){
        cout << "kMeans Clustering has not been completed" << endl;
        return;
    }
    cout << "Total fitness: " << getFitness() << endl;
    cout << "Numbers of Clusters: " << nclust << endl;
    for(int i(0); i<nclust; i++){                        
        cout << "Cluster " << i << ": " << endl;
        cout << "Centroid: ";
        for(int j(0); j<nvals; j++){
            cout << (*clusters[i]).centroid[j] << " ";
        }
        cout << endl << "Number of Members: " << (*clusters[i]).nmembers << endl;
        cout << "Average Distance: " << (*clusters[i]).totalDistance / (*clusters[i]).nmembers << endl << endl;
    }
}

double myData::kMeansClustering(int _nclust, int maxIter, double toler){
    if(size==0){
        cout << "no data" << endl;
        return(0);
    }
    //TODO try assigning each data part of Clust instead of new
    if(nclust != 0){
        for(int i(0); i<nclust; i++){
            delete clusters[i];
        }
        delete [] clusters;
        nclust = 0;
    }
    nclust = _nclust;
    clusters = new Clust*[nclust];
    
    //get random initial centroid locations
    //srand(time(NULL));
    srand48(time(NULL));
    double random;
    for(int i(0); i<nclust; i++){
        //random = rand() % 2000 - 1000;     //generate random coordinates between -1000 and 1000
        random = drand48()*getMaxValue(0);  //get semi-random number (use max value of first column so number is near data)
        clusters[i] = new Clust(nvals, random, i);
    }
    //initalize so that all points are initially members of cluster one
    (*clusters[0]).nmembers = size;
    int iter(0);
    Point *prevCentroids[nclust];
    bool cont(1);
    while(cont){
        for(int i(0); i<nclust; i++){
            prevCentroids[i] = new Point((*clusters[i]).centroid);
        }

        setMemberships();   //call method to calc distances and set memberships
        moveCentroids();    //move centroids to mean of all points assigned to it

        cont = 0;
        for(int i(0); i<nclust; i++){
            if((*clusters[i]).centroid.distance((*prevCentroids[i]))>toler){
                //if difference between new and old centroid locations is not less than tolerance for each centroid, continue iteration
                cont = 1;
            }
            delete prevCentroids[i];
        }
        if(iter>=maxIter){  //if max number of iterations   is reached, end iteration
            cont = 0;
        }
        iter++;
    }
    //clean up - set all points centroidDistance and calculate the fitness (total distances of each cluster)
    double tempDist;
    for(int i(0); i<size; i++){
        for(int id(0); id<nclust; id++){                
            if((*data[i]).getMembership() == id){
                tempDist = (*data[i]).distance((*clusters[id]).centroid);
                (*data[i]).setCentroidDistance(tempDist);
                (*clusters[id]).totalDistance += tempDist;
            }
        }
    }
    return(getFitness());
}
void myData::setMemberships(){
    //calculate distance between every point and each cluster
    //assign membership of each point to closest cluster
    double leastDist;
    double prevDist;
    double dist;
    int id;
    int prevMember;
    for(int i(0); i<size; i++){
        //loop through every data point
        id = (*data[i]).getMembership();    //save the old membership of point before changing it
        (*data[i]).setCentroidDistance((*data[i]).distance((*clusters[id]).centroid));  //set each points centroid distance to moved centroid
        leastDist = (*data[i]).getCentroidDistance();   //initially set leastDist to distance to current centroid
        prevMember = id;
        for(int j(0); j<nclust; j++){
            //loop through clusters - calculate distance of current point to each cluster
            //set leastDist to the distance to the nearest cluster
            dist = (*data[i]).distance((*clusters[j]).centroid);
            if(dist < leastDist){
                //if the distance to this cluster is less, set membership of point to it
                leastDist = dist;
                id = j;
            }
        }
        if(id != prevMember){   //change membership of point if there is a new shortest distance
            (*data[i]).setMembership(id);
            (*clusters[id]).nmembers++;    //incremenent counter of members for centroid
            (*clusters[prevMember]).nmembers--; //decrement old centroid since it lost a member
        }
    }
}

double myData::moveCentroids(){
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
            if((*data[i]).getMembership() == id){
                //if point is a member of this cluster, add its coordinates to array
                for(int j(0); j<nvals; j++){
                    means[id][j] += (*data[i])[j];
                }
                (*data[i]).setCentroidDistance((*data[i]).distance((*clusters[id]).centroid));
            }
        }
    }
    for(int i(0); i<nclust; i++){   //loop through clusters to find means and assign new location
        for(int j(0); j<nvals; j++){
            if((*clusters[i]).nmembers!=0){
                means[i][j] = means[i][j] / (*clusters[i]).nmembers;
                (*clusters[i]).centroid[j] = means[i][j];
            }
        }
    }
    return(0);
}