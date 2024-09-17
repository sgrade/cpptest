// 884. Uncommon Words from Two Sentences
// https://leetcode.com/problems/uncommon-words-from-two-sentences/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<string, int> counter;
        stringstream iss(s1);
        string s;
        while(iss >> s)
            ++counter[s];
        iss.clear();
        iss.str(s2);
        while(iss >> s)
            ++counter[s];
        vector<string> ans;
        for (const auto& [s, cnt]: counter) {
            if (cnt == 1)
                ans.emplace_back(s);
        }
        return ans;
    }
};
