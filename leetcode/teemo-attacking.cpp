// 495. Teemo Attacking
// https://leetcode.com/problems/teemo-attacking/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        int current_end = -1, new_end;
        for (const int& t: timeSeries) {
            new_end = t + duration - 1;
            if (t > current_end) ans += duration;
            else ans += new_end - current_end;
            current_end = new_end;
        }
        return ans;
    }
};
