// 552. Student Attendance Record II
// https://leetcode.com/problems/student-attendance-record-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming with Memoization
class Solution {
public:
    int checkRecord(int n) {
        memo.resize(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return getCombinations(n, 0, 0);
    }

private:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    int getCombinations (int n, int total_absences, int conseq_lates) {
        if (total_absences > 1 || conseq_lates > 2)
            return 0;
        if (n == 0)
            return 1;
        if (memo[n][total_absences][conseq_lates] != -1)
            return memo[n][total_absences][conseq_lates];

        int ans = 0;
        ans = getCombinations (n - 1, total_absences, 0);
        ans = (ans + getCombinations(n - 1, total_absences + 1, 0)) % MOD;
        ans = (ans + getCombinations(n - 1, total_absences, conseq_lates + 1)) % MOD;

        return memo[n][total_absences][conseq_lates] = ans;
    }
};
