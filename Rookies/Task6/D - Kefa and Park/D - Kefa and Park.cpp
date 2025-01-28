

////D

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
bool visited[MAXN];
int has_cat[MAXN];
int n, m;
int leaf_count = 0;

void dfs(int node, int consecutive_cats) {
    visited[node] = true;
    if (has_cat[node]) {
        consecutive_cats++;
    }
    else {
        consecutive_cats = 0;
    }
    if (consecutive_cats > m) {
        return;
    }
    bool is_leaf = true;
    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            is_leaf = false;
            dfs(neighbor, consecutive_cats);
        }
    }
    if (is_leaf) {
        leaf_count++;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> has_cat[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fill(visited, visited + n + 1, false);
    dfs(1, 0);

    cout << leaf_count << endl;

    return 0;
}






