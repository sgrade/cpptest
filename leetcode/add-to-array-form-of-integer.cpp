// 989. Add to Array-Form of Integer
// https://leetcode.com/problems/add-to-array-form-of-integer/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());

        vector<int> v_k;
        while (k > 0) {
            v_k.emplace_back(k % 10);
            k /= 10;
        }

        if (v_k.size() > num.size()) {
            swap(v_k, num);
        }

        int x, rem = 0;
        int i;
        for (i = 0; i < v_k.size(); ++i) {
            x = rem + num[i] + v_k[i];
            num[i] = x % 10;
            rem = x / 10;
        }

        while (i < num.size() && rem > 0) {
            x = rem + num[i];
            num[i] = x % 10;
            rem = x / 10;
            ++i;
        }

        if (rem != 0) {
            if (i == num.size()) {
                num.emplace_back(1);
            }
        }

        reverse(num.begin(), num.end());

        return num;
    }
};
