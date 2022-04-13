// C. Madoka and Childish Pranks

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (string &s: a) {
            cin >> s;
        }

        vector<vector<int>> output;

        int ans = -1;

        vector<int> tmp(4);
        if (a[0][0] != '1') {
            ans = 0;

            for (int i = n - 1; i > 0; --i) {
                for (int j = m - 1; j > -1; --j) {
                    if (a[i][j] == '1') {
                        tmp[0] = i - 1;
                        tmp[1] = j;
                        tmp[2] = i;
                        tmp[3] = j;
                        output.push_back(tmp);
                        ++ans;
                    }
                }
            }

            for (int j = m - 1; j > 0; --j) {
                if (a[0][j] == '1') {
                    tmp[0] = 0;
                    tmp[1] = j - 1;
                    tmp[2] = 0;
                    tmp[3] = j;
                    output.push_back(tmp);
                    ++ans;
                }
            }
        }

        cout << ans << '\n';

        if (ans != -1) {
            for (vector<int> &v: output) {
                for (int &el: v) {
                    cout << el + 1 << ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}
