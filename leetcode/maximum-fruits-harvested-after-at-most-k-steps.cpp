// 2106. Maximum Fruits Harvested After at Most K Steps
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sliding Window
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0, right = 0, n = fruits.size(), current_ans = 0, ans = 0;
        while (right < n) {
            current_ans += fruits[right][1];
            while (left <= right && calculateSteps(left, right, fruits, startPos) > k)
                current_ans -= fruits[left++][1];
            ans = max(ans, current_ans);
            ++right;
        }
        return ans;
    }

private:
    int calculateSteps(int left, int right, const vector<vector<int>>& fruits, int startPos) {
        if (fruits[right][0] <= startPos)
            return startPos - fruits[left][0];
        else if (fruits[left][0] >= startPos)
            return fruits[right][0] - startPos;
        else
            return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) 
                    + fruits[right][0] - fruits[left][0];
    }
};
