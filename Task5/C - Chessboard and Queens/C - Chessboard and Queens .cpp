//C
#include <iostream>
using namespace std;

const int N = 8;
char board[N][N];
bool cols[N], diag1[2 * N - 1], diag2[2 * N - 1];
int ways = 0;

void solve(int row) {
    if (row == N) {
        ways++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (board[row][col] == '.' && !cols[col] && !diag1[row - col + N - 1] && !diag2[row + col]) {
            cols[col] = diag1[row - col + N - 1] = diag2[row + col] = true;
            solve(row + 1);
            cols[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    solve(0);
    cout << ways << endl;
    return 0;
}
