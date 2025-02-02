
//  Hesham Swilam && Mohamed Khalid Ibrahim
//I Falfoul and Zanqoun's Wormy Lunch
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }

    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    vector<int> cumulative_sums(n);
    cumulative_sums[0] = piles[0];
    for (int i = 1; i < n; ++i) {
        cumulative_sums[i] = cumulative_sums[i - 1] + piles[i];
    }

    for (int i = 0; i < m; ++i) {
        int worm_label = queries[i];
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (worm_label <= cumulative_sums[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        cout << left + 1 << endl;
    }

    return 0;
}

