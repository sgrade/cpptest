// B. Tiling Challenge

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    string s;
    vector<vector<bool>> v(n, vector<bool>(n));

    bool ans = true;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = s[j] == '#' ? true : false;
        }
    }

    // Editorial - https://codeforces.com/blog/entry/66783

    vector<vector<bool>> piece(3, vector<bool>(3));
    piece[0][1] = true;
    piece[1][0] = true;
    piece[1][1] = true;
    piece[1][2] = true;
    piece[2][1] = true;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (!v[i][j]) {
                bool flag = true;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (piece[x][y]) {
                            if (j+y-1 < 0 || j+y-1 > n-1) {
                                ans = false;
                                goto ANS;
                            }
                            if (v[i+x][j+y-1]) {
                                ans = false;
                                goto ANS;
                            }
                            else {
                                v[i+x][j+y-1] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!v[i][j]) {
                ans = false;
                goto ANS;
            }
        }
    }

    ANS:
    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
