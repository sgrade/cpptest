// 38. Count and Say
// https://leetcode.com/problems/count-and-say/

#inclde <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Straightforward
class Solution {
    public:
        string countAndSay(int n) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            string ans = "1";
            while (--n) {
                string s;
                for (int i = 0, j = 0; i < ans.size(); i = j) {
                    while (j < ans.size() && ans[j] == ans[i])
                        ++j;
                    s += to_string(j - i) + ans[i];
                }
                ans = s;
            }
            return ans;
        }
    };
