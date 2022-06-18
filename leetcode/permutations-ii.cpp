// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        ans.clear();
        map<int, int> counter;
        for (int i = 0; i < n; ++i) {
            ++counter[nums[i]];
        }
        vector<int> comb;
        backtrack(comb, n, counter, ans);
        return ans;
    }
    
    void backtrack(vector<int> comb, int& n, map<int, int>& counter, vector<vector<int>>& ans) {
        if (comb.size() == n) {
            ans.push_back(comb);
            return;
        }
        for (auto & [num, count]: counter) {
            if (count == 0) {
                continue;
            }
            comb.push_back(num);
            --counter[num];
            backtrack(comb, n, counter, ans);
            comb.pop_back();
            ++counter[num];
        }
    }
};
