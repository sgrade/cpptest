// 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>

using namespace std;


class NumArray {
public:
    vector<int> dp;
    
    NumArray(vector<int>& nums) {
        dp.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return dp[right + 1] - dp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {

    return 0;
}
