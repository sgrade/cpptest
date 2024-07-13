// 1717. Maximum Score From Removing Substrings
// https://leetcode.com/problems/maximum-score-from-removing-substrings/

#include <bits/stdc++.h>

using namespace std;


// Used the idea from the Editorial's Approach 3: Greedy Way (Counting)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
       
        n = s.size();
        ans = 0;
        string pattern, anti_pattern;
        if (x > y) {
            pattern = "ab";
            this->x = x;
            this->y = y;
        }
        else {
            pattern = "ba";
            this->x = y;
            this->y = x;
        }
        
        traverse (s, pattern);
        // swap (pattern[0], pattern[1]);
        // traverse (s, pattern, y);

        return ans;
    }

private:
    int n, x, y, ans = 0;
    void traverse (const string& s, const string& pattern) {
        char ch1 = pattern[0], ch2 = pattern[1];
        int cnt_ch1 = 0, cnt_ch2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ch1) {
                ++cnt_ch1;
            }
            else if (s[i] == ch2) {
                if (cnt_ch1 > 0) {
                    --cnt_ch1;
                    ans += x;
                }
                else {
                    ++cnt_ch2;
                }
            }
            else {
                ans += min(cnt_ch1, cnt_ch2) * y;
                cnt_ch1 = 0;
                cnt_ch2 = 0;
            }
        }
        ans += min(cnt_ch1, cnt_ch2) * y;
    }
};
