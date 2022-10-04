// C. Phase Shift

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::string alpha = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        string ans;

        // prev - prev letter in the circle
        // nxt - next letter in the circle
        vector<int> prev(26, -1), nxt(26, -1);

        int i = 0;
        for (; i < n ; ++i) {

            char ch = s[i];
            int ch_idx = s[i] - 'a';

            if (prev[ch_idx] != -1) {
                ans += alpha[prev[ch_idx]];
                continue;
            }
            
            // Some ideas are from - https://codeforces.com/contest/1735/submission/174417757
            for (int j = 0; j < 26; ++j) {
                char candidate = alpha[j];
                if (ch_idx != j && nxt[j] == -1) {
                    prev[ch_idx] = j;
                    nxt[j] = ch_idx;

                    int cnt = 1;
                    int tmp_idx = j;
                    bool cycle_is_too_short = false;
                    while (tmp_idx != -1) {
                        tmp_idx = nxt[tmp_idx];
                        ++cnt;
                        if (tmp_idx == j) {
                            if (cnt <= 26) {
                                cycle_is_too_short = true;
                            }
                            break;
                        }
                    }

                    if (cycle_is_too_short) {
                        prev[ch_idx] = -1;
                        nxt[j] = -1;
                    }
                    else {
                        ans += alpha[j];
                        break;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
