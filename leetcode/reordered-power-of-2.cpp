// 869. Reordered Power of 2
// https://leetcode.com/problems/reordered-power-of-2/

#include <vector>


// Based on Editorial's Approach 2: Counting
// Checks if the digits of n can be reordered to form a power of 2.
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::vector<int> digits_of_n = GetDigits(n);
        for (int i = 0; i < 31; ++i) {
            int next_power_of_two = 1 << i;
            std::vector<int> digits_of_the_next = GetDigits(next_power_of_two);
            if (digits_of_n == digits_of_the_next) {
                return true;
            }
        }
        return false;
    }

 private:
    // Returns a vector counting the occurrences of each digit in n.
    std::vector<int> GetDigits(int n) {
        std::vector<int> digits(10);
        while (n > 0) {
            ++digits[n % 10];
            n /= 10;
        }
        return digits;
    }
};
