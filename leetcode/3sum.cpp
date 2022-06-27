// 15. 3Sum
// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(), nums.end());
        int left, right;
        int n = nums.size();
        if (n > 2) {
            for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; ++i) {
                if (i != 0 && (nums[i-1] == nums[i])) continue;
                left = i + 1;
                right = n - 1;
                twoSum(nums, i, left, right);
            }
        }
        return ans;
    }
    
    void twoSum(vector<int>& nums, int i, int left, int right) {
        int x;
        while (left < right) {
            x = nums[i] + nums[left] + nums[right];
            if (x == 0) {
                ans.push_back(vector<int>({nums[i], nums[left], nums[right]}));
                ++left;
                --right;
                while (left < right && nums[left] == nums[left - 1]) ++left;
            }
            else if (x < 0) ++left;
            else --right;
        }
        return;
    }
};


int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};
    
    Solution sol;

    vector<vector<int>> ans = sol.threeSum(nums);

    for (auto &v: ans) {
        for (int &el: v) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}