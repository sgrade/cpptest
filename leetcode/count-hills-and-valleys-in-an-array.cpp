// 2210. Count Hills and Valleys in an Array
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int prev = nums[0]; // Track the last different value

        for (int i = 1; i < n - 1; ++i) {
            int next = nums[i + 1];

            // Skip if current equals next (find the actual next different value)
            int j = i + 1;
            while (j < n && nums[j] == nums[i])
                ++j;
            if (j == n) break; // No more different values
            next = nums[j];

            // Check if current position forms a hill or valley
            if ((prev < nums[i] && nums[i] > next) ||
                (prev > nums[i] && nums[i] < next))
                    ++ans;

            // Update prev only when we move to a different value
            if (nums[i] != prev)
                prev = nums[i];

            // Skip duplicate values
            i = j - 1; // -1 because loop will increment
        }

        return ans;
    }
};
