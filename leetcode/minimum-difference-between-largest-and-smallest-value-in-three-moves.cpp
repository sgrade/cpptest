// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minDifference(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        if (n < 5)
            return 0;
        sort(nums.begin(), nums.end());
              
        int ans = nums[n - 1] - nums[0];
        for (int remove_from_left = 0; remove_from_left < 4; ++remove_from_left) {
            int remove_from_right = 3 - remove_from_left;
            int current_ans = nums[n - 1 - remove_from_right] - nums[remove_from_left];
            ans = min(current_ans, ans);
        }
        return ans;
    }
};
