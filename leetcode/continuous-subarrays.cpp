// 2762. Continuous Subarrays
// https://leetcode.com/problems/continuous-subarrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans = 0;
        int left = 0, right = 0;
        multiset<int> st;
        while (right < nums.size()) {
            st.emplace(nums[right]);
            while (*st.rbegin() - *st.begin() > 2) {
                int num = nums[left++];
                st.erase(st.find(num));
            }
            ans += right - left + 1;
            ++right;
        }
        return ans;
    }
};
