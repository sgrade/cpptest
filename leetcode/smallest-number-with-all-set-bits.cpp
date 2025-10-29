// 3370. Smallest Number With All Set Bits
// https://leetcode.com/problems/smallest-number-with-all-set-bits/


class Solution {
public:
    int smallestNumber(int n) {
        int bit_cnt = 0;
        while (n) {
            ++bit_cnt;
            n >>= 1;
        }
        int ans = 1;
        for (int i = 0; i < bit_cnt; ++i) {
            ans <<= 1;
        }
        ans -= 1;
        return ans;
    }
};
