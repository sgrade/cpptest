// 1356. Sort Integers by The Number of 1 Bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Sort By Custom Comparator: Built-in
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int& a, int& b){
            if (__builtin_popcount(a) == __builtin_popcount(b))
                return a < b;
            return __builtin_popcount(a) < __builtin_popcount(b);
        });
        return arr;
    }
};
