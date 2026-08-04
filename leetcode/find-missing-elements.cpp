// 3731. Find Missing Elements
// https://leetcode.com/problems/find-missing-elements/

#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMissingElements(vector<int>& nums) {
    set<int> existing(nums.begin(), nums.end());
    int mn = *existing.begin();
    int mx = *(existing.rbegin());
    vector<int> ans;
    for (int num = mn; num < mx; ++num) {
      if (existing.find(num) == existing.end()) {
        ans.emplace_back(num);
      }
    }
    return ans;
  }
};
