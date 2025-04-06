// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Recursion with Memoization
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            n = nums.size();
            if (n == 0)
                return {};

            sort(nums.begin(), nums.end());

            vector<int> max_subset;
            for (int i = 0; i < n; ++i) {
                vector<int> subset = check(i, nums);
                if (max_subset.size() < subset.size())
                    max_subset = subset;
            }

            return max_subset;
        }

    private:
        int n;
        unordered_map<int, vector<int>> memo;
        vector<int> check (int i, vector<int>& nums) {
            if (memo.find(i) != memo.end())
                return memo[i];
            vector<int> max_subset;
            for (int k = 0; k < i; ++k) {
                if (nums[i] % nums[k] == 0) {
                    vector<int> subset = check(k, nums);
                    if (max_subset.size() < subset.size())
                        max_subset = subset;
                }
            }
            max_subset.emplace_back(nums[i]);
            memo[i] = max_subset;
            return max_subset;
        }
    };
