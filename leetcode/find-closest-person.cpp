// 3516. Find Closest Person
// https://leetcode.com/problems/find-closest-person/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int findClosest(int x, int y, int z) {
            int dx = abs(x - z), dy = abs(y - z);
            if (dx == dy)
                return 0;
            else if (dx < dy)
                return 1;
            else
                return 2;
        }
    };
