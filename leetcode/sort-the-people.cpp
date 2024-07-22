// 2418. Sort the People
// https://leetcode.com/problems/sort-the-people/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = names.size();
        // <height, idx>
        vector<pair<int, int>> ranked(n);
        for (int i = 0; i < n; ++i)
            ranked[i] = {heights[i], i};
        sort(ranked.begin(), ranked.end(), greater<pair<int, int>>());
        vector<string> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = names[ranked[i].second];
        return ans;
    }
};
