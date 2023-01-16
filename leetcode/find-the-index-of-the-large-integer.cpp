// 1533. Find the Index of the Large Integer
// https://leetcode.com/problems/find-the-index-of-the-large-integer/

#include <bits/stdc++.h>

using namespace std;


// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {
  public:
    // Compares the sum of arr[l..r] with the sum of arr[x..y] 
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y);

    // Returns the length of the array
    int length();
};

// Ideas are merged with Leetcode's Approach 1: Binary Search
class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int cmp;
        int len = reader.length();
        int l = 0, r, x, y;
        while (len > 1) {
            len /= 2;
            x = l + len;
            r = x - 1;
            y = x + len - 1;
            cmp = reader.compareSub(l, r, x, y);
            if (cmp == 0) {
                return y + 1;
            }
            else if (cmp < 0) {
                l = x;
            }
        }
        return l;
    }
};
