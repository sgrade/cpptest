// 3345. Smallest Divisible Digit Product I
// https://leetcode.com/problems/smallest-divisible-digit-product-i/

class Solution {
 public:
  int smallestNumber(int n, int t) {
    while (digitProduct(n) % t != 0) {
      ++n;
    }
    return n;
  }

 private:
  int digitProduct(int x) {
    int product = 1;
    for (; x > 0; x /= 10) {
      product *= x % 10;
    }
    return product;
  }
};
