// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size() - 1;
        int ans = 0, mx = 0, current_mx = 0;
        for (int i = 0; i < target; ++i) {
            current_mx = max(current_mx, i + nums[i]);
            if (i == mx) {
                ++ans;
                mx = current_mx;
            }
        }
        return ans;
    }
};
