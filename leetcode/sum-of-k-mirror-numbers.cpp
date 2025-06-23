// 2081. Sum of k-Mirror Numbers
// https://leetcode.com/problems/sum-of-k-mirror-numbers/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/sum-of-k-mirror-numbers/solutions/6873949/beginner-freindly-java-c-python

using ll = long long;

class Solution {
public:
    ll kMirror(int k, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ll ans = 0;
        for (ll len = 1; n > 0; len *= 10) {
            for (ll seed = len; n > 0 && seed < len * 10; ++seed) {
                ll odd_len_p = getPalindrome(seed, true);
                if (isPalindrome(odd_len_p, k)) {
                    ans += odd_len_p;
                    --n;
                }
            }
            for (ll seed = len; n > 0 && seed < len * 10; ++seed) {
                ll even_len_p = getPalindrome(seed, false);
                if (isPalindrome(even_len_p, k)) {
                    ans += even_len_p;
                    --n;
                }
            }
        }
        return ans;
    }

private:
    ll getPalindrome (ll num, bool odd) {
        ll right = num;
        if (odd)
            right /= 10;
        while (right) {
            num = num * 10 + right % 10;
            right /= 10;
        }
        return num;
    }

    bool isPalindrome(ll num, int base) {
        vector<int> digits;
        while (num > 0) {
            digits.emplace_back(num % base);
            num /= base;
        }
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left++] != digits[right--])
                return false;
        }
        return true;
    }
};
