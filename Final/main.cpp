#include "Point.h"
#include "myData.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv){
    myData dataA(20, 2, 0);
    //dataA.print();
    //cout << "_______________________________________" << endl;
    //dataB.print();
    //Point pointC(*dataA.accessObserv(0));
    //cout << pointC << endl;
    cin >> dataA;
    dataA.print();
    dataA.summary();
    dataA.kMeansClustering(3, 4, .001);
}