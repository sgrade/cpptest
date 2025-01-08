// 3042. Count Prefix and Suffix Pairs I
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = words.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() > words[j].size())
                    continue;
                bool prefix = words[j].find(words[i]) == 0;
                bool suffix = words[j].rfind(words[i]) == words[j].size() - words[i].size();
                if (prefix && suffix)
                    ++ans;
            }
        }
        return ans;
    }
};
