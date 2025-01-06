// 1769. Minimum Number of Operations to Move All Balls to Each Box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> minOperations(string boxes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = boxes.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1'){
                for (int j = 0; j < n; ++j) {
                    ans[j] += abs(i - j);
                }
            }
        }
        return ans;
    }
};
