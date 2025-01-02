// 2559. Count Vowel Strings in Ranges
// https://leetcode.com/problems/count-vowel-strings-in-ranges/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = words.size();
        vector<int> prefix_sum(n);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            bool start = find(vowels.begin(), vowels.end(), words[i][0]) != vowels.end();
            bool end = find(vowels.begin(), vowels.end(), words[i].back()) != vowels.end();
            sum += start && end;
            prefix_sum[i] = sum;
        }

        vector<int> ans;
        for (const vector<int>& q: queries) {
            size_t start = q[0] == 0 ? 0 : prefix_sum[q[0] - 1];
            size_t end = prefix_sum[q[1]];
            ans.emplace_back(end - start);
        }
        return ans;
    }
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
};
