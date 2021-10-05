// A. Protect Sheep

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int R, C;
    cin >> R >> C;

    vector<string> v(R);
    for (auto &s: v) {
        cin >> s;
    }

    bool ans = true;
    vector<vector<char>> output(R, vector<char>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (v[i][j] == 'S') {
                if (v[i][max(0, j-1)] == 'W' || 
                    v[i][min(C-1, j+1)] == 'W' ||
                    v[max(0, i-1)][j] == 'W' || 
                    v[min(R-1, i+1)][j] == 'W') {
                        ans = false;
                        goto BRK;
                }
                else {
                    output[i][j] = 'S';
                }
            }
            
            else if (v[i][j] == '.') {
                output[i][j] = 'D';
            }

            else {
                output[i][j] = 'W';
            }
        }
    }

    BRK:
    cout << (ans ? "YES" : "NO") << '\n';
    if (ans) {
        for (auto &row: output) {
            for (auto &ch: row) {
                cout << ch;
            }
            cout << '\n';
        }
    }

    return 0;
}
