// 1342. Number of Steps to Reduce a Number to Zero
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0) {
            if (num % 2 == 0) 
                num /= 2;
            else 
                --num;
            ++ans;
        }
        return ans;
    }
};
