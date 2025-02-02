
//  Hesham Swilam && Mohamed Khalid Ibrahim
//J Falfoul's Nice Number Hunt
#include <iostream>
using namespace std;

bool isNiceNumber(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 6 && digit != 9) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int findNiceNumber(int n) {
    while (!isNiceNumber(n)) {
        n++;
    }
    return n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << findNiceNumber(n) << endl;
    }
    return 0;
}







