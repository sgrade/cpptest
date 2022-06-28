// 55. Jump Game
// https://leetcode.com/problems/jump-game/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            mx = max(mx, (i - 1) + nums[i - 1]);
            if (mx < i) {
                return false;
            }
        }
        return true;
    }
};
