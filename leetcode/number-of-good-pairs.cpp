// 1512. Number of Good Pairs
// https://leetcode.com/problems/number-of-good-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        int ans = 0;
        for (auto& [_, cnt]: counter)
            ans += cnt * (cnt - 1) / 2;
        return ans;
    }
};
