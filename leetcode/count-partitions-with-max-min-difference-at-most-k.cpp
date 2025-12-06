// 3578. Count Partitions With Max-Min Difference at Most K
// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/

#include <set>
#include <vector>

using std::multiset;
using std::vector;

// Based on Editorial's Approach 1: Sliding Window + Dynamic Programming
class Solution {
 public:
  int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> valid_partitions(n + 1),
        valid_partitions_for_prefix(n + 1);
    valid_partitions[0] = 1, valid_partitions_for_prefix[0] = 1;
    multiset<int> nums_in_window;

    int left = 0;
    for (int right = 0; right < n; ++right) {
      nums_in_window.emplace(nums[right]);
      while (*nums_in_window.rbegin() - *nums_in_window.begin() > k) {
        multiset<int>::iterator it = nums_in_window.find(nums[left]);
        nums_in_window.erase(it);
        left++;
      }
      valid_partitions[right + 1] =
          (valid_partitions_for_prefix[right] -
           (left == 0 ? 0 : valid_partitions_for_prefix[left - 1]) + kMod) %
          kMod;
      valid_partitions_for_prefix[right + 1] =
          (valid_partitions_for_prefix[right] + valid_partitions[right + 1]) %
          kMod;
    }

    return valid_partitions[n];
  }

 private:
  static constexpr long long kMod = 1e9 + 7;
};
