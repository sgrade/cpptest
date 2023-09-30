// 456. 132 Pattern
// https://leetcode.com/problems/132-pattern/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Stack
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        stack<int> st;
        vector<int> min_array(n);
        min_array[0] = nums[0];
        for (int i = 1; i < n; ++i) 
            min_array[i] = min(min_array[i - 1], nums[i]);
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] <= min_array[i])
                continue;
            while (!st.empty() && st.top() <= min_array[i])
                st.pop();
            if (!st.empty() && st.top() < nums[i])
                return true;
            st.emplace(nums[i]);
        }
        return false;
    }
};
