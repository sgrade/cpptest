// 851. Loud and Rich
// https://leetcode.com/problems/loud-and-rich/

#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<int> loudAndRich(const std::vector<std::vector<int>>& richer,
                               const std::vector<int>& quiet) {
    int n = quiet.size();
    adj_.assign(n, {});
    for (const auto& r : richer) {
      adj_[r[1]].emplace_back(r[0]);
    }
    ans_.assign(n, -1);
    for (int person = 0; person < n; ++person) {
      Dfs(person, quiet);
    }
    return ans_;
  }

 private:
  std::vector<int> ans_;
  std::vector<std::vector<int>> adj_;

  int Dfs(int person, const std::vector<int>& quiet) {
    if (ans_[person] != -1) {
      return ans_[person];
    }
    int quietest_person = person;
    for (int richer_person : adj_[person]) {
      int candidate = Dfs(richer_person, quiet);
      if (quiet[candidate] < quiet[quietest_person]) {
        quietest_person = candidate;
      }
    }
    ans_[person] = quietest_person;
    return quietest_person;
  }
};
