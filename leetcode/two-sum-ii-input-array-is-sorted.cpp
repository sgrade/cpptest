// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int x;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            x = numbers[left] + numbers[right];
            if (x == target) {
                ans = {left + 1, right + 1};
                break;
            }
            else if (x < target) ++ left;
            else --right;
        }
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

    return 0;
}