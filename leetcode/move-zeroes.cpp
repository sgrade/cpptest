// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int x){
            return x != 0;
        });
    }
};
