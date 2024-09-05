// 2028. Find Missing Observations
// https://leetcode.com/problems/find-missing-observations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int m = rolls.size();
        int sum_of_m = accumulate(rolls.begin(), rolls.end(), 0);
        int sum_of_n = (n + m) * mean - sum_of_m;
        double need = 1.0 * sum_of_n / n;
        if (need < 1.0 || need > 6.0)
            return {};

        vector<int> ans(n, 1);
        sum_of_n -= n;
        int i = 0;
        while (sum_of_n > 0) {
            int current = min(5, sum_of_n);
            ans[i++] += current;
            sum_of_n -= current;
        }
        return ans;
    }
};
