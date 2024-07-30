// 1653. Minimum Deletions to Make String Balanced
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 6: Optimized DP
class Solution {
public:
    int minimumDeletions(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size(), b_count = 0, ans = 0;
        for (const char& ch: s) {
            if (ch == 'b')
                ++b_count;
            else
                // remove 'a' or 'b'
                ans = min (ans + 1, b_count);
        }
        return ans;
    }
};
