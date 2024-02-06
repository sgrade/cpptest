// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<string, vector<string>> anagrams;
        for (const string& s: strs) {
            vector<int> chars(26);
            for (const char& ch: s)
                ++chars[ch - 'a'];
            string hash = "";
            for (int i = 0; i < 26; ++i) {
                if (chars[i] == 0)
                    continue;
                hash += 'a' + i;
                hash += '-';
                hash += to_string(chars[i]);
                hash += '-';
            }
            anagrams[hash].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (const auto& [_, v]: anagrams)
            ans.emplace_back(v);
        return ans;
    }
};
