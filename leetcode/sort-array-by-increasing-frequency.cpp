// 1636. Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        sort(nums.begin(), nums.end(), [&](const int& num1, const int& num2){
            if (counter[num1] == counter[num2])
                return num1 > num2;
            return counter[num1] < counter[num2];
        });
        return nums;
    }
};
