#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	long long d;
	cin >> n >> d;
	vector<long long> points(n);

	for (int i = 0; i < n; i++) {
		cin >> points[i];
	}

	long long count = 0;

	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && points[j] - points[i] <= d) {
			j++;
		}
		long long m = j - i - 1;
		if (m >= 2) {
			count += (m * (m - 1)) / 2; 
		}
	}

	cout << count << endl;
	return 0;
}
