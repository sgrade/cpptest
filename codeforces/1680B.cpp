// B. Robots

#include <iostream>
#include <vector>
#include <algorithm>
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

        vector<string> a(n);
        for (string &s: a) cin >> s;

        bool ans = false;

        pair<int, int> min_i, min_j;
        bool found_min_j = false, found_min_i = false;
        bool can_go_left = true, can_go_up = true;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'R') {
                    found_min_j = true;
                    min_j = pair<int, int> (i, j);
                    break;
                }
            }
            if (found_min_j) {
                break;
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == 'R') {

                    if (j < min_j.second) {
                        can_go_left = false;
                    }

                    else {
                        min_i = pair<int, int> (i, j);
                        if (min_i.first < min_j.first) {
                            can_go_up = false;
                        }
                        found_min_i = true;
                        break;
                    }
                }
            }
            if (found_min_i) {
                break;
            }
        }

        if (can_go_left && can_go_up) {
            ans = true;
        }

        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}
