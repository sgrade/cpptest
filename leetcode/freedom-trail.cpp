// 514. Freedom Trail
// https://leetcode.com/problems/freedom-trail/

#include <bits/stdc++.h>

using namespace std;

// Based on Editorial's Approach 4: Shortest Path
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        n_ring = ring.size(), n_key = key.size();

        unordered_map<char, vector<int>> char_indexes;
        for (int i = 0 ;i < n_ring; ++i)
            char_indexes[ring[i]].emplace_back(i);

        // <total_steps, <ring_idx, key_idx>>
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        pq.emplace(0, pair<int, int>(0, 0));

        unordered_set<string> visited;

        int total_steps = 0;
        while (!pq.empty()) {
            total_steps = pq.top().first;
            const auto [ring_idx, key_idx] = pq.top().second;
            pq.pop();
            if (key_idx == n_key)
                break;

            string current_state = to_string(ring_idx) + "-" + to_string(key_idx);
            if (visited.find(current_state) != visited.end())
                continue;
            visited.emplace(current_state);

            for (const int& next_idx: char_indexes[key[key_idx]]) {
                int min_steps = getMinSteps (ring_idx, next_idx);
                pq.emplace(total_steps + min_steps, pair<int, int>(next_idx, key_idx + 1));
            }
        }

        return total_steps + n_key;
    }

private:
    int n_ring, n_key;
    int getMinSteps (const int& ring_idx, const int& next_idx) {
        int steps = abs(ring_idx - next_idx);
        int steps_other_direction = n_ring - steps;
        return min(steps, steps_other_direction);
    }
};
