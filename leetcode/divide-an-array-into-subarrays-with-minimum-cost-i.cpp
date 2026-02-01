// 3010. Divide an Array Into Subarrays With Minimum Cost I
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    vector<int> mins = {nums[1], nums[2]};
    sort(mins.begin(), mins.end());
    for (size_t i = 3; i < nums.size(); ++i) {
      if (nums[i] < mins[1]) {
        mins[1] = nums[i];
        sort(mins.begin(), mins.end());
      }
    }
    int cost = nums[0] + mins[0] + mins[1];
    return cost;
  }
};