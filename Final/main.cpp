#ifndef CENTROID_H
#include "Centroid.h"
#endif
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    Point pointA;
    double b[2] = {1,1}; 
    Point pointB(2, b);
    Point pointC(2, b, 5);
    Point pointD(2, b, 6, 10.0);
    Point pointE(pointC);

    cout << pointA << endl;
    cout << pointB << endl;
    cout << pointC << endl;
    cout << pointD << endl;
    cout << pointE << endl;

    pointB.setCentroidDistance(10.0);
    pointB.setMembership(3);
    cout << pointB << endl;

    cout << endl << endl;

    Centroid centrA;
    Centroid centrB(2, b, 0);

    centrA.print();
    centrB.print();
}