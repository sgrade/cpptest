// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from a sample solution
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (const char& ch: num) {
            while (!ans.empty() && ans.back() > ch && k > 0) {
                ans.pop_back();
                --k;
            }
            if (ch != '0' || !ans.empty())
                ans.push_back(ch);
        }
        for (int i = 0; !ans.empty() && i < k; ++i)
            ans.pop_back();
        if (ans.size() == 0)
            return "0";
        return ans;
    }
};
