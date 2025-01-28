
///A
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1001;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;

void dfs(int x, int y, int& volume) {
    visited[x][y] = true;
    volume += grid[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > 0) {
            dfs(nx, ny, volume);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int maxVolume = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    int volume = 0;
                    dfs(i, j, volume);
                    maxVolume = max(maxVolume, volume);
                }
            }
        }
        cout << maxVolume << endl;
    }
    return 0;
}
