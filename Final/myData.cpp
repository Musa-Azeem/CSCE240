#include "myData.h"

using namespace std;

//SETTERS for size

myData::myData(): data(nullptr), size(0), nvals(0), clusters(nullptr), nclust(0) {}
myData::myData(const int nobserv, const int _nvals, const double val=0): clusters(nullptr), nclust(0){
    size = nobserv;
    nvals = _nvals;
    //initilize array to be used to populate object (from given value)
    double valArr[nvals];
    for(int i(0); i<nvals; i++){
        valArr[i] = val;
    }
    //initialize data of object with given value
    data = new Point*[size];
    for(int i(0); i<size; i++){
        data[i] = new Point(nvals, valArr);
    }
}
/*myData::myData(const int nobserv, const int _nvals, const double **_data): clusters(nullptr), nclust(0){
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

void myData::print() const{
    for(int i(0); i<size; i++){
        cout << *data[i] << endl;
    }
}