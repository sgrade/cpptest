// 2948. Make Lexicographically Smallest Array by Swapping Elements
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sorting + Grouping
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        int group = 0;
        unordered_map<int, int> num_to_group;
        num_to_group[sorted[0]] = group;

        unordered_map<int, list<int>> groups;
        groups[group] = list<int>(1, sorted[0]);

        for (int i = 1; i < sorted.size(); ++i) {
            if (abs(sorted[i] - sorted[i - 1]) > limit)
                ++group;
            num_to_group[sorted[i]] = group;
            groups[group].emplace_back(sorted[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i], group = num_to_group[num];
            nums[i] = *groups[group].begin();
            groups[group].pop_front();
        }
        return nums;
    }
};
