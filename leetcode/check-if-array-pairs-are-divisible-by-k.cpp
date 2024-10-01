// 1497. Check If Array Pairs Are Divisible by k
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Hashing / Counting
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> counter;
        for (const int& num: arr)
            ++counter[(num % k + k) % k];
        for (const int& num: arr) {
            int rem = (num % k + k) % k;
            if (rem == 0) {
                if (counter[rem] % 2 == 1)
                    return false;
            }
            else if (counter[rem] != counter[k - rem])
                return false;
        }
        return true;
    }
};
