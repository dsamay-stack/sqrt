#include <iostream>
#include <cmath>     
#include "root.h"   
using namespace std;

int main() {
    double x(2.0);
    cout << "give your value for x ";
    cin >> x;
    double r_lib = sqrt(x);
    double r_my = root(x);

    cout << "sqrt(x) = " << r_lib << endl;
    cout << "root(x) = " << r_my << endl;

    return 0;
}
