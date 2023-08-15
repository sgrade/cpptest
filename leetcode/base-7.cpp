// 504. Base 7
// https://leetcode.com/problems/base-7/

#include <bits/stdc++.h>

using namespace std;


// Idea is from https://leetcode.com/problems/base-7/solutions/3203216/c-solution-beats-100-runtime-0ms/
class Solution {
public:
    string convertToBase7(int num) {
        int base7 = 0, i = 0, rem;
        while (num != 0) {
            rem = num % 7;
            base7 = base7 + rem * pow(10, i++);
            num /= 7;
        }
        string ans = to_string(base7);
        return ans;
    }
};
