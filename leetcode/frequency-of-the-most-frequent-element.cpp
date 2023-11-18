// 1838. Frequency of the Most Frequent Element
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <bits/stdc++.h>

using namespace std;


// NOT FINISHED
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<long> d(n, 0L);
        for (int i = 1; i < n; ++i)
            d[i] = d[i - 1] + nums[i - 1] - nums[i];
        for (int i = 1; i < n; ++i)
            d[i] = d[i - 1] + d[i];
        int ans = 1, left = 0, right = 1, current_d;
        for (int right = 1; right < n; ++right) {
            current_d = d[right] - d[left];
            while (left < right && current_d > k) {
                ++left;
                current_d = d[right] - d[left];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
