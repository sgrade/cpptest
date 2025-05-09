// 3343. Count Number of Balanced Permutations
// https://leetcode.com/problems/count-number-of-balanced-permutations/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Memoization Search

class Solution {
    public:
        int countBalancedPermutations(string num) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int total = 0, n = num.size();
            counter.resize(10);
            for (const char& ch: num) {
                int digit = ch - '0';
                ++counter[digit];
                total += digit;
            }
            if (total % 2 != 0)
                return 0;

            target = total / 2, max_odd = (n + 1) / 2;
            psum.resize(11);
            combinations.resize(max_odd + 1, vector<long>(max_odd + 1));
            memo.resize(10, vector<vector<long>>(target + 1, vector<long>(max_odd + 1, -1)));
            // memset(memo, 0xff, sizeof(memo));
            for (int i = 0; i <= max_odd; ++i) {
                combinations[i][i] = combinations[i][0] = 1;
                for (int j = 1; j < i; ++j)
                    combinations[i][j] = (combinations[i - 1][j] + combinations[i - 1][j - 1]) % MOD;
            }
            for (int i = 9; i >= 0; --i)
                psum[i] = psum[i + 1] + counter[i];

            return dfs(0, 0, max_odd);
        }

    private:
        long MOD = 1e9 + 7;
        int target, max_odd;
        vector<int> counter, psum;
        vector<vector<long>> combinations;
        vector<vector<vector<long>>> memo;
        long dfs (int pos, int cur, int odd_cnt) {
            if (odd_cnt < 0 || psum[pos] < odd_cnt || cur > target)
                return 0;
            if (pos > 9)
                return cur == target && odd_cnt == 0;
            if (memo[pos][cur][odd_cnt] != -1)
                return memo[pos][cur][odd_cnt];

            int event_cnt = psum[pos] - odd_cnt;
            long ans = 0;
            for (int i = max(0, counter[pos] - event_cnt); i <= min(counter[pos], odd_cnt); ++i) {
                long ways = combinations[odd_cnt][i] * combinations[event_cnt][counter[pos] - i] % MOD;
                ans = (ans + ways * dfs(pos + 1, cur + i * pos, odd_cnt - i) % MOD) % MOD;
            }
            memo[pos][cur][odd_cnt] = ans;
            return ans;
        }
    };
