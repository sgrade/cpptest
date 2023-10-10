// 1999. Smallest Greater Multiple Made of Two Digits
// https://leetcode.com/problems/smallest-greater-multiple-made-of-two-digits/

#include <bits/stdc++.h>

using namespace std;


// CANNOT CHECK: when I run the code, it returns correct results, but leetcode expected output is empty. It seems that something is broken in leetcode.
class Solution {
public:
    int findInteger(int k, int digit1, int digit2) {
        if (digit1 == 0 && digit2 == 0)
            return -1;
        if (digit1 == digit2 && k == digit1)
            return k;
        if (digit1 > digit2)
            swap(digit1, digit2);
        queue<int> q;
        q.emplace(digit1);
        q.emplace(digit2);
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            if (!NextDigitOverflow(d, digit1)) {
                int x1 = d * 10 + digit1;
                if (x1 > k && x1 % k == 0)
                    return x1;
                q.emplace(x1);
            }
            if (!NextDigitOverflow(d, digit2)) {
                int x2 = d * 10 + digit2;
                if (x2 > k && x2 % k == 0)
                    return x2;
                q.emplace(x2);
            }

        }
        return -1;
    }
private:
    bool NextDigitOverflow (int n, int digit) {
        if ((n > INT_MAX / 10) || (n == INT_MAX / 10 && digit > INT_MAX % 10))
            return true;
        return false;
    }
};
