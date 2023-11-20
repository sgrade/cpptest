// 2391. Minimum Amount of Time to Collect Garbage
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;

        map<char, int> last = {{'M', 0}, {'P', 0}, {'G', 0}};
        for (int i = 0; i < n; ++i) {
            // Travel
            for (const char& unit: garbage[i])
                last[unit] = i;
            // Collect the garbage
            ans += garbage[i].size();
        }

        // Total travel
        for (int i = 1; i < n - 1; ++i)
            travel[i] += travel[i - 1];
        for (const auto& [unit, last_house_idx]: last)
            ans += last[unit] == 0 ? 0 : travel[last_house_idx - 1];

        return ans;
    }
};
