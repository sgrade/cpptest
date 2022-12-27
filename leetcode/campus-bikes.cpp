// 1057. Campus Bikes
// https://leetcode.com/problems/campus-bikes/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 3: Priority Queue
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // distance, worker, bike
        vector<vector<tuple<int, int, int>>> worker_to_bike;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for (int w = 0; w < workers.size(); ++w) {
            vector<tuple<int, int, int>> current;
            for (int b = 0; b < bikes.size(); ++b) {
                int distance = abs(workers[w][0] - bikes[b][0]) + abs(workers[w][1] - bikes[b][1]);
                current.emplace_back(tuple<int, int, int>{distance, w, b});
            }
            sort(current.begin(), current.end(), greater<tuple<int, int, int>>());
            pq.emplace(current.back());
            current.pop_back();
            worker_to_bike.emplace_back(current);
        }

        vector<int> bike_is_assigned(bikes.size());
        vector<int> worker_has_bike(workers.size(), -1);

        while(!pq.empty()) {
            auto[dist, w, b] = pq.top();
            pq.pop();
            if (!bike_is_assigned[b]) {
                bike_is_assigned[b] = true;
                worker_has_bike[w] = b;
            }
            else {
                pq.emplace(worker_to_bike[w].back());
                worker_to_bike[w].pop_back();
            }
        }

        return worker_has_bike;
    }
};
