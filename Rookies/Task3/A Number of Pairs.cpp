#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long count = 0;
        for (int i = 0; i < n - 1; ++i) {
            int left = i + 1;
            int right = n - 1;
            int lower = -1, upper = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[i] + a[mid] >= l) {
                    lower = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            left = i + 1;
            right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[i] + a[mid] <= r) {
                    upper = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (lower != -1 && upper != -1 && lower <= upper) {
                count += upper - lower + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}
