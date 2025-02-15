// 2698. Find the Punishment Number of an Integer
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

#include <bits/stdc++.h

using namespace std;


// Based on Editorial's Approach 1: Memoization
class Solution {
public:
    int punishmentNumber(int n) {
        ios::sync_with_stdio;
        cin.tie(nullptr);
        
        this->n = n;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int sq = i * i;
            string s = to_string(sq);
            vector<vector<int>> memo(s.size(), vector<int>(i + 1, -1));
            if (getPartitions(0, 0, s, i, memo))
                ans += sq;
        }
        return ans;
    }

private:
    int n;
    bool getPartitions(int start_idx, int sum, string s, int target, vector<vector<int>>& memo) {
        if (start_idx == s.size())
            return sum == target;
        if (sum > target)
            return false;
        if (memo[start_idx][sum] != -1)
            return memo[start_idx][sum];
        
        bool found = false;
        for (int current_idx = start_idx; current_idx < s.size(); ++current_idx) {
            string current_s = s.substr(start_idx, current_idx - start_idx + 1);
            int current_sum = stoi(current_s);
            found = found || getPartitions(current_idx + 1, sum + current_sum, s, target, memo);
            if (found)
                return true;
        }

        return memo[start_idx][sum] = found;
    }
};
