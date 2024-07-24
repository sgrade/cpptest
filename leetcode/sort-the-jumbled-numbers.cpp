// 2191. Sort the Jumbled Numbers
// https://leetcode.com/problems/sort-the-jumbled-numbers/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = nums.size();
        sorted.resize(n);
        for (int i = 0; i < n; ++i) {
            int mapped_num = mapNum(nums[i], mapping);
            sorted[i] = {mapped_num, i};
        }
        sort(sorted.begin(), sorted.end());
        ans.resize(n);
        int new_i = 0;
        for (const auto& [_, original_i]: sorted)
            ans[new_i++] = nums[original_i];
        return ans;
    }

private:
    int n;
    vector<int> ans;
    // <mapped_num, original_idx>
    vector<pair<int, int>> sorted;
    int mapNum (int num, vector<int>& mapping) {
        stack<int> digits;
        if (num < 10)
            return mapping[num];
        while (num) {
            digits.emplace(num % 10);
            num /= 10;
        }
        int mapped = 0;
        while (!digits.empty()) {
            mapped *= 10;
            mapped += mapping[digits.top()];
            digits.pop();
        }
        return mapped;
    }
};
