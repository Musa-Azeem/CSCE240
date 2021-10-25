#include <iostream>
#include "String.h"

using namespace std;

int main(int argc, char **argv){
	char str1[] = {'c','s','c','e',' ','2','4','0'};
	
	//default
	String s0;
	s0.print();

	//copy
	String s1(8,str1);
	String s2(s1);
	s1.print();
	s2.print();

	//length
	cout << "length1: " << s1.length() << endl;
	cout << "length2: " << s2.length() << endl;
	
	//clear
	s1.clear();
	cout << "cleared 1: ";
	s1.print();
	s2.print();

	//empty
	cout << "empty1: " << s1.empty() << endl;
	cout << "empty2: " << s2.empty() << endl;

	//at
	cout << "invalid2: " << s2.at(10) <<endl;
	cout << "invalid2: " << s2.at(-1) <<endl;
	cout << "invalid2: " << s2.at(8) <<endl;
	cout << "valid2 2: " << s2.at(2) <<endl;
	cout << "valid2 7: " << s2.at(7) <<endl;
	cout << "valid2 0: " << s2.at(0) <<endl;

	//find
	char str3[] = {'l','o','l','o','l','o','l','o'};
	char str4[] = {'h','e','l','l','o'};
	String s3(8, str3);
	s3.print();
	String s4(5, str4);
	s4.print();
	char strfind1[] = {'l','o','l'};
	String sf1(3, strfind1);
	char strfind2[] = {'l','o'};
	String sf2(2, strfind2);
	char strfind3[] = {'l'};
	String sf3(1, strfind3);
	char strfind4[] = {'l','l'};
	String sf4(2, strfind4);
	char strfind5[] = {' '};
	String sf5(1, strfind5);
	char strfind6[] = {'2','4','0'};
	String sf6(3, strfind6);

	cout << "find3 lol: " << s3.find(sf1, 0) << endl;
	cout << "find3 lol 3: " << s3.find(sf1, 3) << endl;
	cout << "find3 lo: " << s3.find(sf2,0) <<endl;
	cout << "find3 lo 5: " << s3.find(sf2, 5) <<endl;
	cout << "find3 4: " << s3.find(s4,0) <<endl;
	cout << "find4 l: " << s4.find(sf3, 0) <<endl;
	cout << "find4 ll: " << s4.find(sf4, 0) <<endl; 
	cout << "find4 ll 4: " << s4.find(sf4, 4) <<endl; 
	cout << "find2 space: " << s2.find(sf5, 0) <<endl;
	cout << "find 2 240: " << s2.find(sf6, 0) <<endl;
	cout << "find4 imp: " << s4.find(s2, 0) <<endl;
	cout << "find2 imp: " << s2.find(sf6, 6) <<endl;
	cout << "find2 pos; " << s2.find(sf6, 5) <<endl;

	//equal
	s1.print();
	s2.print();
	s3.print();
	s4.print();
	String e2(s2);
	cout << "inequal: " << s2.equal(s0) << endl;
	cout << "equal: ";
	if(s2==e2)
		cout << "1"<< endl;
	cout << "inequal" << s2.equal(s3) << endl;

	//add
	s1.add(s2);
	cout << "s1+s2: ";
	s1.print();
	s3.add(s4);
	cout << "s3+s4: ";
	s3.print();
	String s5(s0+s2);
	cout << "s0+s2: ";
	s5.print();
		
	//print
	cout << "prints" << endl;
	s0.print();
	s1.print();
	s2.print();
	s3.print();
	s4.print();
	s5.print();

	//count
	cout << "count2 240: " << s2.count(sf6) << endl;
	cout << "count3 lol: " << s3.count(sf1) <<endl;
	cout << "count3 lo: " << s3.count(sf2) <<endl;
	cout << "count2 space: " << s2.count(sf5) <<endl;
	cout << "count4 hello: " << s4.count(s4) <<endl;
	cout << "count4 imp: " << s4.count(s2) << endl;
	cout << "count3 ll: " << s3.count(sf4) <<endl;
	cout << "count3 l: " << s3.count(sf3) << endl;
	return(0);

}
