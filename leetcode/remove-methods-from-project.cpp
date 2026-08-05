// 3310. Remove Methods From Project
// https://leetcode.com/problems/remove-methods-from-project/

#include <deque>
#include <numeric>
#include <vector>

using namespace std;

// Based on Editorial's Approach: Searching
class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> graph(n);
    for (const vector<int>& inv : invocations) {
      int caller = inv[0];
      int callee = inv[1];
      graph[caller].emplace_back(callee);
    }

    vector<bool> suspicious(n);
    suspicious[k] = true;
    deque<int> queue{k};
    while (!queue.empty()) {
      int method = queue.front();
      queue.pop_front();
      for (int callee : graph[method]) {
        if (!suspicious[callee]) {
          suspicious[callee] = true;
          queue.emplace_back(callee);
        }
      }
    }

    for (const vector<int>& inv : invocations) {
      int caller = inv[0];
      int callee = inv[1];
      if (!suspicious[caller] && suspicious[callee]) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        return ans;
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (!suspicious[i]) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};
