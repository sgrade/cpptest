// 1094. Car Pooling
// https://leetcode.com/problems/car-pooling/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      sort(trips.begin(), trips.end(), [](vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
      });

      // current capacity
      int current_capacity = capacity;
      // next to drop: to, passengers
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      for (int i = 0; i < trips.size(); ++i) {
        int from = trips[i][1];
        while (!pq.empty() && pq.top().first <= from) {
          current_capacity = min(capacity, current_capacity + pq.top().second);
          pq.pop();
        }
        int passengers = trips[i][0], to = trips[i][2];
        current_capacity -= passengers;
        if (current_capacity < 0)
          return false;
        pq.emplace(to, passengers);
      }

      return true;
    }
};
