// 1900. The Earliest and Latest Rounds Where Players Compete
// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Analyze Fundamentally Different Standing Situations + Memoized Search
class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        F.resize(30, vector<vector<int>>(30, vector<int>(30))), G.resize(30, vector<vector<int>>(30, vector<int>(30)));
        if (firstPlayer > secondPlayer)
            swap(firstPlayer, secondPlayer);
        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }

private:
    vector<vector<vector<int>>> F, G;   // Memo

    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s] != 0)
            return {F[n][f][s], G[n][f][s]};
        if (f + s == n + 1)
            return {1, 1};
        
        if (f + s > n + 1) {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 -s, n + 1 - f);
            return {F[n][f][s], G[n][f][s]};
        }

        int earliest = numeric_limits<int>::max(), latest = numeric_limits<int>::min();
        int half = (n + 1) / 2;

        if (s <= half) {
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    auto [cur_earliest, cur_latest] = dp(half, i + 1, i + j + 2);
                    earliest = min(earliest, cur_earliest);
                    latest = max(latest, cur_latest);
                }
            }
        }

        else {
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    auto [cur_earliest, cur_latest] = dp(half, i + 1, i + j + mid + 2);
                    earliest = min(earliest, cur_earliest);
                    latest = max(latest, cur_latest);
                }
            }
        }

        return {F[n][f][s] = earliest + 1, G[n][f][s] = latest + 1};
    }
};
