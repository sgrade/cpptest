// 3480. Maximize Subarrays After Removing One Conflicting Pair
// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach: Enumeration
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> b_min1(n + 1, INT_MAX), b_min2(n + 1, INT_MAX);
        for (const auto& p: conflictingPairs) {
            int a = p[0], b = p[1];
            if (a > b) swap(a, b);
            if (b < b_min1[a]) {
                b_min2[a] = b_min1[a];
                b_min1[a] = b;
            }
            else if (b < b_min2[a])
                b_min2[a] = b;
        }

        long long ans = 0;
        int idx_b1 = n, b2 = INT_MAX;
        vector<long long> deletions(n + 1);
        long long max_deletions = 0;

        for (int i = n; i >= 1; --i) {
            if (b_min1[idx_b1] > b_min1[i]) {
                b2 = min(b2, b_min1[idx_b1]);
                idx_b1 = i;
            }
            else
                b2 = min(b2, b_min1[i]);

            int right_bound = min(b_min1[idx_b1], n + 1);
            ans += right_bound - i;

            int del_bound = min({b2, b_min2[idx_b1], n + 1});
            deletions[idx_b1] += del_bound - right_bound;
            max_deletions = max(max_deletions, deletions[idx_b1]);
        }

        ans += max_deletions;
        return ans;
    }
};
