// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = temperatures.size();
        vector<int> seen(102, -1);

        for (int i = n - 1; i >= 0; --i) {
            int target = temperatures[i];
            seen[target] = i;

            int min_idx = 1e5 + 2;
            for (int j = target + 1; j < 101; ++j) {
                if (seen[j] != -1)
                    min_idx = min(min_idx, seen[j]);
            }

            temperatures[i] = min_idx == 1e5 + 2 ? 0 : min_idx - i;
        }

        return temperatures;
    }
};
