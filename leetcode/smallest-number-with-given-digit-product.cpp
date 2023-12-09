// 2847. Smallest Number With Given Digit Product
// https://leetcode.com/problems/smallest-number-with-given-digit-product/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/smallest-number-with-given-digit-product/solutions/4011973/c-python3-4ms-greedy-try-from-9-to-2/
class Solution {
public:
    string smallestNumber(long long n) {
        if (n == 1)
            return "1";
        string ans;
        for (int i = 9; i > 1; --i) {
            while (n % i == 0) {
                ans += to_string(i);
                n /= i;
            }
        }
        if (n != 1)
            return "-1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
