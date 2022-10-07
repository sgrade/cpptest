// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 5: Binary Search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size();
        int duplicate, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (CountLessOrEqual(mid, nums) > mid) {
                duplicate = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return duplicate;
    }

private:
    int CountLessOrEqual (int current, vector<int> &nums) {
        int cnt = 0;
        for (const int &num: nums) {
            if (num <= current) {
                ++cnt;
            }
        }
        return cnt;
    }
};
