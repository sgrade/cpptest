// 2501. Longest Square Streak in an Array
// https://leetcode.com/problems/longest-square-streak-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = -1;
        set<int> st (nums.begin(), nums.end());
        auto it = st.begin();
        long long x = *it, mx = *st.rbegin();
        while (x * x <= mx) {
            int cur_ans = 1;
            long long cur_num = x;
            while (cur_num * cur_num <= mx) {
                cur_num *= cur_num;
                if (st.find(cur_num) != st.end())
                    ++cur_ans;
                else
                    break;
            }
            if (cur_ans > 1)
                ans = max(ans, cur_ans);
            ++it;
            x = *it;
        }
        return ans;
    }
};
