// 2594. Minimum Time to Repair Cars
// https://leetcode.com/problems/minimum-time-to-repair-cars/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Using Heap
class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_map<int, int> rank_counter;
            for (const int& rank: ranks)
                ++rank_counter[rank];

            // {time, rank, repaired, mechanics_with_rank}
            auto comp = [](vector<long>& v1, vector<long>& v2){
                return v1[0] > v2[0];
            };

            priority_queue<vector<long>, vector<vector<long>>, decltype(comp)> pq(comp);
            for (const auto& [rank, cnt]: rank_counter)
                pq.emplace(vector<long>{rank, rank, 1, cnt});

            long time = 0;
            while (cars > 0) {
                vector<long> current = pq.top();
                pq.pop();
                time = current[0];
                int rank = current[1], mechanics = current[3];
                long repaired = current[2];
                cars -= mechanics;
                ++repaired;
                pq.emplace(vector<long>{rank * repaired * repaired, rank, repaired, mechanics});
            }

            return time;
        }
    };
