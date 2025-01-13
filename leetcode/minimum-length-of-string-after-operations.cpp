// 3223. Minimum Length of String After Operations
// https://leetcode.com/problems/minimum-length-of-string-after-operations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];

        int ans = 0;
        for (const int& cnt: counter) {
            if (cnt == 0)
                continue;
            if (cnt % 2 == 0)
                ans += 2;
            else
                ans += 1;
        }
        return ans;
    }
};
