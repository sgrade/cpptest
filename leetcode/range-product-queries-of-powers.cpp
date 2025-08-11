// 2438. Range Product Queries of Powers
// https://leetcode.com/problems/range-product-queries-of-powers/

#include <vector>


// Based on Editorial's Approach 1: Binary Decomposition + Direct Calculation
class Solution {
public:
    std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        std::vector<int> powers_of_two;
        int x = 1;
        while (n) {
            if (n % 2 == 1) {
                powers_of_two.emplace_back(x);
            }
            n /= 2;
            x *= 2;
        }

        std::vector<int> ans;
        for (const std::vector<int>& q: queries) {
            int y = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                y = 1LL * y * powers_of_two[i] % MOD;
            }
            ans.emplace_back(y);
        }
        return ans;
    }
};
