// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Nested Prefix XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size() + 1;
        vector<int> prefix(n);
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] ^ arr[i - 1];

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefix[i] == prefix[k]) {
                    ans += k - i - 1;
                }
            }
        }
        return ans;
    }
};
