// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Greedy with Stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        for (const char& ch: num) {
            while (!dq.empty() && k > 0 && dq.back() > ch) {
                dq.pop_back();
                --k;
            }
            dq.emplace(dq.end(), ch);
        }

        for (int i = 0; i < k; ++i)
            dq.pop_back();

        string ans = "";
        while (!dq.empty() && dq.front() == '0')
            dq.pop_front();

        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }

        if (ans.size() == 0)
            return "0";
        return ans;
    }
};
