#ifndef MYARRAYLIST_H
#include "myArrayList.h"
#endif
#include "myArrayList.cpp"  //temp fix

using namespace std;

int main(int argc, char **argv){
    myArrayList<double> a1;     //default
    myArrayList<double> a2(10); //alt
    double array3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    myArrayList<double> a3(array3, 10); //alt
    myArrayList<double> a4(a3); //copy

    //cout
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "a3: " << a3 << endl;
    cout << "a4: " << a4 << endl;
    
    //cin
    cout << "enter 10 values for a2" <<endl;
    cin >> a2;
    cout << "a2: " << a2 << endl;
    
    //length
    cout << "a1 length" << a1.length() << endl;
    cout << "a2 length" << a2.length() << endl;
    cout << "a3 length" << a3.length() << endl;
    cout << "a4 length" << a4.length() << endl;

    //clear
    cout << "a4: " << a4 << endl;
    cout << "after clearing a4" << endl;
    a4.clear();
    cout << a4 << endl;

    //Empty
    cout << "is a1 empty? " << a1.isEmpty() << endl;
    cout << "is a4 empty? " << a4.isEmpty() << endl;

    //=
    cout << "a1 = a4= a3" << endl;
    a1 = a4 = a3;
    cout << "a1: "<< a1 << endl;
    cout << "a3: "<< a3 << endl;
    cout << "a4: "<< a4 << endl;

    //==
    cout << "a2 == a4: " << (a2==a3) << endl;

    //!=
    cout << "a2 != a4: " << (a2!=a3) << endl;

    //+
    cout << "enter size of array to concatonate to end of a4" << endl;
    int size;
    cin >> size;
    myArrayList<double> AddTo(size);
    cout << "enter array values to concatonate to end of a4" << endl;
    cin >> AddTo;
    myArrayList<double> added(a4+AddTo);
    cout << "added: " << added << endl;

    //-
    cout << "enter size of array to remove from a4" << endl;
    cin >> size;
    myArrayList<double> remFrom(size);
    cin >> remFrom;
    myArrayList<double> subbed(a4-remFrom);
    cout << "subbed: " << subbed << endl;

    //get []
    cout << "a3: " << endl;
    cout << "enter index to get from a3" << endl;
    cin >> size;
    cout << (a3[size]) << endl;

    //set []
    cout << "enter index to set a3" << endl;
    cin >> size;
    cout << "enter value to set a3" << endl;
    double val;
    cin >> val;
    a3[size] = val;
    cout << "a3: " << a3 << endl;
    
    return(0);
}