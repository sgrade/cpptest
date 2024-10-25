// 1233. Remove Sub-Folders from the Filesystem
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Using Set
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> ans;
        for (string& f: folder) {
            bool is_subfolder = false;
            string prefix = f;
            while (!prefix.empty()) {
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos)
                    break;
                prefix = prefix.substr(0, pos);
                if (st.find(prefix) != st.end()) {
                    is_subfolder = true;
                    break;
                }
            }
            if (!is_subfolder)
                ans.emplace_back(f);
        }
        return ans;
    }
};
