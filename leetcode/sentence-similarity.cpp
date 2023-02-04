// 734. Sentence Similarity
// https://leetcode.com/problems/sentence-similarity/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_set<string>> mp;
        for (vector<string>& v: similarPairs) {
            sort(v.begin(), v.end());
            mp[v[0]].emplace(v[1]);
        }
        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) continue;
            vector<string> tmp{sentence1[i], sentence2[i]};
            sort(tmp.begin(), tmp.end());
            if (mp[tmp[0]].find(tmp[1]) == mp[tmp[0]].end()) {
                return false;
            }
        }
        return true;
    }
};
