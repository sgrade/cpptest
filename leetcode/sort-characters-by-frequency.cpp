// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        vector<int> counter(75);
        for (const char& ch: s)
            ++counter[ch - '0'];

        vector<pair<int, char>> freq;
        for (int i = 0; i < counter.size(); ++i) {
            if (counter[i] == 0)
                continue;
            freq.emplace_back(counter[i], '0' + i);
        }
        sort(freq.begin(), freq.end());
        string ans = "";
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (int j = 0; j < freq[i].first; ++j)
                ans += freq[i].second;
        }
        return ans;
    }
};
