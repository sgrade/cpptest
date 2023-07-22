// 1929. Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};
