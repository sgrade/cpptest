// 594. Longest Harmonious Subsequence
// https://leetcode.com/problems/longest-harmonious-subsequence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        int ans = 0;
        for (auto& [num, cnt]: counter) {
            if (counter.find(num + 1) != counter.end())
                ans = max(ans, counter[num] + counter[num + 1]);
        }
        return ans;
    }
};
