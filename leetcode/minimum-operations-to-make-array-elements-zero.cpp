// 3495. Minimum Operations to Make Array Elements Zero
// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/

#include <vector>
#include <algorithm>

using std::vector;
using std::min;


// Based on Editorial's Approach: Find Patterns + Bitwise Operation Statistics
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long operations = 0;
        for (const vector<int>& q: queries) {
            int left = q[0], right = q[1];
            operations += (getOperations(right) - getOperations(left - 1) + 1) / 2;
        }
        return operations;
    }

private:
    long long getOperations(int num) {
        int i = 1, base = 1;
        long long operations = 0;
        while (base <= num) {
            operations += 1LL * (i + 1) / 2 * (min(base * 2 - 1, num) - base + 1);
            ++i;
            base *= 2;
        }
        return operations;
    }
};
