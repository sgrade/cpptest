// 1. Two Sum
// https://leetcode.com/problems/two-sum/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> positions(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            positions[i] = {nums[i], i};
        }
        sort (positions.begin(), positions.end());

        int left = 0, right = n - 1;
        int tmp;
        while (left < right) {
            tmp = positions[left][0] + positions[right][0];
            if (tmp == target) {
                return {positions[left][1], positions[right][1]};
            }
            else if (tmp < target) {
                ++left;
            }
            else {
                --right;
            }
        }
        
        return {-1, -1};
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
