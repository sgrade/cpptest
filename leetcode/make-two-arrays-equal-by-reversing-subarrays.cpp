// 1460. Make Two Arrays Equal by Reversing Subarrays
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> counter (1001);
        for (const int& num: target)
            ++counter[num];
        for (const int& num: arr)
            --counter[num];
        int cnt = count (counter.begin(), counter.end(), 0);
        return cnt == 1001;
    }
};
