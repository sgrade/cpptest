// 2551. Put Marbles in Bags
// https://leetcode.com/problems/put-marbles-in-bags/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sorting
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = weights.size();
            vector<int> pairs(n - 1);
            for (int i = 0; i < n - 1; ++i)
                pairs[i] += weights[i] + weights[i + 1];
            sort(pairs.begin(), pairs.end());
            long long ans = 0;
            for (int i = 0; i < k - 1; ++i)
                ans += pairs[n - 2 - i] - pairs[i];
            return ans;
        }
    };
