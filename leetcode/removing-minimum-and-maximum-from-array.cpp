// 2091. Removing Minimum and Maximum From Array
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    const auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    int i = distance(nums.begin(), min_it);
    int j = distance(nums.begin(), max_it);
    if (i > j) {
      swap(i, j);
    }
    int n = nums.size();
    int ans = min({j + 1, n - i, i + 1 + n - j});
    return ans;
  }
};
