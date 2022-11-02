// 77. Combinations
// https://leetcode.com/problems/combinations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(n, k, ans, comb, 1);
        return ans;
    }
private:
    void backtrack(const int &n, const int &k, vector<vector<int>> &ans, vector<int> &comb, int start) {
        if (comb.size() == k) {
            ans.emplace_back(comb);
            return;
        }
        for (int i = start; i <= n; ++i) {
            comb.emplace_back(i);
            backtrack(n, k, ans, comb, i + 1);
            comb.pop_back();
        }
    }
};
