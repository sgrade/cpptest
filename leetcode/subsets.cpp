// 78. Subsets
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        for (int k = 0; k < n + 1; ++k) {
            backtrack(0, cur, nums, ans, k, n);
        }
        return ans;                
    }
    
    void backtrack(int first, vector<int>& cur, const vector<int>& nums, vector<vector<int>>& ans, const int& k, const int& n) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = first; i < n; ++i) {
            cur.push_back(nums[i]);
            backtrack(i + 1, cur, nums, ans, k, n);
            cur.pop_back();
        }
    }
};
