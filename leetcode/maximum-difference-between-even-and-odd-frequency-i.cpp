// 3442. Maximum Difference Between Even and Odd Frequency I
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxDifference(string s) {
        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];
        int mn_even = 101, mx_odd = 0;
        for (const int& cnt: counter) {
            if (cnt == 0)
                continue;
            bool odd = cnt % 2;
            if (odd)
                mx_odd = max(mx_odd, cnt);
            else
                mn_even = min(mn_even, cnt);
        }
        int ans = mx_odd - mn_even;
        return ans;
    }
};
