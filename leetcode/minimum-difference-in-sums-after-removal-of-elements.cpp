// 2163. Minimum Difference in Sums After Removal of Elements
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Priority Queue
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size() / 3;
        
        priority_queue<int> max_heap(nums.begin(), nums.begin() + n);
        long long sum = accumulate(nums.begin(), nums.begin() + n, 0LL);
        vector<long long> part1_sums(n + 1);
        part1_sums[0] = sum;
        for (int i = n; i < 2 * n; ++i) {
            sum += nums[i];
            max_heap.emplace(nums[i]);
            sum -= max_heap.top();
            max_heap.pop();
            part1_sums[i - (n - 1)] = sum;
        }

        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin() + 2 * n, nums.end());
        long long part2_sum = accumulate(nums.begin() + 2 * n, nums.end(), 0LL);
        long long ans = part1_sums[n] - part2_sum;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2_sum += nums[i];
            min_heap.emplace(nums[i]);
            part2_sum -= min_heap.top();
            min_heap.pop();
            ans = min(ans, part1_sums[i - n] - part2_sum);
        }
        return ans;
    }
};
