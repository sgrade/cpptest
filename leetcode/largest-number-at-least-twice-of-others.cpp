// 747. Largest Number At Least Twice of Others
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>::iterator mx_it = max_element(nums.begin(), nums.end());
        int idx = distance(nums.begin(), mx_it);
        int half = (*mx_it) / 2;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > half) {
                if (i == idx)
                    continue;
                return -1;
            }
        }
        return idx;
    }
};
