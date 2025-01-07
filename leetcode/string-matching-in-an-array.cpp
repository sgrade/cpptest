// 1408. String Matching in an Array
// https://leetcode.com/problems/string-matching-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = words.size();
        unordered_set<string> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                if (words[j].size() <= words[i].size()) {
                    if (words[i].find(words[j]) != string::npos)
                        ans.emplace(words[j]);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
