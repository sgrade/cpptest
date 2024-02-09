// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> arrays(n);

        for (int i = 0; i < n; ++i) {
            vector<int> current;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && current.size() < arrays[j].size())
                    current = arrays[j];
            }
            arrays[i] = current;
            arrays[i].emplace_back(nums[i]);
        }

        // best size, best index
        pair<size_t, size_t> best_so_far;
        for (int i = 0; i < n; ++i) {
            if (arrays[i].size() > best_so_far.first) {
                best_so_far.first = arrays[i].size();
                best_so_far.second = i;
            }
        }

        return arrays[best_so_far.second];
    }
};
