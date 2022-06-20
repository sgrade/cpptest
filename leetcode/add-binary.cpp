// 67. Add Binary
// https://leetcode.com/problems/add-binary/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            return addBinary(b, a);
        }
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ans;
        for (; i >= 0; --i) {
            if (a[i] == '1') ++carry;
            if (j > -1 && b[j--] == '1') ++carry;
            if (carry % 2 == 0) {
                ans += '0';
            }
            else {
                ans += '1';
            }
            carry /= 2;
        }
        if (carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
