// 1. Two Sum
// https://leetcode.com/problems/two-sum/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    goto ANS;
                }
            }
        }
        ANS:
        return ans;
    }
};


int main() {

    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution sol;

    vector<int> ans = sol.twoSum(nums, target);

    for (auto &el: ans) {
        cout << el << ' ';
    }
    cout << '\n';

}
