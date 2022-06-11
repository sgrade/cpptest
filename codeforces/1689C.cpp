// C. Infected Tree

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void dfs(int cur, int parent, 
vector<vector<int>>& adj, vector<int>& num_of_children, vector<int>& dp) {

    // number of children
    num_of_children[cur] = adj[cur].size() - 1;

    for (int& child: adj[cur]) {
        if (child == parent) {
            continue;
        }

        dfs(child, cur, adj, num_of_children, dp);
        num_of_children[cur] += num_of_children[child];
    }

    vector<int> children;
    for (int& child: adj[cur]) {
        if (child == parent) {
            continue;
        }
        children.push_back(child);
    }

    if (children.size() == 0) {
        dp[cur] = 0;
    }
    else if (children.size() == 1) {
        dp[cur] = num_of_children[children[0]];
    }
    else {
        dp[cur] = max(
            dp[children[0]] + (num_of_children[children[1]]), 
            dp[children[1]] + (num_of_children[children[0]])
        );
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> num_of_children(n + 1);
        vector<int> dp(n + 1);

        int u, v;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, adj, num_of_children, dp);
        std::cout << dp[1] << '\n';
    }

    return 0;
}
