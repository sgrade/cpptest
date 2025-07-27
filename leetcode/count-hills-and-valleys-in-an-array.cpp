// 2210. Count Hills and Valleys in an Array
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for (int i = 1; i < n - 1; ++i) {
            // hill
            if (nums[i - 1] < nums[i]){
                if (nums[i] < nums[i + 1])
                    continue;
                if (nums[i] > nums[i + 1])
                    ++ans;
                else {
                    while (i < n - 1 && nums[i] == nums[i + 1])
                        ++i;
                    if (i < n - 1 && nums[i] > nums[i + 1])
                        ++ans;
                }
            }

            // valley
            if (nums[i - 1] > nums[i]) {
                if (nums[i] > nums[i + 1])
                    continue;
                if (nums[i] < nums[i + 1])
                    ++ans;
                else {
                    while (i < n - 1 && nums[i] == nums[i + 1])
                        ++i;
                    if (i < n - 1 && nums[i] < nums[i + 1])
                        ++ans;
                }

            }
        }

        return ans;
    }
};
