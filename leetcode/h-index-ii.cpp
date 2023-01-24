// 275. H-Index II
// https://leetcode.com/problems/h-index-ii/

#include <bits/stdc++.h>

using namespace std;


// The optmimizations are based on one of the Leetcode's accepted solutions
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = citations.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (citations[mid] == n - mid) {
                return citations[mid];
            }
            else if (citations[mid] > n - mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};
