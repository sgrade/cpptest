// 808. Soup Servings
// https://leetcode.com/problems/soup-servings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Top-Down Dynamic Programming (Memoization)
class Solution {
public:
    double soupServings(int n) {
        int total_servings = ceil(n / 25.0);
        for (int cur_servings = 1; cur_servings <= total_servings; ++cur_servings) {
            if (dp(cur_servings, cur_servings) > 1 - 1e-5) {
                return 1;
            }
        }
        return dp(total_servings, total_servings);
    }
private:
    unordered_map<int, unordered_map<int, double>> memo;
    double dp(int a_servings, int b_servings) {
        // no soup A and no soup B
        if (a_servings <= 0 && b_servings <= 0) {
            return 0.5;
        }
        if (a_servings <= 0) {
            return 1;
        }
        if (b_servings <= 0) {
            return 0;
        }
        if (memo[a_servings].count(b_servings)) {
            return memo[a_servings][b_servings];
        }
        return memo[a_servings][b_servings] = ( 
                dp(a_servings - 4, b_servings) + 
                dp(a_servings - 3, b_servings - 1) +
                dp(a_servings - 2, b_servings - 2) + 
                dp(a_servings - 1, b_servings - 3)) 
                / 4;
    }
};
