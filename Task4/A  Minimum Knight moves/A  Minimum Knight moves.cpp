
////A


#include <iostream>
#include <queue>

using namespace std;

const int BOARD_SIZE = 8;
const int KNIGHT_MOVES[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValidMove(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

int minKnightMoves(const string& start, const string& destination) {
    if (start == destination) return 0;

    int startX = start[0] - 'a';
    int startY = start[1] - '1';
    int destX = destination[0] - 'a';
    int destY = destination[1] - '1';

    bool visited[BOARD_SIZE][BOARD_SIZE] = {false};
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int moves = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();

            if (x == destX && y == destY) {
                return moves;
            }

            for (const auto& move : KNIGHT_MOVES) {
                int newX = x + move[0];
                int newY = y + move[1];

                if (isValidMove(newX, newY) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        ++moves;
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string start, destination;
        cin >> start >> destination;
        cout << minKnightMoves(start, destination) << endl;
    }

    return 0;
}