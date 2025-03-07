// 2523. Closest Prime Numbers in Range
// https://leetcode.com/problems/closest-prime-numbers-in-range/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Analyze Distance between twin primes
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int prev = -1, num1 = -1, num2 = -1, min_diff = 1e6;
            int x = left;
            for (; x <= right; ++x) {
                if (isPrime(x)) {
                    prev = x++;
                    break;
                }
            }
            for (; x <= right; ++x) {
                if (isPrime(x)) {
                    int diff = x - prev;
                    if (diff < min_diff) {
                        min_diff = diff;
                        num1 = prev;
                        num2 = x;
                    }
                    if (diff == 1 || diff == 2)
                        return {prev, x};
                    prev = x;
                }
            }
            return {num1, num2};
        }

    private:
        bool isPrime (int num) {
            if (num < 2)
                return false;
            if (num == 2 || num == 3)
                return true;
            if (num % 2 == 0)
                return false;
            for (int divisor = 3; divisor * divisor <= num; divisor += 2) {
                if (num % divisor == 0)
                    return false;
            }
            return true;
        }
    };
