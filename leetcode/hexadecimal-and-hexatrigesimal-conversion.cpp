// 3602. Hexadecimal and Hexatrigesimal Conversion
// https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/solutions/6924204/simple-maths
class Solution {
public:
    string concatHex36(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for (int i = 0; i < 10; ++i)
            chars[i] = i + '0';
        for (int i = 10; i < 36; ++i)
            chars[i] = i - 10 + 'A';

        int n2 = n * n, n3 = n2 * n;
        string ans;
        while (n2) {
            int rem = n2 % 16;
            ans = chars[rem] + ans;
            n2 /= 16;
        }

        string ans36 = "";
        while (n3) {
            int rem = n3 % 36;
            ans36 = chars[rem] + ans36;
            n3 /= 36;
        }

        return ans + ans36;
    }
private:
    unordered_map<int, char> chars;
};
