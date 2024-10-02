// 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        set<pair<int, int>> st;
        for (int i = 0; i < arr.size(); ++i)
            st.emplace(arr[i], i);
        int rank = 0, prev = -1;
        for (const auto& [num, idx]: st) {
            if (num != prev)
                ++rank;
            arr[idx] = rank;
            prev = num;
        }
        return arr;
    }
};
