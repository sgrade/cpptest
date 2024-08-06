// 3016. Minimum Number of Pushes to Type Word II
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumPushes(string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> counter(26);
        for (const char& ch: word)
            ++counter[ch - 'a'];
        int ans = 0;
        sort (counter.begin(), counter.end(), greater<int>());
        int i = 8;
        for (const int& cnt: counter) {
            ans += cnt * (i / 8);
            ++i;
        }
        return ans;
    }
};
