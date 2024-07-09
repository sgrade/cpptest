// 1701. Average Waiting Time
// https://leetcode.com/problems/average-waiting-time/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long sum = 0;
        int chef_becomes_free = 0;
        for (const vector<int>& customer: customers) {
            int arrival = customer[0], time = customer[1];
            int start = max (chef_becomes_free, arrival);
            int finish = start + time;
            int waiting_time = finish - arrival;
            sum += waiting_time;
            chef_becomes_free = finish;
        }
        int n = customers.size();
        double ans = 1.0 * sum / n;
        return ans;
    }
};
