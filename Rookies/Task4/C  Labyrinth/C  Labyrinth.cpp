////C
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
const char direction[4] = { 'U', 'D', 'L', 'R' };

int n, m;
char labyrinth[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> parent[MAX][MAX];
char moveDirection[MAX][MAX];

bool isValidMove(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}

void enqueue(queue<pair<int, int>>& q, int newX, int newY, int x, int y, char dir) {
    visited[newX][newY] = true;
    parent[newX][newY] = { x, y };
    moveDirection[newX][newY] = dir;
    q.push({ newX, newY });
}

string reconstructPath(pair<int, int> end) {
    string path;
    pair<int, int> curr = end;

    while (labyrinth[curr.first][curr.second] != 'A') {
        path.push_back(moveDirection[curr.first][curr.second]);
        curr = parent[curr.first][curr.second];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') {
                start = { i, j };
            }
            else if (labyrinth[i][j] == 'B') {
                end = { i, j };
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == end.first && y == end.second) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValidMove(newX, newY)) {
                enqueue(q, newX, newY, x, y, direction[i]);
            }
        }
    }

    if (found) {
        string path = reconstructPath(end);
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
