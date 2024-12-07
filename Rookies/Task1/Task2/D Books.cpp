#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxBooks = 0, currentTime = 0, start = 0;

    for (int end = 0; end < n; end++) {
        currentTime += a[end];
        while (currentTime > t) {
            currentTime -= a[start];
            start++;
        }
        maxBooks = max(maxBooks, end - start + 1);
    }

    cout << maxBooks << endl;
    return 0;
}
