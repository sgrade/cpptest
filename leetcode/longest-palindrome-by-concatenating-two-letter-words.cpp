// 2131. Longest Palindrome by Concatenating Two Letter Words
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<string, int> counter;
        for (const string& w: words)
            ++counter[w];

        int ans = 0, n = counter.size();
        bool mid = false;
        while (!counter.empty()) {
            auto [w, cnt] = *counter.begin();
            if (w[0] == w[1]) {
                int rem = counter[w] % 2;
                if (rem)
                    mid = true;
                ans += cnt / 2 * 4;
            }
            else {
                string rev = w;
                swap(rev[0], rev[1]);
                if (counter.find(rev) != counter.end()) {
                    ans += min(cnt, counter[rev]) * 4;
                    counter.erase(rev);
                }
            }
            counter.erase(w);
        }
        if (mid)
            ans += 2;
        return ans;
    }
};
