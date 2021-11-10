#include <iostream>
#include "myString.h"

using namespace std;

int main(int argc, char **argv){
    myString s0;    //defualt
    myString s1(10);    //alt constructor 1
    myString s2("hello world", 11); //alt constructor 2
    myString s3(s2);    //copy constructor

    /*
    //print
    s0.print();
    s1.print();
    s2.print();
    s3.print();
    */

    //operator<<
    cout << "s0:" << s0 << endl;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << endl;    
    //set
    cout << "enter char to set s1" << endl;
    char input;
    cin >> input;
    cout << "enter index to set s1" << endl;
    int index;
    cin >> index;
    s1.set(index, input);
    cout << "s1:" << s1 << endl;
    cout << endl;

    //at
    cout << "enter index to get char of s2" << endl;
    cin >> index;
    cout << "s2 at " <<index<< ":" << (s2.at(index)) << endl;
    cout << endl;
    
    //length
    cout << "lengths" << endl;
    cout << (s0.length()) << endl;
    cout << (s1.length()) << endl;
    cout << (s2.length()) << endl;
    cout << (s3.length()) << endl;
    cout << endl;

    //substring
    cout << "enter start index to create substring from s2: " << endl;
    cin >> index;
    cout << "enter length of substring: " << endl;
    int length;
    cin >> length;
    myString substr(s2.substring(index, length));
    substr.print();
    cout << endl;
    
    //clear
    s1.clear();
    cout << "s1 cleared: " << s1 << endl << endl;

    //empty
    cout << s1.empty() << endl;

    //find
    cout << "enter length of string to find in s3: " << endl;
    cin >> length;
    myString toFind(length);
    cout << "enter string to find in s3: " << endl;
    cin >> toFind;
    cout << "enter index to start search" << endl;
    cin >> index;
    cout << s3.find(toFind, index) << endl << endl;

    //count
    cout << "enter length of string to find cout of in s3: " << endl;
    cin >> length;
    myString toFind2(length);
    cout << "enter string to find count of in s3: " << endl;
    cin >> toFind2;
    cout << s3.count(toFind2) << endl << endl;

    //equal
    cout << "equal" << endl;
    cout << s0.equal(s1) << endl;
    cout << s1.equal(s2) << endl;

    //add
    cout << "enter length of string to add to s3: " << endl;
    cin >> length;
    myString toAdd(length);
    cout << "enter string to add to s3: " << endl;
    cin >> toAdd;
    s3.add(toAdd);
    cout << s3 << endl << endl;

    //operator=
    cout << "operator=" << endl;
    s0 = s1 = s2;
    cout << "s0:" << s0 << endl;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << endl;    

    //operator==
    cout << "operator==" << endl;
    cout << (s0==s1) << endl;
    cout << (s2==s3) << endl;
    cout << endl;

    //operator!=
    cout << "operator!=" << endl;
    cout << (s0!=s1) << endl;
    cout << (s2!=s3) << endl;
    cout << endl;

    //operator+
    cout << "operator+" << endl;
    myString added;
    added = s0+s1;
    cout << "s0:" << s0 << endl;
    cout << "s1:" << s1 << endl;
    cout << "added: " << added << endl << endl;

    //operator-
    cout << "operator-" << endl;
    cout << "enter length of string to subtract from s3: " << endl;
    cin >> length;
    myString toSub(length);
    cout << "enter string to subtract from s3: " << endl;
    cin >> toSub;
    cout << (s3 - toSub) << endl;
    cout << "s0:" << s0 << endl;
    cout << "s1:" << s1 << endl << endl;

    //pre operator++
    cout << "pre operator++" << endl;
    cout << s0.length() << ": " << s0 << endl;
    added = ++s0;
    cout << added.length() << ": " << added << endl;
    cout << s0.length() << ": " << s0 << endl << endl;
    
    //post operator++
    cout << "post operator++" << endl;
    cout << s0.length() << ": " << s0 << endl;
    added = s0++;
    cout << added.length() << ": " << added << endl;
    cout << s0.length() << ": " << s0 << endl << endl;

    //set []
    cout << "set operator[]" << endl;
    cout << "enter index to set value of s1" << endl;
    cin >> index;
    cout << "enter char to set" << endl;
    cin >> input;
    s1[index] = input;
    cout << s1 << endl << endl;

    //set []
    cout << "get operator[]" << endl;
    cout << "enter index to get value of s1" << endl;
    cin >> index;
    cout << s1[index] << endl << endl;



}