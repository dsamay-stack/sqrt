#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int rows = 8;
    const int cols = 5;
    int a[rows][cols];

    srand(time(nullptr));

    // заповнення масиву випадковими числами [10; 99]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = 10 + rand() % 90;
        }
    }

    // вивід масиву на екран
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
