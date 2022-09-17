// C. Word Game

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;

        vector<int> ans(3);

        map<string, vector<int>> mp;

        string s;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> s;
                if (mp.find(s) == mp.end()) {
                    mp[s] = {0, 0, 0};
                }
                ++mp[s][i];
            }
        }

        int cnt, idx;
        for (auto &[word, vect]: mp) {
            cnt = count(vect.begin(), vect.end(), 0);
            if (cnt == 2) {
                for (idx = 0; idx < 3; ++idx) {
                    if (vect[idx] != 0) break;
                }
                ans[idx] += 3;
            }
            else if (cnt == 1) {
                for (idx = 0; idx < 3; ++idx) {
                    if (vect[idx] != 0) {
                        ++ans[idx];
                    }
                }
            }
        }

        for (int &el: ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    cout << __cplusplus << '\n';

    return 0;
}