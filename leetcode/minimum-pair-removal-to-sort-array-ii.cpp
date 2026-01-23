// 3510. Minimum Pair Removal to Sort Array II
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/

#include <bitset>
#include <list>
#include <queue>
#include <vector>

using namespace std;

// Based on Editorial's Approach: Priority Queue + Lazy Deletion
using ll = long long;

constexpr int MAX_N = 100005;

struct Node {
  ll value;
  int left;
};

using ListIt = list<Node>::iterator;

struct Pair {
  ListIt first;
  ListIt second;
  ll cost;
  size_t first_left;
  size_t second_left;

  Pair(ListIt fi, ListIt se, ll cost)
      : first(fi),
        second(se),
        cost(cost),
        first_left(fi->left),
        second_left(se->left) {}
};

struct ComparePair {
  bool operator()(const Pair& a, const Pair& b) const {
    return a.cost != b.cost ? a.cost > b.cost : a.first_left > b.first_left;
  }
};

class Solution {
 public:
  int minimumPairRemoval(vector<int>& nums) {
    list<Node> node_list;
    bitset<MAX_N> merged;
    priority_queue<Pair, vector<Pair>, ComparePair> pq;

    int decrease_count = 0;
    int count = 0;

    node_list.push_back({nums[0], 0});

    for (size_t i = 1; i < nums.size(); ++i) {
      node_list.push_back({nums[i], static_cast<int>(i)});

      auto curr = prev(node_list.end());
      auto prev_it = prev(curr);

      pq.emplace(prev_it, curr, prev_it->value + curr->value);

      if (nums[i - 1] > nums[i]) {
        ++decrease_count;
      }
    }

    while (decrease_count > 0 && !pq.empty()) {
      const auto& top = pq.top();

      if (merged[top.first_left] || merged[top.second_left]) {
        pq.pop();
        continue;
      }

      auto first = top.first;
      auto second = top.second;
      auto cost = top.cost;
      pq.pop();

      if (first->value + second->value != cost) {
        continue;
      }

      ++count;

      if (first->value > second->value) {
        --decrease_count;
      }

      auto prev_it =
          (first == node_list.begin()) ? node_list.end() : prev(first);
      auto next = std::next(second);

      if (prev_it != node_list.end()) {
        if (prev_it->value > first->value && prev_it->value <= cost) {
          --decrease_count;
        }
        if (prev_it->value <= first->value && prev_it->value > cost) {
          ++decrease_count;
        }
        pq.emplace(prev_it, first, prev_it->value + cost);
      }

      if (next != node_list.end()) {
        if (second->value > next->value && cost <= next->value) {
          --decrease_count;
        }
        if (second->value <= next->value && cost > next->value) {
          ++decrease_count;
        }
        pq.emplace(first, next, cost + next->value);
      }

      first->value = cost;
      merged[second->left] = true;
      node_list.erase(second);
    }

    return count;
  }
};