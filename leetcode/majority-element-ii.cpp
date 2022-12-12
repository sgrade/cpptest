// 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>

using namespace std;


// Solution is based on Leetcode's Approach 1: Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), n_by_3 = n / 3;

        // 1st pass
        int count1 = 0, count2 = 0;
        int candidate1 =  1e9 + 1, candidate2 =  1e9 + 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == candidate1) ++count1;
            else if (nums[i] == candidate2) ++count2;
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                --count1;
                --count2;
            }
        }

        // 2nd pass - because candidate1 and 2 are not guaranteed to exist 
        //  (they haven't received the n/3 majority, just that the algorithm selected them)
        //  Source - https://leetcode.com/problems/majority-element-ii/solutions/797025/majority-element-ii/comments/706411

        vector<int> ans;
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == candidate1) ++count1;
            if (nums[i] == candidate2) ++count2;
        }
        if (count1 > n_by_3) ans.emplace_back(candidate1);
        if (count2 > n_by_3) ans.emplace_back(candidate2);
        return ans;
    }
};
