// 3731. Find Missing Elements
// https://leetcode.com/problems/find-missing-elements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMissingElements(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] > 1) {
        for (int j = nums[i - 1] + 1; j < nums[i]; j++) {
          ans.emplace_back(j);
        }
      }
    }
    return ans;
  }
};
