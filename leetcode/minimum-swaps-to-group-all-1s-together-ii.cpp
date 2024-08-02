// 2134. Minimum Swaps to Group All 1's Together II
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Using Sliding Window
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        int ans1 = GetSwaps (nums, 0);
        int ans2 = GetSwaps (nums, 1);
        return min (ans1, ans2);
    }
private:
    int n;
    int GetSwaps (vector<int>& nums, int x) {
        int x_count = 0;
        for (int i = n - 1; i >= 0; --i)
            if (nums[i] == x) ++x_count;
        if (x_count == 0 || x_count == n)
            return 0;
        int left = 0, right = 0;
        int max_len = 0, cur_len = 0;
        while (right < x_count) {
            if (nums[right++] == x)
                ++cur_len;
        }
        max_len = cur_len;
        while (right < n) {
            if (nums[left++] == x)
                --cur_len;
            if (nums[right++] == x)
                ++cur_len;
            max_len = max (max_len, cur_len);
        }
        return x_count - max_len;
    }
};
