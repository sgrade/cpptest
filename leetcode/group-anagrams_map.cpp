// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size() == 0) return ans;
        
        // unoredered_map by default doesn't support vector<int> as a key
        // you need to write hash function to overcome it
        // https://jimmy-shen.medium.com/stl-map-unordered-map-with-a-vector-for-the-key-f30e5f670bae
        map<vector<int>, vector<string>> pre_ans;
        
        vector<int> count(26);
        for (const string& s: strs) {
            count.assign(26, 0);
            for (const char &c: s) {
                ++count[c - 'a'];
            }
            if (pre_ans.find(count) == pre_ans.end()) {
                pre_ans[count] = {s};
            }
            else {
                pre_ans[count].push_back(s);
            }
        }
        for (const auto& [key, value]: pre_ans) {
            ans.push_back(value);
        }
        return ans;
    }
};
