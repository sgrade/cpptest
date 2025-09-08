// 1317. Convert Integer to the Sum of Two No-Zero Integers
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

#include <vector>

using std::vector;


class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int num1 = 1; num1 < n / 2 + 1; ++num1) {
            if (FindZeroes(num1)) {
                continue;
            }
            int num2 = n - num1;
            if (!FindZeroes(num2)) {
                return {num1, num2};
            }
        }
        return {-1, -1};
    }
private:
    bool FindZeroes (int num) {
        int rem;
        while (num) {
            rem = num % 10;
            if (rem == 0) {
                return true;
            }
            num /= 10;
        }
        return false;
    }
};
