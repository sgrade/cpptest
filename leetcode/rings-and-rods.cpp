// 2103. Rings and Rods
// https://leetcode.com/problems/rings-and-rods/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> counter(10, vector<int>(3));
        unordered_map<char, int> colors = {{'R', 0}, {'G', 1}, {'B', 2}};
        for (int i = 0; i < rings.size(); i += 2) {
            ++counter[rings[i + 1] - '0'][colors[rings[i]]];
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            bool all_colors = true;
            for (int j = 0; j < 3; ++j) {
                if (counter[i][j] == 0) {
                    all_colors = false;
                    break;
                }
            }
            if (all_colors)
                ++ans;
        }
        return ans;
    }
};
