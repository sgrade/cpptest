// 3347. Maximum Frequency of an Element After Performing Operations II
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::min;
using std::max;


// Based solution - // https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/
// Modified with ideas from Editorial's Approach: Sort + Enumerate + Binary Search
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> counter;
        for (const int num: nums) {
            ++counter[num];
        }
        unordered_set<int> modes;
        for (const auto& [num, cnt]: counter) {
            ans = max(ans, cnt);
            modes.emplace(num);
            if (num - k >= nums.front()) {
                modes.emplace(num - k);
            }
            if (num + k <= nums.back()) {
                modes.emplace(num + k);
            }
        }
        

        for (const int num: modes) {
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
