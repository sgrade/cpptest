// 3024. Type of Triangle
// https://leetcode.com/problems/type-of-triangle/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2])
            return "none";

        unordered_set<int> st(nums.begin(), nums.end());
        if (st.size() == 1)
            return "equilateral";
        else if (st.size() == 2)
            return "isosceles";
        else
            return "scalene";
    }
};
