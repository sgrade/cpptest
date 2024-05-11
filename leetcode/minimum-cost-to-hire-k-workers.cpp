// 857. Minimum Cost to Hire K Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Priority Queue
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = quality.size();
        double total_cost = numeric_limits<double>::max();
        double current_total_quality = 0;
        // <wage to quality ratio, quality>
        vector<pair<double, int>> ratio_and_quality;

        for (int i = 0; i < n; ++i) {
            double ratio = 1.0 * wage[i] / quality[i];
            ratio_and_quality.emplace_back(ratio, quality[i]);
        }
        sort(ratio_and_quality.begin(), ratio_and_quality.end());

        priority_queue<int> highest_quality_workers;
        for (int i = 0; i < n; ++i) {
            int current_quality = ratio_and_quality[i].second;
            highest_quality_workers.emplace(current_quality);
            current_total_quality += current_quality;
            if (highest_quality_workers.size() > k) {
                int highest_quality = highest_quality_workers.top();
                highest_quality_workers.pop();
                current_total_quality -= highest_quality;
            }
            if (highest_quality_workers.size() == k) {
                double ratio = ratio_and_quality[i].first;
                total_cost = min(total_cost, current_total_quality * ratio);
            }
        }
        return total_cost;
    }
};
