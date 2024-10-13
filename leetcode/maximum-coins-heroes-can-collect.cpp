// 2838. Maximum Coins Heroes Can Collect
// https://leetcode.com/problems/maximum-coins-heroes-can-collect/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int m = monsters.size();
        vector<pair<int, long long>> sorted(m);
        for (int i = 0; i < m; ++i)
            sorted[i] = pair<int, long long>(monsters[i], coins[i]);
        sort(sorted.begin(), sorted.end());

        for (int i = 1; i < m; ++i)
            sorted[i].second += sorted[i - 1].second;

        vector<long long> ans;
        for (const int& hero_power: heroes) {
            auto it = upper_bound(sorted.begin(), sorted.end(), hero_power, [](int value, const pair<int, long long>& p){
                return value < p.first;
            });
            long long current_ans = 0;
            if (it != sorted.begin())
                current_ans = prev(it)->second;
            ans.emplace_back(current_ans);
        }
        return ans;
    }
};
