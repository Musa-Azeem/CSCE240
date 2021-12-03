#ifndef CENTROID_H
#include "Centroid.h"
#endif
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    double a[2] = {10, 10};
    Point pointA(2, a);
    double b[3] = {10,20, 20}; 
    Point pointB(3, b);

    cout << pointA.distance(pointB) << endl;

}