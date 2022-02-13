// B. Boboniu Plays Chess

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    vector<vector<bool>> visited (n+1, vector<bool>(m+1));

    int i = sx, j = sy;
    for (; i > 0; --i) {
        cout << i << ' ' << j << '\n';
        visited[i][j] = true;
    }
    i = 1;
    --j;
    for (; j > 0; --j) {
        cout << i << ' ' << j << '\n';
        visited[i][j] = true;
    }

    for (i = 1; i < n + 1; ++i) {
        int j_begin = i % 2 == 0 ? m : 1;
        int j_diff = i % 2 == 0 ? -1 : 1;
        int cnt = 0;
        for (j = j_begin; cnt < m; ++cnt, j += j_diff) {
            if (!visited[i][j]) {
                cout << i << ' ' << j << '\n';
            }
        }
    }

    return 0;
}
