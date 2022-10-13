// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/

#include <bits/stdc++.h>

using namespace std;


// Idea is from https://leetcode.com/problems/wiggle-sort-ii/discuss/1840002/C%2B%2B-solution-using-priority-queue.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};
