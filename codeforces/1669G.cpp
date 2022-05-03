// G. Fall Down

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<string> v(n);
        for (string &s: v) cin >> s;

        vector<vector<char>> output(n, vector<char>(m, '.'));
        
        int last_o;
        for (int j = 0; j < m; ++j) {
            last_o = n;
            for (int i = n-1; i > -1; --i) {
                if (v[i][j] == 'o') {
                    output[i][j] = 'o';
                    last_o = i;
                }
                else if (v[i][j] == '*') {
                    output[last_o - 1][j] = '*';
                    --last_o;
                }
            }
        }

        for (auto &vec: output) {
            for (char &ch: vec) {
                cout << ch;
            }
            cout << '\n';
        }

        cout << '\n';
    }


    return 0;
}
