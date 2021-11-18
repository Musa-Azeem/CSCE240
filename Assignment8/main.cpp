#ifndef MYARRAYLIST_H
#include "myArrayList.h"
#endif
#include "myArrayList.cpp"  //temp fix

using namespace std;

int main(int argc, char **argv){
    myArrayList<int> a1;
    myArrayList<int> a2(5);
    int array3[5] = {1, 2, 3, 4, 5};
    myArrayList<int> a3(array3, 5);
    myArrayList<int> a4(a3);
    return(0);
}