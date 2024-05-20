// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        GetSubsetXOR(nums, 0, 0);
        return ans;
    }

private:
    int n;
    int ans = 0;
    void GetSubsetXOR(const vector<int>& nums, int idx, int current_ans) {
        if (idx == n) {
            ans += current_ans;
            return;
        }

        current_ans ^= nums[idx];
        GetSubsetXOR(nums, idx + 1, current_ans);

        current_ans ^= nums[idx];
        GetSubsetXOR(nums, idx + 1, current_ans);
    }
};
