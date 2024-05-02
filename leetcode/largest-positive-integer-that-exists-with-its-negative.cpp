// 2441. Largest Positive Integer That Exists With Its Negative
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> seen;
        for (const int& num: nums) {
            if (seen.find(-num) != seen.end())
                ans = max(ans, abs(num));
            seen.emplace(num);
        }
        return ans;
    }
};
