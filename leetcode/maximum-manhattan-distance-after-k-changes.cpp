// 3443. Maximum Manhattan Distance After K Changes
// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxDistance(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int ns = 0, ew = 0, ans = 0;    // north-south, east-west
        for (int i = 0; i < s.size(); ++i) {
            const char& ch = s[i];
            if (ch == 'N')
                --ns;
            else if (ch == 'S')
                ++ns;
            else if (ch == 'E')
                --ew;
            else
                ++ew;
            int cur_ans = min(i + 1, abs(ns) + abs(ew) + k * 2);
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};
