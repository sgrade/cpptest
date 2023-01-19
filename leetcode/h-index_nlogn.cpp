// 274. H-Index
// https://leetcode.com/problems/h-index/

#include <bits/stdc++.h>

using namespace std;


// SLOW
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (citations[i] > i) {
                h = max(h, i + 1);
            }
        }
        return h;
    }
};
