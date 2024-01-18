// 2320. Count Number of Ways to Place Houses
// https://leetcode.com/problems/count-number-of-ways-to-place-houses/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    int countHousePlacements(int n) {
        long long one_side_count = (count(n, false) + count(n, true)) % MOD;
        return (one_side_count * one_side_count) % MOD;
    }

private:
    long long MOD = 1e9 + 7;
    long long count(int n, bool placed) {
        if (n == 1)
            return 1;
        // the adjacent cell should be empty
        if (placed)
            return count(n - 1, false);
        // the adjacent cell can be left empty or house can be placed there
        else
            return (count(n - 1, false) + count(n - 1, true)) % MOD;
    }
};
