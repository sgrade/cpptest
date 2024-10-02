// 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        map<int, int> counter;
        unordered_map<int, vector<int>> indexes;
        for (int i = 0; i < arr.size(); ++i) {
            ++counter[arr[i]];
            indexes[arr[i]].emplace_back(i);
        }
        int rank = 1;
        for (const auto& [num, cnt]: counter) {
            for (const int& i: indexes[num])
                arr[i] = rank;
            ++rank;
        }
        return arr;
    }
};
