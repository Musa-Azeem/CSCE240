#include "Point.h"
#include "myData.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv){
    myData dataA(2, 3, 10);
    myData dataB(dataA);
    //dataA.print();
    //cout << "_______________________________________" << endl;
    //dataB.print();
    //Point pointC(*dataA.accessObserv(0));
    //cout << pointC << endl;
    cin >> *dataA.accessObserv(1);
    dataA.print();
}