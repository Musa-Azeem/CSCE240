#include "myData.h"
#include <math.h>

using namespace std;

//SETTERS for size

myData::myData(): data(nullptr), size(0), nvals(0), clusters(nullptr), nclust(0) {}
//TODO try using assignment operator to initialize array of Points
myData::myData(const long int nobserv, const int _nvals, const double val=0): size(nobserv), nvals(_nvals), clusters(nullptr), nclust(0){
    //initilize array to be used to populate object (from given value)
    /*double valArr[nvals];
    for(int i(0); i<nvals; i++){
        valArr[i] = val;
    }*/
    //initialize data of object with given value
    data = new Point*[size];
    for(int i(0); i<size; i++){
        data[i] = new Point(nvals, val);
    }
}
/*myData::myData(const long int nobserv, const int _nvals, const double **_data): clusters(nullptr), nclust(0){
    size = nobserv;
    nvals = _nvals;
    data = new Point*[size];
    for(int i(0); i<size; i++){
        data[i] = new Point(nvals, _data[i]);
    }
}*/
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

/*Point * myData::accessObserv(const int index){
    return(data[index]);
}*/

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
        lhs << "Data: \t";
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
    int iter(0);
    Point *prevCentroids[nclust];
    bool cont(1);
    while(cont){
        cout << " ___________________________________ "<< endl;
        cout << "iter" << iter << endl;
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
    return(1);
}
void myData::setMemberships(){
    //calculate distance between every point and each cluster
    //assign membership of each point to closest cluster
    cout << *this << endl;
    double leastDist;
    double prevDist;
    double dist;
    int id;
    int prevMember;
    for(int i(0); i<size; i++){
        //loop through every data point
        prevMember = (*data[i]).getMembership();    //save the old membership of point before changing it
        leastDist = (*data[i]).getCentroidDistance();   //initially set leastDist to distance to current centroid
        if(prevMember == -1){   //if first iteration of kmeans, points have no membership and no centroidDistance
            (*data[i]).setMembership(0);    //set membership to first cluster
            (*clusters[0]).nmembers++;
            prevMember = 0;
            leastDist = (*data[i]).distance((*clusters[0]).centroid);  //set leastDist to distance to first cluster
            (*data[i]).setCentroidDistance(leastDist);
            (*clusters[0]).totalDistance+=leastDist;
            //cout << i << " " << leastDist <<  " " << (*clusters[0]).totalDistance << endl;
        }

        prevDist = leastDist;
        id = prevMember;
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
            cout << "i " << i << endl;
            cout << "least dist " << leastDist << endl;
            cout << "id " << id << endl;
            cout << "cluster before change" << (*clusters[id]).totalDistance << endl;
            (*data[i]).setMembership(id);
            (*data[i]).setCentroidDistance(leastDist);
            (*clusters[id]).nmembers++;    //incremenent counter of members for centroid
            (*clusters[id]).totalDistance += leastDist; //add new member's distance to centroid to total
            cout << "cluster after change" << (*clusters[id]).totalDistance << endl;
            (*clusters[prevMember]).nmembers--; //decrement old centroid since it lost a member
            cout << "old cluster before change" << (*clusters[prevMember]).totalDistance << endl;
            (*clusters[prevMember]).totalDistance -= prevDist;
            cout << "old cluster after change" << (*clusters[prevMember]).totalDistance << endl;
        }
    }
    cout << "after setMembership" << endl;
    cout << *this << endl;
}

double myData::moveCentroids(){
    //moves centroids to the mean of all points assigned to it
    //return new average distance
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
            }
        }
    }
    for(int i(0); i<nclust; i++){   //loop through clusters to find means and assign new location
        for(int j(0); j<nvals; j++){
            means[i][j] = means[i][j] / (*clusters[i]).nmembers;
            (*clusters[i]).centroid[j] = means[i][j];
        }
    }

    /*double mean;
    for(int i(0); i<nclust; i++){   //calculate fitenss of each centroid
        mean = (*clusters[i]).totalDistance / (*clusters[i]).nmembers;
    }*/
    return(0);
}