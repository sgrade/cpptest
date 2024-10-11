// 942. The Number of the Smallest Unoccupied Chair
// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Set with Sorted Insertion
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        int target_arrival = times[targetFriend][0];
        sort(times.begin(), times.end());

        int next_chair = 0, current_chair = 0;
        set<int> unoccupied;
        for (int i = 0; i < times.size(); ++i) {
            int arrival = times[i][0], leaving = times[i][1];
            while (!occupied.empty() && occupied.top().first <= arrival) {
                unoccupied.emplace(occupied.top().second);
                occupied.pop();
            }
            if (!unoccupied.empty()) {
                current_chair = *unoccupied.begin();
                unoccupied.erase(unoccupied.begin());
            }
            else
                current_chair = next_chair++;
            occupied.emplace(leaving, current_chair);
            if (arrival == target_arrival)
                return current_chair;
        }
        return 0;
    }
};
