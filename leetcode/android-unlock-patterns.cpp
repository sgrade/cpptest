// 351. Android Unlock Patterns
// https://leetcode.com/problems/android-unlock-patterns/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Memoization
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        jump.resize(10, vector<int>(10));
        dp.resize(10, vector<int>(1 << 10, -1));
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

        // Start from corners: 1, 3, 7, 9
        ans += CountPatternsFromNumber (1, 1, m, n) * 4;
        // Start from edge 2, 4, 6, 8
        ans += CountPatternsFromNumber (2, 1, m, n) * 4;
        // Start from 5
        ans += CountPatternsFromNumber (5, 1, m, n);
        return ans;
    }
private:
    int ans = 0;
    int visited = 0;
    vector<vector<int>> jump;
    vector<vector<int>> dp;

    int CountPatternsFromNumber (int cur_num, int cur_len, int min_len, int max_len) {
        if (cur_len > max_len)
            return 0;
        if (dp[cur_num][visited] != -1)
            return dp[cur_num][visited];
        int valid_patterns = 0;
        if (cur_len >= min_len)
            ++valid_patterns;
        visited = SetBit (visited, cur_num);
        for (int next_num = 1; next_num <= 9; ++next_num) {
            int jump_over_num = jump[cur_num][next_num];
            if (!IsSet(visited, next_num) && 
                (jump_over_num == 0 || IsSet(visited, jump_over_num))) 
            {
                valid_patterns += CountPatternsFromNumber (next_num, cur_len + 1, min_len, max_len);
            }
        }
        visited = ClearBit (visited, cur_num);
        return dp[cur_num][visited] = valid_patterns;
    }

    int SetBit (int num, int pos) {
        num |= 1 << (pos - 1);
        return num;
    }

    int ClearBit (int num, int pos) {
        num ^= 1 << (pos - 1);
        return num;
    }

    bool IsSet (int num, int pos) {
        int bit_at_pos = (num >> (pos - 1)) & 1;
        return bit_at_pos == 1;
    }
};
