// 326. Power of Three
// https://leetcode.com/problems/power-of-three/

// Based on Editorial's Approach 4: Integer Limitations
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

