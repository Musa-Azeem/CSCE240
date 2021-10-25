#include <iostream>
#include "String.h"

using namespace std;

int main(int argc, char **argv){
    char str[] = {'h','e','l','l','o'};
    String s(5, str);
    char str2[] = {'o','o','o','o','e'};
    String s2(5, str2);
    char str3[] = {'h','e','k','e','h','e','k'};
    String s3(7, str3);
    s.print();
    s2.print();
    char fin[] = {'l'};
    String sf(1, fin);
    cout << s2.find(sf, 4) << endl;
    String s5;
    //s2.add(s5);
    String s3;
    s3+s;
    s3.print();

    s.add(s2);
    s.print();
    char cou[] = {'h','e','l','l','o','t'};
    String c(6, cou);
    cout << s.count(c) << endl;
    return(0);

}