 //  Hesham Swilam && Mohamed Khalid Ibrahim
// A  Falfoul's Tennis Triumph
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> results(N);
    for (int i = 0; i < N; ++i) {
        cin >> results[i];
    }

    int score = 0, streak = 0;
    for (int i = 0; i < N; ++i) {
        if (results[i] == 1) {
            score++;
            streak++;
            if (streak >= 3) {
                score++;
            }
        }
        else {
            score--;
            streak = 0;
        }
    }

    cout << score << endl;
    return 0;
}

