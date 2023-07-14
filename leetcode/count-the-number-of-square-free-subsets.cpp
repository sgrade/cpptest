// 2572. Count the Number of Square-Free Subsets
// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

#include <bits/stdc++.h>

using namespace std;


// Follows this solution - https://leetcode.com/problems/count-the-number-of-square-free-subsets/solutions/3203755/o-n-1024-memoization-bitmask/
// Another solution with video explanation is very similar and gives many hints how to solve such problems - https://leetcode.com/problems/count-the-number-of-square-free-subsets/solutions/3204715/video-explanation-building-solution-from-scratch-with-intuitions/
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        n = nums.size();
        return 1LL * (dp(0, 0, nums) - 1 + mod) % mod;
    }

private:
    int n;
    long long mod = 1e9 + 7;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<vector<int>> memo = vector<vector<int>> (1024, vector<int>(1024, -1));
    long long dp(int i, int mask, vector<int>& nums) {
        if (i == n)
            return 1;
        if (memo[i][mask] != -1)
            return memo[i][mask];
        int tmp = mask, flag = 1;
        for (int j = 0; j < 10; ++j) {
            int num = nums[i], cnt = 0;
            while (num % primes[j] == 0) {
                num /= primes[j];
                ++cnt;
            }
            if (cnt >= 2 || ((cnt == 1) && ((mask >> j) & 1))) {
                flag = 0;
                break;
            }
            if (cnt)
                tmp |= (1 << j);
        }
        if (flag) 
            return memo[i][mask] = (dp(i + 1, mask, nums) + dp(i + 1, tmp, nums)) % mod;
        else
            return memo[i][mask] = dp(i + 1, mask, nums);
    }
};
