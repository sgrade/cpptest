// C. awoo's Favorite Problem

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {

        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        map<char, int> s_cnt, t_cnt;

        bool ans = true;
        queue<char> s_without_b, t_without_b;  // s and t without b
        vector<int> count_b_s(1), count_b_t(1);
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            ++s_cnt[s[i]];
            ++t_cnt[t[i]];
        }

        for (auto &p: s_cnt) {
            if (p.second != t_cnt[p.first]) {
                ans = false;
                goto ANS;
            }
        }
        
        // Idea is from https://codeforces.com/contest/1697/submission/160289797
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                count_b_s.back() += 1;
            }
            else {
                s_without_b.push(s[i]);
                count_b_s.push_back(0);
            }
            if (t[i] == 'b') {
                count_b_t.back() += 1;
            }
            else {
                t_without_b.push(t[i]);
                count_b_t.push_back(0);
            }
        }
        
        for (int i = 0; i < n - s_cnt['b']; ++i) {
            if (s_without_b.front() != t_without_b.front()) {
                ans = false;
                break;
            }
            sum += count_b_s[i] - count_b_t[i];
            // If sum > 0, we need to shift 'b' to the left, which is not possible with 'a'
            if (sum > 0 && s_without_b.front() == 'a') {
                ans = false;
                break;
            }
            // If sum < 0, we need to shift 'b' to the right, which is not possible with 'c'
            if (sum < 0 && s_without_b.front() == 'c') {
                ans = false;
                break;
            }
            s_without_b.pop();
            t_without_b.pop();
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
