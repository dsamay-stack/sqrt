#include <iostream>
#include <vector>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main() {
   
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    int n;
    wcout << L"Введіть кількість елементів: ";
    if (!(wcin >> n) || n <= 0) {
        wcout << L"Некоректний розмір.\n";
        return 0;
    }

    vector<double> a(n);
    wcout << L"Введіть " << n << L" чисел: ";
    for (int i = 0; i < n; ++i) wcin >> a[i];

    vector<double> asc = a, desc = a;
    sort(asc.begin(), asc.end());
    sort(desc.begin(), desc.end(), greater<double>());

    wcout << L"За зростанням: ";
    for (double x : asc) wcout << x << L' ';
    wcout << L"\n";

    wcout << L"За спаданням: ";
    for (double x : desc) wcout << x << L' ';
    wcout << L"\n";

    return 0;
}
