// 2929. Distribute Candies Among Children II
// https://leetcode.com/problems/distribute-candies-among-children-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Enumeration
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans = 0;
        for (int i = 0; i <= min(limit, n); ++i) {
            if (n - i > 2 * limit)
                continue;
            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};
