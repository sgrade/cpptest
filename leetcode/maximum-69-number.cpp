// 1323. Maximum 69 Number
// https://leetcode.com/problems/maximum-69-number/

#include <vector>
#include <algorithm>


class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        std::vector<int> nums;
        while (temp) {
            nums.emplace_back(temp % 10);
            temp /= 10;
        }
        reverse(nums.begin(), nums.end());
        bool changed = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 6) {
                nums[i] = 9;
                changed = true;
                break;
            }
        }

        if (!changed) {
            return num;
        }

        int ans = 0;
        for (const int num: nums) {
            ans *= 10;
            ans += num;
        }
        return ans;
    }
};
