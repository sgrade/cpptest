// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size() == 0) return ans;
        
        unordered_map<string, vector<string>> pre_ans;
        
        vector<int> count(26);
        for (const string& s: strs) {
            count.assign(26, 0);
            for (const char &c: s) {
                ++count[c - 'a'];
            }
            
            // unoredered_map by default doesn't support vector<int> as a key
            // so we need either a hash function or convert it to a hashable key (here)
            string key;
            for (int i = 0; i < 26; ++i) {
                key += "#";
                key += count[i];
            }
            
            if (pre_ans.find(key) == pre_ans.end()) {
                pre_ans[key] = {s};
            }
            else {
                pre_ans[key].push_back(s);
            }
        }
        for (const auto& [key, v]: pre_ans) {
            ans.push_back(v);
        }
        return ans;
    }
};
