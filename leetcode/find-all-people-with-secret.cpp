// 2092. Find All People With Secret
// https://leetcode.com/problems/find-all-people-with-secret/

#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>

using std::pair;
using std::queue;
using std::sort;
using std::unordered_map;
using std::vector;

// Based on Editorial's Approach 1: Breadth First Search
class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                            int firstPerson) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for (const vector<int>& m : meetings) {
      int x = m[0], y = m[1], t = m[2];
      adj[x].emplace_back(t, y);
      adj[y].emplace_back(t, x);
    }

    // Sort adjacency lists by time for early termination
    for (auto& [person, meetings] : adj) {
      sort(meetings.begin(), meetings.end());
    }

    // Time at which a person learned the secret
    vector<int> learned_time(n, INT_MAX);
    learned_time[0] = 0;
    learned_time[firstPerson] = 0;

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    q.emplace(firstPerson, 0);

    while (!q.empty()) {
      auto [cur_person, cur_time] = q.front();
      q.pop();

      // Skip if this is an outdated entry (we already learned earlier)
      if (cur_time > learned_time[cur_person]) {
        continue;
      }

      for (auto [next_time, next_person] : adj[cur_person]) {
        // Early termination: meetings are sorted, no point checking later ones
        if (next_time < cur_time) {
          continue;
        }

        if (learned_time[next_person] > next_time) {
          learned_time[next_person] = next_time;
          q.emplace(next_person, next_time);
        }
      }
    }

    vector<int> know_secret;
    know_secret.reserve(n);  // Pre-allocate to avoid reallocation
    for (int i = 0; i < n; ++i) {
      if (learned_time[i] != INT_MAX) {
        know_secret.emplace_back(i);
      }
    }
    return know_secret;
  }
};