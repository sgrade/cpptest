// 2485. Find the Pivot Integer
// https://leetcode.com/problems/find-the-pivot-integer/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 5: Using Math
class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        int ans = sqrt(sum);
        return ans * ans == sum ? ans : - 1;
    }
};
