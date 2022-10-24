// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Backtracking with Counters
class Solution {
public:
    map<int, int> counter;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        for (const int &el: candidates) {
            ++counter[el];
        }
        
        vector<int> counter_list;
        for (const auto[key, value]: counter) {
            counter_list.emplace_back(key);
        }
        
        backtrack(comb, target, 0, counter_list, ans);
        return ans;
    }
    
    void backtrack(vector<int> comb, const int target, const int current, vector<int> &counter_list, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.emplace_back(comb);
            return;
        }
        else if (target < 0) {
            return;
        }
        
        for (int i = current; i < counter_list.size(); ++i) {
            int candidate = counter_list[i];
            if (counter[candidate] <= 0) {
                continue;
            }

            comb.emplace_back(candidate);
            --counter[candidate];
            backtrack(comb, target-candidate, i, counter_list, ans);
            comb.pop_back();
            ++counter[candidate];
        }
        
    }
};
