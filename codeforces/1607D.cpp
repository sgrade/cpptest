// D. Blue-Red Permutation

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<pair<char, int>> a(n);
        for (auto &p: a) {
            cin >> p.second;
            --p.second;
        }

        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            a[i].first = s[i];
        }

        bool ans = true;

        sort(begin(a), end(a));

        for (int i = 0; i < n; ++i) {

            // Editorial - https://codeforces.com/blog/entry/96604

            if (a[i].first == 'B') {
                if (a[i].second < i) {
                    ans = false;
                    break;
                }
            }

            // a[i].first == 'R'
            else {
                if (a[i].second > i) {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
