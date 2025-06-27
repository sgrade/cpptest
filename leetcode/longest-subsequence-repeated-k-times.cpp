// 2014. Longest Subsequence Repeated k Times
// https://leetcode.com/problems/longest-subsequence-repeated-k-times/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Brute-force Enumeration
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->k = k;
        n = s.size();

        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];

        vector<char> candidates;
        for (int i = 25; i >= 0; --i) {
            if (counter[i] >= k)
                candidates.emplace_back('a' + i);
        }

        queue<string> q;
        for (char ch: candidates)
            q.emplace(string(1, ch));

        string ans = "";
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size() > ans.size())
                ans = cur;
            for (const char& ch: candidates) {
                string next = cur + ch;
                if (isRepeatedK(s, next))
                    q.emplace(next);
            }
        }
        return ans;
    }

private:
    int k, n;
    bool isRepeatedK(const string& s, const string& candidate) {
        int pos = 0, repeated = 0;
        int c_size = candidate.size();
        for (const char& ch: s) {
            if (ch == candidate[pos]){
                ++pos;
                if (pos == c_size) {
                    pos = 0;
                    ++repeated;
                    if (repeated == k)
                        return true;
                }
            }
        }
        return false;
    }
};
