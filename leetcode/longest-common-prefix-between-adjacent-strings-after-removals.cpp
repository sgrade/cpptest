// 3598. Longest Common Prefix Between Adjacent Strings After Removals
// https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = words.size();
        if (n < 2)
            return {0};

        vector<int> prefix_sum(n), suffix_sum(n);
        for (int i = 1; i < n; ++i)
            prefix_sum[i] = max(prefix_sum[i - 1], calculateCommonPrefixLen(words[i - 1], words[i]));
        for (int i = n - 2; i >= 0; --i)
            suffix_sum[i] = max(suffix_sum[i + 1], calculateCommonPrefixLen(words[i + 1], words[i]));
        
        vector<int> ans(n);
        ans[0] = suffix_sum[1];
        ans[n - 1] = prefix_sum[n - 2];
        for (int i = 1; i < n - 1; ++i) {
            int neighbors_len = calculateCommonPrefixLen(words[i - 1], words[i + 1]);
            ans[i] = max({prefix_sum[i - 1], neighbors_len, suffix_sum[i + 1]});
        }
        return ans;
    }

private:
    int n;
    int calculateCommonPrefixLen(const string& w1, const string w2) {
        int len1 = w1.size(), len2 = w2.size(), len = min(len1, len2), cur_ans = 0;
        for (int i = 0; i < len; ++i) {
            if (w1[i] != w2[i])
                break;
            ++cur_ans;
        }
        return cur_ans;
    }
};
