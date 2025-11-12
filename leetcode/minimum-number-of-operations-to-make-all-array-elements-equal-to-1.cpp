// Minimum Number of Operations to Make All Array Elements Equal to 1
// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

#include <numeric>
#include <vector>

using std::gcd;
using std::min;
using std::vector;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ones = 0, g = 0;
    for (const int num : nums) {
      if (num == 1) {
        ++ones;
      }
      g = gcd(g, num);
    }
    if (ones > 0) {
      return n - ones;
    }
    if (g > 1) {
      return -1;
    }

    // Minimum size of an array, which gcd is 1
    int min_len = n;
    for (int lo = 0; lo < n; ++lo) {
      g = 0;
      for (int hi = lo; hi < n; ++hi) {
        g = gcd(g, nums[hi]);
        if (g == 1) {
          min_len = min(min_len, hi - lo + 1);
          break;
        }
      }
    }

    // Min operations to get 1 from the min_len array
    int ops_to_get_one = min_len - 1;
    int ops = ops_to_get_one + (n - 1);
    return ops;
  }
};
