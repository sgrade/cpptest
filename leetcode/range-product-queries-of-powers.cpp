// 2438. Range Product Queries of Powers
// https://leetcode.com/problems/range-product-queries-of-powers/

#include <cstdint>
#include <vector>


// Based on Editorial's Approach 1: Binary Decomposition + Direct Calculation
class Solution {
 public:
    std::vector<int> productQueries(int n, const std::vector<std::vector<int>>& queries) const {
        constexpr int kMod = 1e9 + 7;
        std::vector<int> powers_of_two;
        int x = 1;
        int temp_n = n;
        while (temp_n) {
            if (temp_n % 2 == 1) {
                powers_of_two.push_back(x);
            }
            temp_n /= 2;
            x *= 2;
        }

        const int m = static_cast<int>(powers_of_two.size());
        std::vector<int64_t> prefix_prod(m + 1, 1);
        for (int i = 0; i < m; ++i) {
            prefix_prod[i + 1] = prefix_prod[i] * powers_of_two[i] % kMod;
        }

        std::vector<int> ans;
        for (const auto& q : queries) {
            const int l = q[0];
            const int r = q[1];
            // To get the product of powers_of_two[l..r], divide prefix_prod[r+1] by prefix_prod[l] under modulo.
            // Since division is not directly supported, we use modular inverse.
            const int64_t res = prefix_prod[r + 1] * ModInv(prefix_prod[l], kMod) % kMod;
            ans.push_back(static_cast<int>(res));
        }
        return ans;
    }

 private:
    // Modular inverse using Fermat's little theorem
    int64_t ModInv(int64_t a, int mod) const {
        return ModPow(a, mod - 2, mod);
    }

    int64_t ModPow(int64_t a, int64_t b, int mod) const {
        int64_t res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};
