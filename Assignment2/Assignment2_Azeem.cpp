#include <iostream>
using namespace std;

double myFactorial(double num);
double mySine(double x, int n);
double myCosine(double x, int n);
double power(double base, double exp);

const double pi = 3.141592654;
int main(int argc, char **arg){
    double x(0);
    double n(0);
    cout << "Enter an angle in degrees: ";
    cin >> x;
    cout << "Enter the number of terms (an integer greater than 0) to be used in the approximation: ";
    cin >> n;
    if(n <= 0) {
        n = 10;
    }
    cout << n << "! = " << myFactorial(n)<<endl;
    cout << "sin(" << x << ") = " << mySine(x, n) << endl;
    cout << "cos(" << x << ") = " << myCosine(x, n) << endl;

    return(0);
}

double myFactorial(double num){
    if(num == 0){
        return 1;
    }
    for(int i = num-1; i>1; i--){
        num *= i;
    }
    return(num);
}

double mySine(double x, int n){
    x *= pi/180;
    
    double est(0);
    for(int i=0; i<n; i++){
        //cout << "\n" <<endl;
        //cout << "num: " << power(-1, i) << endl;
        //cout << "fact: " << myFactorial(2*i+1) << endl;
        //cout << "xterm: " << power(x, (2*i+1)) << endl;
        //cout << (power(-1,i)/myFactorial(2*i+1)) * power(x,(2*i+1)) << endl; 
        est += (power(-1,i)/myFactorial(2*i+1)) * power(x,(2*i+1));
    }

    return(est);
}

double myCosine(double x, int n){
    x *= pi/180;

    double est(0);
    for(int i=0; i<n; i++){
        est += (power(-1, i) / myFactorial(2*i)) * power(x, (2*i));
    }
    return(est);
}

double power(double base, double exp){
    if(exp==0){
        return(1);
    }
    double ret = base;
    for(int i=1; i<exp; i++){
        ret *= base;
    }
    return(ret);
}