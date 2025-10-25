// 1716. Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/


class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7, first_week = 28, diff_each_week = 7;
        // Ariphmetic sum
        int full_weeks = weeks * (2 * first_week + (weeks - 1) * diff_each_week) / 2;

        int last_monday = 1 + weeks, last_week = 0;
        for (int day = 0; day < n % 7; ++day) {
            last_week += last_monday + day;
        }

        return full_weeks + last_week;
    }
};
