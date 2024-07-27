// 2976. Minimum Cost to Convert String I
// https://leetcode.com/problems/minimum-cost-to-convert-string-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Floyd-Warshall Algorithm
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans = 0;

        vector<vector<long long>> min_cost(26, vector<long long>(26, INT_MAX));
        for (int i = 0; i < original.size(); ++i) {
            int start = original[i] - 'a', end = changed[i] - 'a';
            min_cost[start][end] = min(min_cost[start][end], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) 
                    min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
            }
        }

        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i])
                continue;
            int src = source[i] - 'a', trgt = target[i] - 'a';
            if (min_cost[src][trgt] >= INT_MAX)
                return -1;
            ans += min_cost[src][trgt];
        }
        return ans;
    }
};
