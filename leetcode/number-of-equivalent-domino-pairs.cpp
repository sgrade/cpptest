// 1128. Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Editorial's Approach: Tuple Representation + Counting
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ans = 0;
            vector<int> counter(100);
            for (vector<int>& v: dominoes) {
                if (v[0] > v[1])
                    swap(v[0], v[1]);
                int hash = v[0] * 10 + v[1];
                ans += counter[hash];
                ++counter[hash];
            }
            return ans;
        }
    };
