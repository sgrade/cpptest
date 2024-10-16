// 1405. Longest Happy String
// https://leetcode.com/problems/longest-happy-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n = a + b + c;
        vector<pair<int, char>> counter = {
            {a, 'a'},
            {b, 'b'},
            {c, 'c'}
        };

        string ans = "";
        while (n > 0) {
            sort (counter.begin(), counter.end(), greater<>());
            auto& [cur_cnt, cur_ch] = counter[0];
            if (cur_cnt == 0)
                break;
            if (!ans.empty() && ans.back() == cur_ch) {
                if (ans.size() > 1 && ans[ans.size() - 2] == cur_ch)
                    break;
                cur_cnt = 1;
            }
            auto& [nxt_cnt, nxt_ch] = counter[1];
            if (cur_cnt - nxt_cnt > 1) {
                ans += cur_ch;
                ans += cur_ch;
                cur_cnt -= 2;
                n -= 2;
            }
            else {
                ans += cur_ch;
                --cur_cnt;
                --n;
            }
            if (nxt_cnt > 0) {
                ans += nxt_ch;
                --nxt_cnt;
                --n;
            }
        }

        return ans;
    }
};
