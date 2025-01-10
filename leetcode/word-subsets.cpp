// 916. Word Subsets
// https://leetcode.com/problems/word-subsets/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Reduce to Single Word in B
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> counter(26);
        for (const string& s: words2) {
            vector<int> current(26);
            for (const char& ch: s)
                ++current[ch - 'a'];
            for (int i = 0; i < 26; ++i)
                counter[i] = max(counter[i], current[i]);
        }

        vector<string> ans;
        for (const string& s: words1) {
            vector<int> current(26);
            for (const char& ch: s)
                ++current[ch - 'a'];
            bool found = true;
            for (int i = 0; i < 26; ++i) {
                if (current[i] < counter[i]) {
                    found = false;
                    break;
                }
            }
            if (found)
                ans.emplace_back(s);
        }
        return ans;
    }
};
