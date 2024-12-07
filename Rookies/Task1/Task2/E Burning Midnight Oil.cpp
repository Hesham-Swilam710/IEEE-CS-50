#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long low = 1, high = n, result = n;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long total = 0, power = 1, temp = mid;

        while (temp > 0) {
            total += temp;
            power *= k;
            temp = mid / power;
        }

        if (total >= n) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
