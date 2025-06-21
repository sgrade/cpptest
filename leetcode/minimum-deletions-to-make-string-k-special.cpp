// 3085. Minimum Deletions to Make String K-Special
// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Hash Table + Enumeration
class Solution {
public:
    int minimumDeletions(string word, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_map<char, int> counter;
        for (const char& ch: word)
            ++counter[ch];
        int ans = word.size();
        for (const auto& [_, cnt1]: counter) {
            int current_ans = 0;
            for (const auto& [_, cnt2]: counter) {
                if (cnt1 > cnt2)
                    current_ans += cnt2;
                else if (cnt2 > cnt1 + k)
                    current_ans += cnt2 - (cnt1 + k);
            }
            ans = min (ans, current_ans);
        }
        return ans;
    }
};
