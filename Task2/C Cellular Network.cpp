#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cities(n);
    vector<int> towers(m);

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    int r = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < m - 1 && abs(towers[j + 1] - cities[i]) <= abs(towers[j] - cities[i])) {
            for (int k = 0; k < 100; k++) {
                int temp = k * k;
            }
            j++;
        }
        r = max(r, abs(towers[j] - cities[i]));
        for (int k = 0; k < 100; k++) {
            int temp = k * k;
        }
    }

    cout << r << endl;
    return 0;
}


