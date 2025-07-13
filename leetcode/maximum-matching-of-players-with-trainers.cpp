// 2410. Maximum Matching of Players With Trainers
// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sorting + Two Pointers + Greedy
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(players.begin(), players.end()),
        sort(trainers.begin(), trainers.end());
        
        int np = players.size(), nt = trainers.size(), ans = 0;
        for (int p = 0, t = 0; p < np && t < nt; ++p, ++t) {
            while (t < nt && players[p] > trainers[t])
                ++t;
            if (t < nt)
                ++ans;
        }
        return ans;
    }
};
