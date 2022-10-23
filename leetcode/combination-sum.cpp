// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backtrack(candidates, target, ans, comb, 0);
        return ans;
    }
    
    void backtrack(vector<int> &candidates, const int &target, vector<vector<int>> &ans, vector<int> &comb, const int start) {
        if (target == 0) {
            ans.emplace_back(comb);
            return;
        }
        else if (target < 0) {
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            comb.emplace_back(candidates[i]);
            backtrack(candidates, target - candidates[i], ans, comb, i);
            comb.pop_back();
        }
    }
};
