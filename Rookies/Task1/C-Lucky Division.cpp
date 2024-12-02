//// c

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        bool isLucky = true;
        int temp = i;


        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 4 && digit != 7) {
                isLucky = false;
                break;
            }
            temp /= 10;
        }


        if (isLucky && n % i == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }


    cout << "NO" << endl;
    return 0;
}



