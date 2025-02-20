// 3450. Maximum Students on a Single Bench
// https://leetcode.com/problems/maximum-students-on-a-single-bench/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for (const vector<int>& s: students)
            benches[s[1]].emplace(s[0]);
        int ans = 0;
        for (const auto& [_, st]: benches)
            ans = max(ans, (int)st.size());
        return ans;
    }

private:
    unordered_map<int, unordered_set<int>> benches;
};
