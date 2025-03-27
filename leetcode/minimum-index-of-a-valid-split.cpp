// 2780. Minimum Index of a Valid Split
// https://leetcode.com/problems/minimum-index-of-a-valid-split/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size(), ans = 0, dom = -1;
            unordered_map<int, int> counter;
            for (const int& num: nums)
                ++counter[num];
            for (const auto& [x, cnt]: counter) {
                if (cnt > n / 2) {
                    dom = x;
                    break;
                }
            }

            int cnt = counter[dom], cnt_left = 0, cnt_right = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == dom) {
                    ++cnt_left;
                    cnt_right = cnt - cnt_left;
                    if (cnt_left * 2 > i + 1 &&
                        cnt_right * 2 > n - i - 1)
                    return i;
                }
            }
            return -1;
        }
    };
