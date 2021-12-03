/*
#include "Centroid.h"

using namespace std;

Centroid::Centroid(): Point(), id(-1){}
Centroid::Centroid(const int _nCoord, double* _coord, const int _id): Point(_nCoord, _coord), id(_id){}
Centroid::Centroid(const Centroid &other): Point(other), id(other.getID()){}
Centroid::~Centroid(){}

int Centroid::getID() const{
    return(id);
}

void Centroid::print() const{
    cout << "ID: " << getID() << endl;
    cout << *this << endl;
}
*/