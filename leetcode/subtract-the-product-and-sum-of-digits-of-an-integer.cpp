// 1281. Subtract the Product and Sum of Digits of an Integer
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/


class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        string s = to_string(n);
        for (const char ch: s) {
            int digit = ch - '0';
            sum += digit;
            product *= digit;
        }
        return product - sum;
    }
};
