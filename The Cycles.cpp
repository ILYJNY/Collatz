#include <iostream>
#include <vector>
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

// DFS로 모든 단순 사이클 찾기
void dfs_cycles(int start, int u, vector<vector<int>> &adj, vector<int> &path, vector<vector<int>> &cycles, vector<bool> &visited) {
    visited[u] = true;
    path.push_back(u);

    for (int v : adj[u]) {
        if (v == start) {
            // 사이클 발견, path 복사
            cycles.push_back(path);
        } else if (!visited[v]) {
            dfs_cycles(start, v, adj, path, cycles, visited);
        }
    }

    path.pop_back();
    visited[u] = false;
}

int main() {
    int p;
    cout << "Enter p (for k = 2*p): ";
    cin >> p;
    int k = 2 * p;
    int n = 2 * k;

    auto adj = build_graph(k);

    vector<vector<int>> cycles;
    vector<int> path;
    vector<bool> visited(n, false);

    for (int start = 0; start < n; start++) {
        dfs_cycles(start, start, adj, path, cycles, visited);
    }

    cout << "Total cycles found: " << cycles.size() << "\n\n";

    for (size_t i = 0; i < cycles.size(); i++) {
        cout << "Cycle " << i+1 << ": ";
        for (int node : cycles[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}