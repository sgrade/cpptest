// 2554. Maximum Number of Integers to Choose From a Range I
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<int> ban(banned.begin(), banned.end());
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (ban.find(i) != ban.end())
                continue;
            if (maxSum - i < 0)
                return ans;
            maxSum -= i;
            ++ans;
        }
        return ans;
    }
};
