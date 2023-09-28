// 905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& x, const int& y){
            return x % 2 < y % 2;
        });
        return move(nums);
    }
};
