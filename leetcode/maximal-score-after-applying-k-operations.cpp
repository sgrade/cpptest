// 2530. Maximal Score After Applying K Operations
// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(nums.begin(), nums.end(), greater<int>());
        priority_queue<int> pq;
        int n = min(k, (int)nums.size());
        for (int i = 0; i < n; ++i)
            pq.emplace(nums[i]);

        long long score = 0;
        while (k) {
            int current = pq.top();
            pq.pop();
            if (current == 1) {
                score += k;
                break;
            }
            --k;
            score += current;
            current = current / 3 + (current % 3 != 0);
            pq.emplace(current);
        }

        return score;
    }
};
