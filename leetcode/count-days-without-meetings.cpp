// 3169. Count Days Without Meetings
// https://leetcode.com/problems/count-days-without-meetings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            sort(meetings.begin(), meetings.end());
            int ans = 0, cur_end = 0;
            for (const vector<int>& m: meetings) {
                int next_begin = m[0], next_end = m[1];
                if (cur_end < next_begin)
                    ans += next_begin - cur_end - 1;
                cur_end = max(cur_end, next_end);
            }
            ans += max(0, days - cur_end);
            return ans;
        }
    };
