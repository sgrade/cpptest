// 18. 4Sum
// https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Hash Set
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k) {
        vector<vector<int>> ans;
        
        if (start == nums.size()) {
            return ans;
        }
        
        long long average = target / k;
        if (nums[start] > average || average > nums.back()) {
            return ans;
        }
        
        if (k == 2) {
            return twoSum(nums, target, start);
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i-1] != nums[i]) {
                for (vector<int> &v: kSum(nums, target - nums[i], i + 1, k - 1)) {
                    ans.emplace_back(vector<int>{nums[i]});
                    ans.back().insert(ans.back().end(), v.begin(), v.end());
                }
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> twoSum(vector<int> &nums, long long target, int start) {
        vector<vector<int>> ans;
        set<long long> st;
        
        for (int i = start; i < nums.size(); ++i) {
            if (ans.empty() || ans.back()[1] != nums[i]) {
                if (st.find(target - nums[i]) != st.end()) {
                    ans.emplace_back(vector<int>{int(target - nums[i]), nums[i]});
                }
            }
            st.insert(nums[i]);
        }
        
        return ans;
    }
};
