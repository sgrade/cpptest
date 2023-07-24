// 2011. Final Value of Variable After Performing Operations
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (const string &s: operations) {
            if (s == "--X" || s == "X--")
                --X;
            else
                ++X;
            
        }
        return X;
    }
};
