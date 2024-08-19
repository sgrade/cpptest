// 650. 2 Keys Keyboard
// https://leetcode.com/problems/2-keys-keyboard/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Prime Factorization
class Solution {
public:
    int minSteps(int n) {
        int ans = 0, factor = 2;
        while (n > 1) {
            while (n % factor == 0) {
                ans += factor;
                n /= factor;
            }
            ++factor;
        }
        return ans;
    }
};
