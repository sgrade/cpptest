// 2971. Find Polygon With the Largest Perimeter
// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sorting
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        long long ans = -1, sum = 0;
        for (const int& num: nums) {
            if (num < sum)
                ans = num + sum;
            sum += num;
        }
        return ans;
    }
};
