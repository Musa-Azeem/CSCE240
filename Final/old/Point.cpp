#include "Point.h"
#include <math.h>

using namespace std;

Point::Point(): size(0), coord(nullptr), membership(-1), centroidDistance(-1){}
/*Point::Point(const int numOfCoord, const double val): size(numOfCoord), membership(-1), centroidDistance(-1){
    coord = new double[size];
    for(int i(0); i<size; i++){
        coord[i] = val;
    }
}*/
Point::Point(const int numOfCoord, const double val, const int _membership): size(numOfCoord), membership(_membership), centroidDistance(-1){
    coord = new double[size];
    for(int i(0); i<size; i++){
        coord[i] = val;
    }
}
/*Point::Point(const int numOfCoord, const double *_coord){
    init(numOfCoord, _coord, -1, -1);
}*/
Point::Point(const int numOfCoord, const double *_coord, const int _membership): size(numOfCoord), membership(_membership), centroidDistance(-1) {
    coord = new double[size];
    for(int i(0); i<size; i++){
        coord[i] = _coord[i];
    }
}
/*Point::Point(const int numOfCoord, const double *_coord, const int _membership, const double _centroidDistance){
    init(numOfCoord, _coord, _membership, _centroidDistance);
}*/
Point::Point(const Point &other){
    size = other.size;
    membership = other.membership;
    centroidDistance = other.centroidDistance;
    if(size==0){
        coord = nullptr;
    }
    else{
        coord = new double[size];
        for(int i(0); i<size; i++){
            coord[i] = other[i];
        }
    }
}
Point::~Point(){
    delete [] coord;
}

/*void Point::init(const int _size, const double *_data, const int _membership, const double _centroidDistance){
    size = _size;
    membership = _membership;
    centroidDistance = _centroidDistance;
    if(size == 0){
        coord = nullptr;
        return;
    }
    coord = new double[size];
    for(int i(0); i<size; i++){
        coord[i] = _data[i];
    }
}*/

int Point::getSize() const{
    return(size);
}
int Point::getMembership() const{
    return(membership);
}
double Point::getCentroidDistance() const{
    return(centroidDistance);
}
/*const double * Point::getCoord() const{
    return(coord);
}*/

void Point::setMembership(const int _membership){
    if(_membership<0){
        cout << "Invalid Cluster ID" << endl;
        exit(1);
    }
    membership = _membership;
}
void Point::setCentroidDistance(const double _centroidDistance){
    if(_centroidDistance<0){
        cout << "Invalid Distance" << endl;
        exit(1);
    }
    centroidDistance = _centroidDistance;
}
int & Point::accessMembership(){
    return(membership);
}

double Point::distance(const Point &other) const{
    if(!other.coord){
        cout << "Argument Point Object data is Null" << endl;
        exit(1);
    }
    if(!coord){
        cout << "Calling Point Object data is Null" << endl;
        exit(1);   
    }
    if(size != other.size){
        cout << "Point objects are of difference dimensions" << endl;
        exit(1);
    }
    double sum(0);
    for(int i(0); i<size; i++){
        sum += (coord[i] - other[i]) * (coord[i] - other[i]);
    }
    return(sqrt(sum));
}

double Point::operator[](const int index) const{
    if(index < 0 || index >= size){
        cout << "Index Out of Range" << endl;
        exit(1);
    }
    return(coord[index]);
}

double & Point::operator[](const int index){
    if(index < 0 || index >= size){
        cout << "Index Out of Range" << endl;
        exit(1);
    }
    return(coord[index]);
}

const Point & Point::operator=(const Point &rhs){
    delete [] coord;
    size = rhs.size;
    membership = rhs.membership;
    centroidDistance = rhs.centroidDistance;
    if(size==0){
        coord = nullptr;
    }
    else{
        coord = new double[size];
        for(int i(0); i<size; i++){
            coord[i] = rhs[i];
        }
    }
    return(rhs);
}
bool Point::operator==(const Point &rhs) const{
    //only checks values - not membership
    if(size != rhs.getSize()){
        return(0);
    }
    for(int i(0); i<size; i++){
        if(coord[i] != rhs[i]){
            return(0);
        }    
    }
    return(1);
}
bool Point::operator!=(const Point &rhs) const{
    return(!(*this==rhs));
}

/*void Point::print() const{
    for(int i(0); i<size; i++){
        cout << coord[i] << " ";
    }
    cout << endl;
}*/

ostream & operator<<(ostream &lhs, const Point &rhs){   //TODO rewrite to ' ' delim
    if(!rhs.coord){
        return(lhs);
    }
    for(int i(0); i<rhs.getSize(); i++){
        lhs << rhs[i] << ",";
    }
    lhs << rhs.getMembership();
    return(lhs);
}
istream & operator>>(istream &lhs, Point &rhs){
    for(int i(0); i<rhs.getSize(); i++){
        lhs >> rhs[i];
    }
    return(lhs);
}