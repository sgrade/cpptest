// 2894. Divisible and Non-divisible Sums Difference
// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total_sum = n * (1 + n) / 2;

        int m_cnt = n / m, largest_divisible_by_m = m_cnt * m;
        int sum_of_divisible = m_cnt * (m + largest_divisible_by_m) / 2;

        int ans = total_sum - sum_of_divisible * 2;
        return ans;
    }
};
