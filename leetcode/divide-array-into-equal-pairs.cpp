// 2206. Divide Array Into Equal Pairs
// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            if (nums.size() % 2 != 0)
                return false;
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); i += 2) {
                if (nums[i] != nums[i - 1])
                    return false;
            }
            return true;
        }
    };
