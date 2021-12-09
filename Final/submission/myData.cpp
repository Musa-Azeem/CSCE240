#include "myData.h"
#include "kMeans.h"
#include <math.h>

using namespace std;

myData::myData(): data(nullptr), size(0), nvals(0) {}
myData::myData(const long int nobserv, const int _nvals, const double val=0): size(nobserv), nvals(_nvals){
    //initilize array to be used to populate object (from given value)
    //initialize data of object with given value and inital membership to first cluster
    data = new Point[size];
    for(int i(0); i<size; i++){
        data[i] = Point(nvals, val, 0);
    }
}
myData::myData(const double _data[][0], const long int nobserv, const int _nvals): size(nobserv), nvals(_nvals){
    data = new Point[size];
    for(int i(0); i<size; i++){
        data[i] = Point(nvals, _data[i], 0);
    }
}
myData::myData(const myData &other): size(other.size), nvals(other.nvals) {
    if(size != 0){ 
        data = new Point[size];
        for(int i(0); i<size; i++){
            data[i] = Point(other.data[i]);
        }
    }
    else{
        data = nullptr;
    }
}
myData::~myData(){
    delete [] data;
}

const myData & myData::operator=(const myData &rhs){
    delete [] data;

    size = rhs.size;
    nvals = rhs.nvals;
    if(size != 0){ 
        data = new Point[size];
        for(int i(0); i<size; i++){
            data[i] = Point(rhs.data[i]);
        }
    }
    else{
        data = nullptr;
    }
    return(rhs); 
}

long int myData::getSize() const{return(size);}
int myData::getNvals() const{return(nvals);}

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
    double min(data[0][col]);    //get value at given column of first Point in data array
    for(int i(1); i<size; i++){
        double next(data[i][col]);
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
    double max(data[0][col]);    //get value at given column of first Point in data array
    for(int i(1); i<size; i++){
        double next(data[i][col]);
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
        sum += data[i][col];
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
        sum += pow((data[i][col]-mean), 2);
    }
    return(sqrt(sum/size));
}

int myData::operator[](int index) const{
    if(index<0 || index>=size){
        cout << "index out of range" << endl;
        exit(1);
    }
    return(data[index].getMembership());
}
int & myData::operator[](int index){
    if(index<0 || index>=size){
        cout << "index out of range" << endl;
        exit(1);
    }
    return(data[index].accessMembership());
}
myData myData::operator+(const myData &rhs) const{
    int retSize(size+rhs.size);
    myData ret(retSize, nvals);
    for(int i(0); i<size; i++){
        ret.data[i] = Point(data[i]);
    }
    for(int i(size); i<retSize; i++){
        ret.data[i] = Point(rhs.data[i-size]);
    }
    return(ret);
}
bool myData::operator==(const myData &rhs) const{
    //does not check for memberships
    if(size != rhs.size || nvals != rhs.nvals){
        return(0);
    }
    for(int i(0); i<size; i++){
        if(data[i]!=rhs.data[i]){
            return(0);
        }    
    }
    return(1);
}
bool myData::operator!=(const myData &rhs) const{
    return(!(*this==rhs));
}

istream & operator>>(istream &lhs, myData &rhs){
    //requires number of observations (size) to be set beforehand
    if(rhs.getSize()==0){
        cout << "Size not set" << endl;
        exit(1);
    }
    cout << "Enter " << rhs.getSize() << " observations of " << rhs.getNvals() << " values:" << endl;
    for(int i(0); i<rhs.getSize(); i++){
        lhs >> rhs.data[i];
    }
    return(lhs);
}
ostream & operator<<(ostream &lhs, const myData &rhs){
    /*
    Prints data points and centroids to stdout, seperated by ','
    Prints data points and appends the cluster ID they were assigned to
    Prints Centroids and appends the cluster ID they belong to
    Input:  instance of myData and ostream to print it to
    Output: data of object is printed to ostream
    */
    for(int i(0); i<rhs.getSize(); i++){
        lhs << rhs.data[i] << endl;
    }
    lhs << endl;
    lhs << rhs.kMeansClusters << endl;
    return(lhs);
}

void myData::ClusterSummary() const{
    kMeansClusters.ClusterSummary();
}

double myData::kMeansClustering(const int _nclust, const int maxIter, const double toler){
    if(size==0){
        cout << "no data, cannot complete Kmeans Clustering" << endl;
        return(0);
    }
    kMeansClusters = kMeans(nvals, _nclust, getMaxValue(0));
    return(kMeansClusters.kMeansClustering(data, size, maxIter, toler));
}