// A. DZY Loves Chessboard
// Wrong answer on test 5

#include <iostream>
#include <vector>

using namespace std;


vector<string> a;
int n, m;
vector<vector<char>> ans;

void explore(const int &r, const int &c) {
    
    if (a[r][c] != '.') {
        ans[r][c] = '-';
        return;
    }

    bool b = true;
    bool w = true;

    if (r - 1 >= 0) {
        if (ans[r-1][c] == 'B') b = false;
        if (ans[r-1][c] == 'W') w = false;
    }

    if (c - 1 >= 0) {
        if (ans[r][c-1] == 'B') b = false;
        if (ans[r][c-1] == 'W') w = false;
    }

    if (!b) {
        ans[r][c] = 'W';
    }
    else if (!w) {
        ans[r][c] = 'B';
    }
    else {
        if (c % 2 == 0) {
            ans[r][c] = 'B';
        }
        else {
            ans[r][c] = 'W';
        }
    }

    return;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ans.resize(n, vector<char>(m));

    int d = 0;
    while (d < max(n, m)) {
        
        if (d < n) {
                
            int i = d;
            for (int j = 0; j < d + 1 && j < m; ++j) {
                explore(i, j);
            }
        }

        if (d < m) {
            int j = d;
            for (int i = 0; i < d && i < n; ++i) {
                explore(i, j);
            }
        }
    
        ++d;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
