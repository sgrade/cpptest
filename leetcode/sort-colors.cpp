// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counter(3);
        for (const int& num: nums)
            ++counter[num];
        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < counter[i]; ++j)
                nums[idx++] = i;
        }
    }
};
