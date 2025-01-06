// 1769. Minimum Number of Operations to Move All Balls to Each Box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sum of Left and Right Moves
class Solution {
public:
    vector<int> minOperations(string boxes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = boxes.size();
        vector<int> ans(n);
        int balls_left = 0, moves_left = 0, balls_right = 0, moves_right = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] += moves_left;
            balls_left += boxes[i] == '1';
            moves_left += balls_left;

            int j = n - 1 - i;
            ans[j] += moves_right;
            balls_right += boxes[j] == '1';
            moves_right += balls_right;
        }
        return ans;
    }
};
