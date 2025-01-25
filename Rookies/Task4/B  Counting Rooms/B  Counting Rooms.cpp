

////B

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;
char building[MAX][MAX];
bool visited[MAX][MAX];

int n, m;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && building[nx][ny] == '.') {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> building[i][j];
            visited[i][j] = false;
        }
    }

    int room_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (building[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                room_count++;
            }
        }
    }

    cout << room_count << endl;

    return 0;
}





