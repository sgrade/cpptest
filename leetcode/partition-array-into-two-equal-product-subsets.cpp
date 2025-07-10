// 3566. Partition Array into Two Equal Product Subsets
// https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/solutions/6800242/two-approach-beats-100-bitmasking-recursion

using lll = __int128;

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        lll product = 1, target_squared = (lll)target * target;
        for (const int& num: nums) {
            product *= num;
            if (product > target_squared)
                return false;
        }

        if (product != target_squared)
            return false;
        
        int subsets = 1 << n;
        // Iterate though all subsets except the full set (containing all elements)
        for (int mask = 1; mask < subsets - 1; ++mask) {
            lll current_product = 1;
            // Iterate through the array elements
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    current_product *= nums[i];
                    if (current_product > target)
                        break;
                }
            }
            if (current_product == target)
                return true;
        }
        return false;
    }
};
