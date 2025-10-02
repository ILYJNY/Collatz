#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 그래프 생성
vector<vector<int>> build_graph(int k) {
    int n = 2 * k;
    vector<vector<int>> adj(n);
    for (int x = 0; x < n; x++) {
        if (x % 2 == 0) {
            adj[x].push_back(x / 2);
            adj[x].push_back(k + x / 2);
        } else {
            adj[x].push_back((3 * x + 1) % n);
        }
    }
    return adj;
}

// DFS로 최대 사이클 길이 계산
void dfs_maxlen(int start, int u, vector<vector<int>> &adj, vector<int> &path, int &max_len, vector<bool> &visited) {
    visited[u] = true;
    path.push_back(u);

    for (int v : adj[u]) {
        if (v == start) {
            max_len = max(max_len, (int)path.size());
        } else if (!visited[v]) {
            dfs_maxlen(start, v, adj, path, max_len, visited);
        }
    }

    path.pop_back();
    visited[u] = false;
}

int main() {
    cout << "p\tk\t n\t max_cycle_length\t ratio\n";
    for (int p = 1; p <= 32; p++) {
        int k = 2 * p;
        int n = 2 * k;
        auto adj = build_graph(k);

        int max_len = 0;
        vector<int> path;
        vector<bool> visited(n, false);

        for (int start = 0; start < n; start++) {
            dfs_maxlen(start, start, adj, path, max_len, visited);
        }

        double ratio = (double)max_len / n;
        cout << p << "\t" << k << "\t" << n << "\t" << max_len << "\t\t\t" << ratio << "\n";
    }
    return 0;
}