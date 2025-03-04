// 1780. Check if Number is a Sum of Powers of Three
// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

#include <bits/stdc++.h>

using namespace std;


// Approach 3: Ternary Representation
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n > 0) {
                if (n % 3 == 2)
                    return false;
                n /= 3;
            }
            return true;
        }
    };
