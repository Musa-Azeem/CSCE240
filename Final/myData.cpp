#include "myData.h"

using namespace std;

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

myData::~myData(){
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