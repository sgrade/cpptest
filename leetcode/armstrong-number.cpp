// 1134. Armstrong Number
// https://leetcode.com/problems/armstrong-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isArmstrong(int n) {
        bool ans = true;
        int tmp = n, rem;
        vector<int> a;
        while (tmp > 0) {
            rem = tmp % 10;
            a.push_back(rem);
            tmp /= 10;
        }
        int N = a.size();
        long long sm = 0;
        for (int &digit: a) {
            tmp = digit;
            for (int i = 1; i < N; ++i) {
                digit *= tmp;
            }
            sm += digit;
            if (sm > n) {
                ans = false;
                break;
            }
        }
        if (sm != n) ans = false;
        return ans;
    }
};
