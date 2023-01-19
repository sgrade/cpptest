// 274. H-Index
// https://leetcode.com/problems/h-index/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach #2 (Counting)
//    improved by a trick from the submissions and my own
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counter(n + 1);
        for (const int& cit: citations) {
            ++counter[min(n, cit)];
        }
        int total = 0;
        for (int i = n; i >=0; --i) {
            total += counter[i];
            if (total >= i) return i;
        }
        return 0;
    }
};
