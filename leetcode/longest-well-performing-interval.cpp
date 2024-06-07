// 1124. Longest Well-Performing Interval
// https://leetcode.com/problems/longest-well-performing-interval/

#include <bits/stdc++.h>

using namespace std;


// Based on [cpp] O(N) solution with detailed explanation
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0, cnt = 0;
        unordered_map<int, int> balance;
        balance[0] = -1;
        for (int i = 0; i < hours.size(); ++i) {
            cnt += hours[i] > 8 ? 1 : -1;
            if (cnt > 0)
                ans = max(ans, i + 1);
            else {
                if (balance.find(cnt - 1) != balance.end())
                    ans = max(ans, i - balance[cnt - 1]);
                if (balance.find(cnt) == balance.end())
                    balance[cnt] = i;
            }
        }
        return ans;
    }
};
