// 1874. Minimize Product Sum of Two Arrays
// https://leetcode.com/problems/minimize-product-sum-of-two-arrays/

#include <algorithm>
#include <vector>

using std::greater;
using std::vector;

class Solution {
 public:
  int minProductSum(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end(), greater<int>());
    int product_sum = 0;
    for (size_t i = 0; i < nums1.size(); i++) {
      product_sum += nums1[i] * nums2[i];
    }
    return product_sum;
  }
};
