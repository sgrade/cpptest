// 3539. Find Sum of Array Product of Magical Sequences
// https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/

#include <vector>

using std::vector;


// Based on Editorial's Find Sum of Array Product of Magical Sequences
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        n = nums.size();

        // Precompute factorials and inverse factorials modulo k_mod.
        vector<long long> factorials(m + 1, 1);
        vector<long long> inverse_factorials(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            factorials[i] = factorials[i - 1] * i % k_mod;
        }
        for (int i = 2; i <= m; ++i) {
            inverse_factorials[i] = mod_pow(i, k_mod - 2);  // modular inverse of i
        }
        for (int i = 2; i <= m; ++i) {
            inverse_factorials[i] = inverse_factorials[i - 1] * inverse_factorials[i] % k_mod;
        }

        // nums_power_table[i][j] = nums[i]^j % k_mod
        vector<vector<long long>> nums_power_table(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                nums_power_table[i][j] = nums_power_table[i][j - 1] * nums[i] % k_mod;  // power table
            }
        }

        // dp_table[i][j][p][q] accumulates contributions for first (i+1) items,
        // with total chosen degree j, auxiliary state p, and parity-count q.
        vector<vector<vector<vector<long long>>>> dp_table(
            n,
            vector<vector<vector<long long>>>(
                m + 1,
                vector<vector<long long>>(m * 2 + 1, vector<long long>(k + 1, 0))));

        // Base case: only the first number contributes with degree j.
        for (int j = 0; j <= m; ++j) {
            dp_table[0][j][j][0] = nums_power_table[0][j] * inverse_factorials[j] % k_mod;
        }

        // Transition: incorporate each next number and update dp states.
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int p = 0; p <= m * 2; ++p) {
                    for (int q = 0; q <= k; ++q) {
                        int q2 = (p % 2) + q;
                        if (q2 > k) {
                            break;
                        }
                        for (int r = 0; r + j <= m; ++r) {
                            int p2 = p / 2 + r;
                            dp_table[i + 1][j + r][p2][q2] +=
                                dp_table[i][j][p][q] * nums_power_table[i + 1][r] % k_mod *
                                inverse_factorials[r] % k_mod;
                            dp_table[i + 1][j + r][p2][q2] %= k_mod;
                        }
                    }
                }
            }
        }

        // Aggregate final answer for total degree m and exactly k set bits + parities.
        long long result = 0;
        for (int p = 0; p <= m * 2; ++p) {
            for (int q = 0; q <= k; ++q) {
                if (__builtin_popcount(p) + q == k) {
                    result = (result + dp_table[n - 1][m][p][q] * factorials[m] % k_mod) % k_mod;
                }
            }
        }
        return static_cast<int>(result);
    }

private:
    int n;
    static constexpr long long k_mod = 1000000007LL;

    // Fast modular exponentiation: computes x^y % k_mod.
    long long mod_pow(long long x, long long y) {
        long long result = 1;
        long long cur = x % k_mod;
        while (y) {
            if (y & 1) {
                result = result * cur % k_mod;
            }
            y >>= 1;
            cur = cur * cur % k_mod;
        }
        return result;
    }
};
