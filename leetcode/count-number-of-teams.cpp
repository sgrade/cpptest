// 1395. Count Number of Teams
// https://leetcode.com/problems/count-number-of-teams/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming (Memoization)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        n = rating.size();
        int ans = 0;
        vector<vector<int>> increasing (n, vector<int>(4, -1)), decreasing (n, vector<int>(4, -1));
        for (int start = 0; start < n; ++start)
            ans += (CountIncreasing (rating, start, 1, increasing)) + CountDecreasing (rating, start, 1, decreasing);
        return ans;
    }

private:
    int n;
    int CountIncreasing (const vector<int>& rating, int current, int team_size, vector<vector<int>>& increasing) {
        if (current == n)
            return 0;
        if (team_size == 3)
            return 1;
        if (increasing[current][team_size] != -1)
            return increasing[current][team_size];
        int teams = 0;
        for (int next = current + 1; next < n; ++next) {
            if (rating[next] > rating[current])
                teams += CountIncreasing (rating, next, team_size + 1, increasing);
        }
        return increasing[current][team_size] = teams;
    }
    int CountDecreasing (const vector<int>& rating, int current, int team_size, vector<vector<int>>& decreasing) {
        if (current == n)
            return 0;
        if (team_size == 3)
            return 1;
        if (decreasing[current][team_size] != -1)
            return decreasing[current][team_size];
        int teams = 0;
        for (int next = current + 1; next < n; ++next) {
            if (rating[next] < rating[current])
                teams += CountDecreasing (rating, next, team_size + 1, decreasing);
        }
        return decreasing[current][team_size] = teams;
    }
};
