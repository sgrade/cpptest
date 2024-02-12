// 169. Majority Element
// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 7: Boyer-Moore Voting Algorithm
// Optimization is based on https://leetcode.com/problems/majority-element/submissions/857759012/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int count = 0, candidate = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
            else if (nums[i] == candidate)
                ++count;
            else
                --count;
        }
        return candidate;
    }
};
