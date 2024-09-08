// 1229. Meeting Scheduler
// https://leetcode.com/problems/meeting-scheduler/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded: 18 / 25 testcases passed
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        this->duration = duration;
        n1 = slots1.size(), n2 = slots2.size();
        check (0, 0, slots1, slots2);
        return ans;
    }

private:
    int duration, n1, n2;
    vector<int> ans;
    void check (int i1, int i2, vector<vector<int>>& slots1, vector<vector<int>>& slots2) {
        if (ans.size() > 0 || i1 == n1 || i2 == n2)
            return;
        int s1 = slots1[i1][0], e1 = slots1[i1][1];
        int s2 = slots2[i2][0], e2 = slots2[i2][1];
        if (s1 >= e2)
            check (i1, i2 + 1, slots1, slots2);
        if (s2 >= e1)
            check (i1 + 1, i2, slots1, slots2);

        int max_s = max(s1, s2), min_e = min(e1, e2);
        if (min_e - max_s >= duration) {
            ans.emplace_back(max_s);
            ans.emplace_back(max_s + duration);
            return;
        }
        else {
            check (i1 + 1, i2, slots1, slots2);
            check (i1, i2 + 1, slots1, slots2);
        }
    }
};
