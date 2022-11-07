// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current{};
        backtrack(nums, ans, n, 0, current);
        return ans;
    }
    
private:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans, const int &n, const int &start, vector<int> &current) {
        ans.emplace_back(current);
        for (int i = start; i < n; ++i) {
            if (i != start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.emplace_back(nums[i]);
            backtrack(nums, ans, n, i + 1, current);
            current.pop_back();
        }
    }
};
