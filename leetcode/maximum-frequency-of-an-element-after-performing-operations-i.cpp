// 3346. Maximum Frequency of an Element After Performing Operations I
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::min;
using std::max;


// Based on Editorial's Approach: Sort + Enumerate + Binary Search
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> counter;
        for (const int num: nums) {
            ++counter[num];
        }

        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int num = nums[0]; num <= nums[nums.size() - 1]; ++num) {
            int left = num - k, right = num + k;
            vector<int>::iterator left_it = lower_bound(nums.begin(), nums.end(), left);
            vector<int>::iterator right_it = upper_bound(nums.begin(), nums.end(), right);
            int can_change = distance(left_it, right_it);
            int cur_ans = 0;
            if (counter.count(num)) {
                cur_ans = min(can_change, counter[num] + numOperations);
            } else {
                cur_ans = min(can_change, numOperations);
            }
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};
