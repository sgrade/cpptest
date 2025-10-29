// 3370. Smallest Number With All Set Bits
// https://leetcode.com/problems/smallest-number-with-all-set-bits/


class Solution {
public:
    int smallestNumber(int n) {
        return (1 << std::bit_width((unsigned)n)) - 1;
    }
};
