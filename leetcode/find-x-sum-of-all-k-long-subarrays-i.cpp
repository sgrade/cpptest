// 3318. Find X-Sum of All K-Long Subarrays I
// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/

#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    if (k == 1) {
      return nums;
    }

    int n = nums.size();
    unordered_map<int, int> cntr;
    for (int i = 0; i < k - 1; ++i) {
      ++cntr[nums[i]];
    }

    // Comparator: sort by frequency desc, then by value desc
    auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
      if (p1.second != p2.second) {
        return p1.second < p2.second;  // Higher frequency first
      }
      return p1.first < p2.first;  // Higher value first
    };

    vector<int> ans;
    for (int i = k - 1; i < n; ++i) {
      ++cntr[nums[i]];
      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
          cmp, vector<pair<int, int>>(cntr.begin(), cntr.end()));

      int sm = 0;
      for (int j = 0; j < x && !pq.empty(); ++j) {
        auto [num, cnt] = pq.top();
        pq.pop();
        sm += num * cnt;
      }
      ans.emplace_back(sm);
      if (cntr[nums[i - k + 1]] == 1) {
        cntr.erase(nums[i - k + 1]);
      } else {
        --cntr[nums[i - k + 1]];
      }
    }
    return ans;
  }
};