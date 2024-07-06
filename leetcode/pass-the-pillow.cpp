// 2582. Pass the Pillow
// https://leetcode.com/problems/pass-the-pillow/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int passThePillow(int n, int time) {
        int times = time / (n - 1);
        int rem = time % (n - 1);
        if (times % 2 == 0)
            return 1 + rem;
        return n - rem;
    }
};
