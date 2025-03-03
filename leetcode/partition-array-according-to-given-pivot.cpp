// 2161. Partition Array According to Given Pivot
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            
            vector<int> before, after;
            int pivots = 0;
            for (const int& num: nums) {
                if (num < pivot)
                    before.emplace_back(num);
                else if (num > pivot)
                    after.emplace_back(num);
                else
                    ++pivots;
            }
            for (int i = 0; i < pivots; ++i)
                before.emplace_back(pivot);
            before.insert(before.end(), after.begin(), after.end());
            return before;
        }
    };
