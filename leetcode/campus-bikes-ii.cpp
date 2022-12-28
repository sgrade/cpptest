// 1066. Campus Bikes II
// https://leetcode.com/problems/campus-bikes-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 4: Priority Queue (Similar to Dijkstra's Algorithm)
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int num_of_bikes = bikes.size();
        int num_of_workers = workers.size();

        // <distance_sum, mask>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;

        pq.emplace(pair<int, int>{0, 0});
        while (!pq.empty()) {
            int current_distance_sum = pq.top().first;
            int current_mask = pq.top().second;
            pq.pop();

            if (visited.find(current_mask) != visited.end()) {
                continue;
            }
            visited.emplace(current_mask);

            int worker_index = CountNumOfOnes(current_mask);
            if (worker_index == num_of_workers) {
                return current_distance_sum;
            }

            for (int bike_index = 0; bike_index < num_of_bikes; ++bike_index) {
                if ((current_mask & (1 << bike_index)) == 0) {
                    int distance = abs(workers[worker_index][0] - bikes[bike_index][0]) + 
                        abs(workers[worker_index][1] - bikes[bike_index][1]);
                    int next_state_distance_sum = current_distance_sum + distance;

                    int next_state_mask = current_mask | (1 << bike_index);
                    pq.emplace(pair<int, int>{next_state_distance_sum, next_state_mask});
                }
            }
        }

        // Never executed
        return -1;
    }

private:

    // Brian Kernighan’s Algorithm
    int CountNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            ++count;
        }
        return count;
    }
};
