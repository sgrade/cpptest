// 2870. Minimum Number of Operations to Make Array Empty
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        int ans = 0;
        for (const auto& [num, cnt]: counter) {
            if (cnt == 1)
                return -1;
            int rem = cnt % 3;
            if (rem == 0)
                ans += cnt / 3;
            else if (rem == 1) {
                ans += (cnt - 4) / 3;
                ans += 2;
            }
            else
                ans += (cnt - 1) / 3 + 1;
        }
        return ans;
    }
};
