#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;

    for (int x = 2; x <= 20; x += 2) {
        a.push_back(x);
    }

    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i + 1 < a.size()) cout << " ";
    }
    cout << "\n";

    for (int x : a) {
        cout << x << "\n";
    }

    return 0;
}
