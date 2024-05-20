// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Generate All Subsets Using Backtracking
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        GetSubsets(nums, 0, {});

        int ans = 0;
        for (const vector<int>& subset: subsets) {
            int current_ans = 0;
            for (const int& num: subset)
                current_ans ^= num;
            ans += current_ans;
        }
        return ans;
    }

private:
    int n;
    vector<vector<int>> subsets;
    void GetSubsets(const vector<int>& nums, int idx, vector<int> subset) {
        if (idx == n) {
            subsets.emplace_back(subset);
            return;
        }

        subset.emplace_back(nums[idx]);
        GetSubsets(nums, idx + 1, subset);

        subset.pop_back();
        GetSubsets(nums, idx + 1, subset);
    }
};
