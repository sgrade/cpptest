// 1230. Toss Strange Coins
// https://leetcode.com/problems/toss-strange-coins/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursive Dynamic Programming
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = prob.size();
        memo.resize(n, vector<double>(target + 1, -1));
        return GetProbability (0, prob, target);
    }

private:
    int n;
    vector<vector<double>> memo;
    double GetProbability (int i, vector<double>& prob, int target) {
        // impossible to get negative target
        if (target < 0)
            return 0;

        // no more coins?
        if (i == n)
            return target == 0 ? 1 : 0;

        if (memo[i][target] != -1)
            return memo[i][target];
        memo[i][target] =
            GetProbability (i + 1, prob, target - 1) * prob[i] +
            GetProbability (i + 1, prob, target) * (1 - prob[i]);
        return memo[i][target];
    }
};
