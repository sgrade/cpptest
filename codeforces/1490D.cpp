// D. Permutation Transformation
// NOT FINISHED

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<int> a;
vector<vector<int>> adj;
vector<bool> visited;
int d;
vector<int> ans(n + 1);

void add_edge (int &cur_idx, int &mx_idx) {
    visited[cur_idx] = true;
    adj[cur_idx].push_back(mx_idx);
    adj[mx_idx].push_back(cur_idx);
}

int find_mx_idx (int l, int r) {

    if (l > r) {
        return;
    }

    if (l == r) {
        ans[l] = d;
        --d;
        return;
    }

    int cur = 0, cur_idx;

    for (int i = l; i < r + 1; ++i) {
        if (a[i] > cur) {
            cur = a[i];
            cur_idx = i;
        }
    }

    return cur_idx;
} 

void explore (int mx_idx, int l, int r) {

    
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        cin >> n;

        a.clear();
        a.resize(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> a[i];
        }

        adj.clear();
        adj.resize(n + 1);
        visited.clear();
        visited.resize(n + 1);
        
        vector<int>::iterator it = max_element(a.begin(), a.end());
        int mx_idx = distance(a.begin(), it);
        int mx = a[mx_idx];
        visited[mx_idx] = true;
        
        d = 0;
        ans.clear();
        ans.resize(n + 1);
        explore(mx_idx, 1, n);

        for (int i = 1; i < n + 1; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
