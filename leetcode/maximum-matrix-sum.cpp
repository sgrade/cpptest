// 1975. Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Journey From Minus to Plus
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long sum = 0;
        int mn = INT_MAX, negatives = 0;
        for (const auto& row: matrix) {
            for (const int& val: row) {
                sum += abs(val);
                if (val < 0)
                    ++negatives;
                mn = min(mn, abs(val));
            }
        }
        if (negatives % 2 != 0)
            sum -= 2 * mn;
        return sum;
    }
};
