// 334. Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = numeric_limits<int>::max();
        int second = numeric_limits<int>::max();
        for (const int &x: nums) {
            if (x <= first) {
                first = x;
            }
            else if (x <= second) {
                second = x;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
