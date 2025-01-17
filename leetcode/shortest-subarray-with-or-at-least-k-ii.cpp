// 3097. Shortest Subarray With OR at Least K II
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = nums.size();
        int left = 0, right = 0, ans = numeric_limits<int>::max();
        vector<int> binary(32);
        while (right < n) {
            if (nums[right] >= k)
                return 1;
            
            int mask = 1, i = 32 - 1;
            while (mask <= nums[right]) {
                binary[i--] += (nums[right] & mask) > 0;
                mask <<= 1;
            }
            int have = bin_to_int (binary);
            if (have >= k)
                ans = min(ans, right - left + 1);
            
            while (left < right && have >= k) {
                mask = 1, i = 32 - 1;
                while (mask <= nums[left]) {
                    binary[i--] -= (nums[left] & mask) > 0;
                    mask <<= 1;
                }
                ++left;
                have = bin_to_int (binary);
                if (have >= k)
                    ans = min(ans, right - left + 1);
            }

            ++right;
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }

private:
    int n;
    int bin_to_int (vector<int>& binary) {
        int x = 0, mask = 1;
        for (int i = 32 - 1; i >= 0; --i) {
            x += (binary[i] > 0) * mask;
            mask <<= 1;
        }
        return x;
    }
};
