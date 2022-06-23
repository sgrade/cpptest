// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        string tmp;
        for (int i = 0; i < strs.size(); ++i) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        vector<vector<string>> output;
        for (auto &p: mp) {
            output.push_back(p.second);
        }
        return output;
    }
};
