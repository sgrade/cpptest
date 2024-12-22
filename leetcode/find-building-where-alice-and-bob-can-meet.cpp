// 2940. Find Building Where Alice and Bob Can Meet
// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Monotonic Stack
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        n = queries.size();
        ans.resize(n, -1);

        vector<vector<pair<int, int>>> q(heights.size());
        for (int i = 0; i < n; ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b)
                swap(a, b);
            if (heights[b] > heights[a] || a == b)
                ans[i] = b;
            else
                q[b].emplace_back(heights[a], i);
        }

        for (int i = heights.size() - 1; i >= 0; --i) {
            int st_size = st.size();
            for (auto& [a, b]: q[i]) {
                int pos = Get(a);
                if (pos < st_size && pos >= 0)
                    ans[b] = st[pos].second;
            }
            while (!st.empty() && st.back().first <= heights[i])
                st.pop_back();
            st.emplace_back(heights[i], i);
        }

        return ans;
    }
private:
    int n;
    vector<int> ans;
    vector<pair<int, int>> st;
    int Get(int height) {
        int left = 0;
        int right = st.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (st[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};
