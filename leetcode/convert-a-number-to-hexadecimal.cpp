// 405. Convert a Number to Hexadecimal
// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/convert-a-number-to-hexadecimal/solutions/437513/c-beats-100-no-bit-manipulation-with-explanation
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int x = num;
        const char chars[] = "0123456789abcdef";
        string ans;
        ans.reserve(8); // Max 8 hex digits for 32-bit int
        
        while (x) {
            ans = chars[x & 15] + ans;  // Prepend to avoid reverse()
            x >>= 4;
        }
        
        return ans;
    }
};
