// 2285. Maximum Total Importance of Roads
// https://leetcode.com/problems/maximum-total-importance-of-roads/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> counter(n);
        for (const vector<int>& road: roads) {
            ++counter[road[0]];
            ++counter[road[1]];
        }
        
        vector<pair<int, int>> sorted_counter(n);
        for (int i = 0; i < n; ++i)
            sorted_counter[i] = pair<int, int>(counter[i], i);
        sort(sorted_counter.begin(), sorted_counter.end());
        
        int i = 1;
        for (const auto& [cnt, city]: sorted_counter) {
            counter[city] = i++;
        }
        
        long long ans = 0;
        for (const vector<int>& road: roads) {
            ans += counter[road[0]];
            ans += counter[road[1]];
        }
        return ans;
    }
};
