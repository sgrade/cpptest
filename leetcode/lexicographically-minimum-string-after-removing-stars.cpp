// 3170. Lexicographically Minimum String After Removing Stars
// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Greedy
class Solution {
public:
    string clearStars(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<stack<int>> indexes(26);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*')
                indexes[s[i] - 'a'].emplace(i);
            else {
                for (int j = 0; j < 26; ++j) {
                    if (!indexes[j].empty()) {
                        int smallest_idx = indexes[j].top();
                        s[smallest_idx] = '*';
                        indexes[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*')
                ans += s[i];
        }

        return ans;
    }
};
