// 912. Sort an Array
// https://leetcode.com/problems/sort-an-array/

#include <bits/stdc++.h>

using namespace std;


// Counting Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        const auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        int min = *mn, max = *mx;
        int idx = 0;
        for (int num = min; num <= max; ++num) {
            if (counter.find(num) != counter.end()) {
                int cnt = counter[num];
                fill(nums.begin() + idx, nums.begin() + idx + cnt, num);
                idx += cnt;
            }
        }
        return nums;
    }
};
