// 3321. Find X-Sum of All K-Long Subarrays II
// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/

#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using std::pair;
using std::set;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();

    unordered_map<int, int> cntr;
    for (int i = 0; i < k - 1; ++i) {
      ++cntr[nums[i]];
    }

    long long sm = 0;
    set<pair<int, int>, decltype(&cmp)> x_largest(cmp), rest(cmp);
    for (auto& [num, cnt] : cntr) {
      x_largest.emplace(cnt, num);
      sm += 1LL * num * cnt;
    }
    rebalance(x_largest, rest, sm, x);

    vector<long long> ans;
    for (int i = k - 1; i < n; ++i) {
      int right_num = nums[i];
      int left_num = nums[i - k + 1];

      // Add right element
      updateElement(right_num, 1, x_largest, rest, sm, cntr);

      rebalance(x_largest, rest, sm, x);
      ans.emplace_back(sm);

      // Remove left element
      updateElement(left_num, -1, x_largest, rest, sm, cntr);
      rebalance(x_largest, rest, sm, x);
    }
    return ans;
  }

 private:
  // Comparator: sort by frequency desc, then by value desc
  static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) {
      return p1.first > p2.first;  // Higher frequency first
    }
    return p1.second > p2.second;  // Higher value first
  };

  // Makes sure that the x_largest set always have max x elements with highest
  // priority
  void rebalance(set<pair<int, int>, decltype(&cmp)>& x_largest,
                 set<pair<int, int>, decltype(&cmp)>& rest, long long& sm,
                 const int x) {
    // First, ensure x_largest has at most x elements
    while (x_largest.size() > (size_t)x) {
      auto it = prev(x_largest.end());
      sm -= 1LL * it->first * it->second;
      rest.emplace(*it);
      x_largest.erase(it);
    }

    // Then, fill up to x elements if possible
    while (x_largest.size() < (size_t)x && !rest.empty()) {
      auto it = rest.begin();
      sm += 1LL * it->first * it->second;
      x_largest.emplace(*it);
      rest.erase(it);
    }

    // Finally, swap if rest has higher priority elements than x_largest
    while (!rest.empty() && !x_largest.empty()) {
      auto rest_top = rest.begin();
      auto x_bottom = prev(x_largest.end());

      // If rest's top element has higher priority, swap
      if (cmp(*rest_top, *x_bottom)) {
        sm -= 1LL * x_bottom->first * x_bottom->second;
        sm += 1LL * rest_top->first * rest_top->second;

        x_largest.emplace(*rest_top);
        rest.emplace(*x_bottom);
        rest.erase(rest_top);
        x_largest.erase(x_bottom);
      } else {
        break;  // No more beneficial swaps
      }
    }
  }

  // Update an element: remove old freq pair, update counter, add new freq pair
  void updateElement(int num, int delta,
                     set<pair<int, int>, decltype(&cmp)>& x_largest,
                     set<pair<int, int>, decltype(&cmp)>& rest, long long& sm,
                     unordered_map<int, int>& cntr) {
    int old_cnt = cntr[num];
    int new_cnt = old_cnt + delta;

    // Remove old entry if it exists
    if (old_cnt > 0) {
      pair<int, int> old_pair(old_cnt, num);
      if (x_largest.count(old_pair)) {
        x_largest.erase(old_pair);
        sm -= 1LL * num * old_cnt;
      } else {
        rest.erase(old_pair);
      }
    }

    // Update counter
    if (new_cnt == 0) {
      cntr.erase(num);
    } else {
      cntr[num] = new_cnt;
      // Add back to x_largest by default. Requires rebalancing on the next
      // iteration.
      x_largest.emplace(new_cnt, num);
      sm += 1LL * num * new_cnt;
    }
  }
};
