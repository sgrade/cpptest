// 2815. Max Pair Sum in an Array
// https://leetcode.com/problems/max-pair-sum-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, vector<int>> max_digits;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i], mx = 0, rem;
            while (num) {
                rem = num % 10;
                mx = max(mx, rem);
                num /= 10;
            }
            max_digits[mx].emplace_back(nums[i]);
        }

        int ans = -1;
        for (auto& [mx, nms]: max_digits) {
            if (nms.size() == 1)
                continue;
            sort(nms.begin(), nms.end(), greater<int>());
            ans = max(ans, nms[0] + nms[1]);
        }

        return ans;
    }
};
