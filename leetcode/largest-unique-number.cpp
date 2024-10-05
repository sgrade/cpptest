// Approach 1: Sorting
// https://leetcode.com/problems/largest-unique-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        int ans = -1;
        for (const auto& [num, cnt]: counter) {
            if (cnt == 1)
                ans = max(ans, num);
        }
        return ans;
    }
};
