// 46. Permutations
// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        backtrack(n, nums, ans, 0);
        return ans;
    }
    
    void backtrack(int& n, vector<int>& nums, vector<vector<int>>& ans, int first) {
        if (first == n) {
            ans.push_back(nums);
        }
        for (int i = first; i < n; ++i) {
            swap(nums[first], nums[i]);
            backtrack(n, nums, ans, first + 1);
            swap(nums[first], nums[i]);
        }
    }
};
