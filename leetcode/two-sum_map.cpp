// 1. Two Sum
// https://leetcode.com/problems/two-sum/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        
        int x;
        for (int i = 0; i < nums.size(); ++i) {
            x = target - nums[i];
            if (mp.find(x) != mp.end() && mp[x] != i) {
                ans[0] = i;
                ans[1] = mp[x];
                break;
            }
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

}
