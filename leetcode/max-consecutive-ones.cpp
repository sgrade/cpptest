// 485. Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, current_ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++current_ans;
            }
            else {
                ans = max(ans, current_ans);
                current_ans = 0;  
            }
        }
        ans = max(ans, current_ans);
        return ans;
    }
};
