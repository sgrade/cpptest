// 1072. Flip Columns For Maximum Number of Equal Rows
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Hash Map
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<string, int> freq;
        for (const auto& row: matrix) {
            string pattern = "";
            int first = row[0];
            for (const int& current: row)
                pattern += current == first ? 'T' : 'F';
            ++freq[pattern];
        }

        int max_freq = 0;
        for (const auto& [_, cnt]: freq)
            max_freq = max(max_freq, cnt);
        return max_freq;
    }
};
