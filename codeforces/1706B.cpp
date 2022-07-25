// B. Making Towers

#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        map<int, vector<int>> indexes;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            indexes[tmp].emplace_back(i);
        }

        vector<int> ans(n + 1);

        // Editorial - https://codeforces.com/blog/entry/105008

        int d;
        for (auto &[color, v]: indexes) {
            ans[color] = 1;
            for (int i = 1; i < v.size(); ++i) {
                d = v[i] - v[i - 1];
                if (d % 2 != 0) {
                    ++ans[color];
                }
            }
        }

        for (int i = 1; i < n + 1; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
