// B. Chess Tournament

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        bool ans = true;

        vector<vector<char>> output(n, vector<char>(n, '0'));

        vector<int> want_to_win;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '2') {
                want_to_win.push_back(i);
            }
        }

        vector<int> losses_left(n);
        for (auto &i: want_to_win) {
            losses_left[i] = want_to_win.size() - 2;
        }

        for (auto &i: want_to_win) {
            bool found_loser = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && output[i][j] == '0' && losses_left[j] > 0) {
                    --losses_left[j];
                    output[i][j] = '+';
                    output[j][i] = '-';
                    found_loser = true;
                    break;
                }
            }
            if (!found_loser) {
                ans = false;
                break;
            }
        }

        if (ans) {
            for (int i = 0; i < n; ++i) {            
                for (int j = 0; j < n; ++j) {
                    if (i == j) {
                        output[i][j] = 'X';
                    }
                    else if (output[i][j] == '0') {
                        output[i][j] = '=';
                        output[j][i] = '=';
                    }
                }
            }
        }
        
        if (ans) {
            cout << "YES" << endl;
            for (auto &v: output) {
                for (auto &ch: v) {
                    cout << ch;
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
