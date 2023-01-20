// 491. Non-decreasing Subsequences
// https://leetcode.com/problems/non-decreasing-subsequences/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcodes's Approach 1: Backtracking
// VERY SLOW
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        backtrack(nums, st, vector<int>(), 0);
        return vector(st.begin(), st.end());
    }
private:
    void backtrack(const vector<int>& nums, set<vector<int>>& st, vector<int> current_seq, int idx) {
        if (idx == nums.size()) {
            if (current_seq.size() >= 2) {
                st.emplace(current_seq);
            }
            return;
        }
        if (current_seq.empty() || current_seq.back() <= nums[idx]) {
            current_seq.emplace_back(nums[idx]);
            backtrack(nums, st, current_seq, idx + 1);
            current_seq.pop_back();
        }
        backtrack(nums, st, current_seq, idx + 1);
    }
};
