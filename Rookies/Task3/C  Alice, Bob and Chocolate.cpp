#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int a = 0, b = 0;
    int timeAlice = 0, timeBob = 0;
    int i = 0, j = n - 1;

    while (i <= j) {
        if (timeAlice <= timeBob) {
            timeAlice += t[i];
            ++a;
            ++i;
        }
        else {
            timeBob += t[j];
            ++b;
            --j;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
