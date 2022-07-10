// E. Split Into Two Sets
// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// The dfs code is from my own solution for the leetcode problem
// https://github.com/sgrade/cpptest/blob/master/leetcode/is-graph-bipartite_recursive.cpp
bool dfs(int idx, int color, vector<int> &visited, const vector<vector<int>>& graph) {
    visited[idx] = color;
    int cur;
    for (int i = 0; i < graph[idx].size(); ++i) {
        cur = graph[idx][i];
        if (visited[cur] == -1) {
            if (!dfs(cur, color ^ 1, visited, graph)) {
                return false;
            }
        }
        else if (visited[idx] == visited[cur]) {
            return false;
        }
    }
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        bool ans = true;
        
        vector<vector<int>> graph(n + 1);
        int a, b;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            if (a == b) ans = false;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        
        if (ans) {
            vector<int> visited(n + 1, -1);
            for (int i = 1; i < n + 1; ++i) {
                if (visited[i] != -1) {
                    continue;
                }
                if (!dfs(i, 0, visited, graph)) {
                    ans = false;
                    break;
                }
            }
        }
        
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
