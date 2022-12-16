// 249. Group Shifted Strings
// https://leetcode.com/problems/group-shifted-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        int idx;
        for (const string& s: strings) {
            idx = GetSeqIndex(s);
            if (ans.size() == idx) {
                ans.emplace_back(vector<string>{s});
            }
            else {
                ans[idx].emplace_back(s);
            }
        }
        return ans;
    }
private:
    unordered_map<char, int> chars = {{'a', 0},{'b', 1},{'c', 2},{'d', 3},{'e', 4},{'f', 5},{'g', 6},{'h', 7}, {'i', 8},{'j', 9},{'k', 10},{'l', 11},{'m', 12},{'n', 13},{'o', 14},{'p', 15},{'q', 16},{'r', 17},{'s', 18},{'t', 19},{'u', 20},{'v', 21},{'w', 22},{'x', 23},{'y', 24},{'z', 25}};

    unordered_map<string, int> seq_indexes;

    int GetSeqIndex(const string& s) {
        string hsh = "";
        int prev = chars[s[0]], cur, d;
        for (int i = 1; i < s.size(); ++i) {
            cur = chars[s[i]];
            d = cur < prev ? 26 + cur - prev : cur - prev;
            hsh += '+' + to_string(d);
            prev = cur;
        }
        if (seq_indexes.find(hsh) == seq_indexes.end()) {
            seq_indexes[hsh] = seq_indexes.size();
            
        }
        return seq_indexes[hsh];
    }
};
