// 3356. Zero Array Transformation II
// https://leetcode.com/problems/zero-array-transformation-ii/

#include <bits/stdc++.h

using namespace std;


// Based on Editorial's Approach 2: Line Sweep
class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size(), q = queries.size(), sum = 0, ans = 0;
            vector<int> diffs(n + 1);
            for (int i = 0; i < n; ++i) {
                while (sum + diffs[i] < nums[i]) {
                    ++ans;
                    if (ans > q)
                        return -1;
                    int left = queries[ans - 1][0], right = queries[ans - 1][1], val = queries[ans - 1][2];
                    if (right >= i) {
                        diffs[max(left, i)] += val;
                        diffs[right + 1] -= val;
                    }
                }
                sum += diffs[i];
            }
            return ans;
        }
    };
