// 1282. Group the People Given the Group Size They Belong To
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, pair<int, vector<int>>> groups;
        for (int i = 0; i < n; ++i) {
            int group_size = groupSizes[i];
            ++groups[group_size].first;
            groups[group_size].second.emplace_back(i);
            // Is the groups full?
            if (group_size == groups[group_size].first) {
                groups[group_size].first = 0;
                ans.emplace_back(groups[group_size].second);
                groups[group_size].second.clear();
            }
        }
        return ans;
    }
};
