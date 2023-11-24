// 1561. Maximum Number of Coins You Can Get
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(piles.begin(), piles.end(), greater<int>());
        int ans = 0;
        int n = piles.size() / 3 * 2;
        for (int i = 1; i < n; i += 2)
            ans += piles[i];
        return ans;
    }
};
