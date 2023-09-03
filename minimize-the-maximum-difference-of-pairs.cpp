// 2616. Minimize the Maximum Difference of Pairs
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/


#include <bits/stdc++.h>


using namespace std;


// Based on Editorial's Approach: Greedy + Binary Search
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n - 1] - nums[0], mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (CountValidPairs(nums, mid) < p)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

private:
    int n;
    int CountValidPairs(vector<int>& nums, int threshold) {
        int i = 0, cnt = 0;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= threshold) {
                ++cnt;
                ++i;
            }
            ++i;
        }
        return cnt;
    }
};
