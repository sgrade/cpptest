// C. Zero Path
// Time limit exceeded on pretest 4
 
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
int n, m;
 
bool ans;
 
void dfs(const vector<vector<int>>& a, int i, int j, int cost) {
    
    cost += a[i][j];
    if (i == n - 1 && j == m - 1) {
        if (cost == 0) {
            ans = true;
        }
    }
 
    if (i + 1 < n) {
        dfs(a, i + 1, j, cost);
    }
    if (j + 1 < m) {
        dfs(a, i, j + 1, cost);
    }
}
 
 
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
 
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
 
        ans = false;
 
        dfs(a, 0, 0, 0);
 
        cout << (ans ? "YES\n" : "NO\n");
    }
 
    return 0;
}
