// A. Colour the Flag

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<string> inp(n);
        for (auto &el: inp) {
            getline(cin >> ws, el);
        }

        int i = 0, j = 0;

        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            auto x = inp[i].size();
            for (int j = 0; j < m; ++j) {
                v[i][j] = inp[i][j];
            }
        }

        bool ans = true;

        // Odd-even cells template
        vector<vector<char>> oe(2, vector<char>(2, '.'));
        
        char ch1 = '.';
        char ch2 = '.';
        
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (v[i][j] != '.') {
                    oe[i%2][j%2] = v[i][j];
                    
                    ch1 = v[i][j];
                    ch2 = ch1 == 'W' ? 'R' : 'W';

                    goto NXT1;
                }
            }
        }

        NXT1:
        if (ch1 == '.') {
            ch1 = 'R';
            ch2 = 'W';
            i = 0;
            j = 0;
        }
        
        for (int p = 0; p < 2; ++p) {
            for (int q = 0; q < 2; ++q) {
                if (p == i%2) {
                    if (q != j%2) {
                        oe[p][q] = ch2;
                    }
                    else {
                        oe[p][q] = ch1;
                    }
                }
                else {
                    if (q != j%2) {
                        oe[p][q] = ch1;
                    }
                    else {
                        oe[p][q] = ch2;
                    }
                }
            }
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (v[i][j] != oe[i%2][j%2]) {

                    if (v[i][j] == '.') {
                        v[i][j] = oe[i%2][j%2];
                    }

                    else {
                        ans = false;
                        goto NXT2;
                    }

                }
            }
        }

        NXT2:
        if (ans) {
            cout << "YES" << endl;
            for (auto &row: v) {
                for (auto &cell: row) {
                    cout << cell;
                }
                cout << endl;
            }
        }

        else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
