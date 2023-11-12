// 2562. Find the Array Concatenation Value
// https://leetcode.com/problems/find-the-array-concatenation-value/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long ans = 0;
        int left = 0, right = nums.size() - 1;
        int tmp, cnt;
        while (left < right) {
            cnt = 0, tmp = nums[right];
            while (tmp) {
                ++cnt;
                tmp /= 10;
            }
            ans += nums[left] * pow(10, cnt) + nums[right];
            ++left;
            --right;
        }
        if (left == right)
            ans += nums[left];
        return ans;
    }
};
