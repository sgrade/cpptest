// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>

using namespace std;


// WRONG ANSWER
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int zeroes = 0, ones = 0, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 1)
                ++ones;
            else
                ++zeroes;
            if (zeroes == ones)
                ans = max(ans, right - left + 1);
            else {
                if (right % 2 != 0) {
                    if (nums[left] == 1)
                        --ones;
                    else
                        --zeroes;
                    ++left;
                }
            }
        }
        return ans;
    }
};
