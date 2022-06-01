// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    int ans;
    int minDiff = INT_MAX, currentDiff;
    int n;  // nums lenght
    int t;  // target
    int x;  // current sum
    
    void twoSum(vector<int>& nums, int i) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            x = nums[i] + nums[left] + nums[right];
            currentDiff = abs(t - x);
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                ans = x;
            }
            if (x < t) ++left;
            else --right;
        }
        return;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        t = target;
        sort(nums.begin(), nums.end());
        n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            twoSum(nums, i);
        }
        return ans;
    }
};


int main() {



    return 0;
}
