#include "myData.h"

using namespace std;

//SETTERS for size

myData::myData(): data(nullptr), size(0), nvals(0), clusters(nullptr), nclust(0) {}
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
        clusters = new Cluster*[nclust];
        for(int i(0); i<nclust; i++){
            clusters[i] = new Cluster(*other.clusters[i]);
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
    size = rhs.size;
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
        clusters = new Cluster*[nclust];
        for(int i(0); i<nclust; i++){
            clusters[i] = new Cluster(*rhs.clusters[i]);
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

Point * myData::accessObserv(const int index){
    return(data[index]);
}

void myData::print() const{
    for(int i(0); i<size; i++){
        cout << *data[i] << endl;
    }
}

istream & operator>>(istream &lhs, myData &rhs){
    //requires number of observations (size) to be set beforehand
    cout << "Enter " << rhs.getSize() << " observations of " << rhs.getNvals() << "values" << endl;
    for(int i(0); i<rhs.getSize(); i++){
        lhs >> *rhs.accessObserv(i);
    }
    return(lhs);
}