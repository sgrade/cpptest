// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = candidates.size();
        sort (candidates.begin(), candidates.end());
        vector<int> combination;
        Backtrack (combination, candidates, target, 0);
        return ans;
    }
private:
    int n;
    vector<vector<int>> ans;
    void Backtrack (vector<int>& combination, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.emplace_back (combination);
            return;
        }
        for (int i = idx; i < n && target >= candidates[i]; ++i) {
            if (i == idx || candidates[i] != candidates[i - 1]) {
                combination.emplace_back(candidates[i]);
                Backtrack (combination, candidates, target - candidates[i], i + 1);
                combination.pop_back();
            }
        }
    }
};
