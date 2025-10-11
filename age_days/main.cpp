#include <iostream>
using namespace std;

int main() {
    const int years = 26;       
    const int days_per_year = 365; 
    const int days = years * days_per_year;

    cout << "I am " << years << " years or " << days << " days old." << endl;
    return 0;
}
