// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/range-sum-query-mutable/solutions/75753/Java-using-Binary-Indexed-Tree-with-clear-explanation/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        BIT.resize(n + 1);
        for (int i = 0; i < n; ++i)
            init(i, nums[i]);
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        init(index, diff);
    }

    int sumRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }

private:
    int n;
    vector<int> nums;
    vector<int> BIT;

    void init (int i, int val) {
        ++i;
        while (i <= n) {
            BIT[i] += val;
            i += (i & -i);
        }
    }

    int getSum (int i) {
        int sum = 0;
        ++i;
        while (i > 0) {
            sum += BIT[i];
            i -= (i & -i);
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
