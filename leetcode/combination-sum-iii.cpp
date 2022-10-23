// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backtrack(n, k, comb, 0, ans);
        return ans;
    }
    
    void backtrack(const int sm, const int k, vector<int> comb, const int next_start, vector<vector<int>> &ans) {
        if (sm == 0 && comb.size() == k) {
            ans.emplace_back(comb);
            return;
        }        
        else if (sm < 0 || comb.size() == k) {
            return;
        }
        
        for (int i = next_start; i < 9; ++i) {
            comb.emplace_back(i + 1);
            backtrack(sm - comb.back(), k, comb, i + 1, ans);
            comb.pop_back();
        }
    }
};
