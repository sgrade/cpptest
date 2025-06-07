// Distribute Candies Among Children III
// https://leetcode.com/problems/distribute-candies-among-children-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Inclusion-Exclusion Principle
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // total number of cases
        long long c1 = calculate(n + 2);

        // At least one child receives more than limit
        long long c2 = 3 * calculate(n - limit + 1);


        // At least two children receive more than limit
        long long c3 = 3 * calculate(n - (limit + 1) * 2 + 2);

        // All three children receive more than limit
        long long c4 = calculate(n - 3 * (limit + 1) + 2);

        return c1 - c2 + c3 - c4;
    }
private:
    long long calculate(int x) {
        if (x < 0)
            return 0;
        return 1LL * x * (x - 1) / 2;
    }
};
