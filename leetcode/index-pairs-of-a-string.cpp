// 1065. Index Pairs of a String
// https://leetcode.com/problems/index-pairs-of-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for (const string& w: words) {
            int idx = 0;
            while (true) {
                idx = text.find(w, idx);
                if (idx == string::npos) {
                    break;
                }
                ans.emplace_back(vector<int>{idx, idx + (int)w.size() - 1});
                ++idx;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
