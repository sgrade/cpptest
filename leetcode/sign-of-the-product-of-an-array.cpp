// 1822. Sign of the Product of an Array
// https://leetcode.com/problems/sign-of-the-product-of-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negatives = 0;
        for (const int& num : nums) {
            if (num == 0)
                return 0;
            else if (num < 0)
                ++negatives;
        }
        return negatives % 2 == 0 ? 1 : -1;
    }
};
