// 2749. Minimum Operations to Make the Integer Zero
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/


// Based on Editorial's Approach: Enumeration
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int operations = 1;
        while (true) {
            long long rem = num1 - 1LL * (num2) * operations;
            if (operations > rem) {
                return -1;
            }
            if (operations >= __builtin_popcountll(rem)) {
                return operations;
            }
            ++operations;
        }
        return -1;
    }
};
