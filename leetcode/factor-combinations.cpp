// 254. Factor Combinations
// https://leetcode.com/problems/factor-combinations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        backtrack(n, {});
        return ans;
    }
private:
    vector<vector<int>> ans;

    void backtrack(int n, vector<int> current_ans) {
        // This check is to exclude duplicates
        int i = current_ans.empty() ? 2 : current_ans.back();
        for (; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                current_ans.emplace_back(i);
                backtrack(n / i, current_ans);
                current_ans.pop_back();
            }
        }
        if (!current_ans.empty()) {
            current_ans.emplace_back(n);
            ans.emplace_back(current_ans);
        }
    }
};
