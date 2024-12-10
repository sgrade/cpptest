// 2981. Find Longest Special Substring That Occurs Thrice I
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumLength(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<string, size_t> counter;
        int left = 0, right = 0;
        while (right < s.size()) {
            if (s[left] != s[right]) {
                left = right;
                continue;
            }
            for (int i = left; i <= right; ++i) {
                string subs = s.substr(left, i - left + 1);
                ++counter[subs];
            }
            ++right;
        }
        size_t ans = 0;
        for (const auto& [subs, cnt]: counter) {
            if (cnt > 2)
                ans = max(ans, subs.size());
        }
        return ans == 0 ? -1 : ans;
    }
};
