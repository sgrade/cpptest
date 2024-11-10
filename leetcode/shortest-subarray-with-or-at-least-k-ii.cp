// 3097. Shortest Subarray With OR at Least K II
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<bool> bits_in_k;
        int tmp = k;
        while (tmp){
            bits_in_k.emplace_back(tmp & 1);
            tmp >>= 1;
        }
        reverse(bits_in_k.begin(), bits_in_k.end());

        int left = 0, right = 0, ans = numeric_limits<int>::max();
        vector<int> bits(bits_in_k.size());
        while (right < n) {
            if (nums[right] >= k)
                return 1;
            
            int mask = 1, i = bits_in_k.size() - 1;
            while (mask <= nums[right]) {
                bits[i--] += (nums[right] & mask) > 0;
                mask <<= 1;
            }
            int have = bin_to_int (bits);
            if (have >= k)
                ans = min(ans, right - left + 1);
            
            while (left < right && have >= k) {
                mask = 1, i = bits_in_k.size() - 1;
                while (mask <= nums[left]) {
                    bits[i--] -= (nums[left] & mask) > 0;
                    mask <<= 1;
                }
                ++left;
                have = bin_to_int (bits);
                if (have >= k)
                    ans = min(ans, right - left + 1);
            }

            ++right;
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }

private:
    int bin_to_int (vector<int>& bits) {
        int x = 0, mask = 1;
        for (int i = bits.size() - 1; i >= 0; --i) {
            x += (bits[i] > 0) * mask;
            mask <<= 1;
        }
        return x;
    }
};
