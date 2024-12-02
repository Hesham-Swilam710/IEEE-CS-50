//// d
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string dirs;
    cin >> dirs;
    long long* x=new long long [n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }


    long long minTime = -1;
    for (int i = 0; i < n - 1; i++) {

        if (dirs[i] == 'R' && dirs[i + 1] == 'L') {

            long long time = (x[i + 1] - x[i]) / 2;

            if (minTime == -1 || time < minTime) {
                minTime = time;
            }
        }
    }


    cout << minTime << endl;

    return 0;
}


