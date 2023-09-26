//  1394. Find Lucky Integer in an Array
// https://leetcode.com/problems/find-lucky-integer-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> counter(501);
        for (const int& num: arr)
            ++counter[num];
        int ans = -1;
        for (int i = 500; i > 0; --i) {
            if (counter[i] == i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
