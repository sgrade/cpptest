// 1792. Maximum Average Pass Ratio
// https://leetcode.com/problems/maximum-average-pass-ratio/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Priority Queue
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (const vector<int>& c : classes)  {
            int pass = c[0], total = c[1];
            double gain = getGain (pass, total);
            pq.emplace(gain, pair<int, int>(pass, total));
        }

        while (extraStudents--) {
            auto [pass, total] = pq.top().second;
            pq.pop();
            double gain = getGain (pass + 1, total + 1);
            pq.emplace(gain, pair<int, int>(pass + 1, total + 1));
        }

        double sum = 0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top().second;
            pq.pop();
            sum += double(pass) / total;
        }
        double ans = sum / classes.size();
        return ans;
    }

private:
    priority_queue<pair<double, pair<int, int>>> pq;
    double getGain (int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};
