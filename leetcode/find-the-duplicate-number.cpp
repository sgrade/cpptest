// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 7: Floyd's Tortoise and Hare (Cycle Detection)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int tortoise = nums[0], hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        tortoise = nums[0];
        while (tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};
