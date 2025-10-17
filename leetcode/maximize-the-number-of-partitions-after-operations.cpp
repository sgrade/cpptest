// 3003. Maximize the Number of Partitions After Operations
// https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;


// Based on Editorial's Maximize the Number of Partitions After Operations
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<vector<int>> prefix(n, vector<int>(3)), suffix(n, vector<int>(3));
        int splits = 0, mask = 0, distinct = 0;
        for (int i = 0; i < n - 1; ++i) {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary)) {
                ++distinct;
                if (distinct <= k) {
                    mask |= binary;
                } else {
                    ++splits;
                    mask = binary;
                    distinct = 1;
                }
            }
            prefix[i + 1][0] = splits;
            prefix[i + 1][1] = mask;
            prefix[i + 1][2] = distinct;
        }

        splits = 0, mask = 0, distinct = 0;
        for (int i = n - 1; i > 0; --i) {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary)) {
                ++distinct;
                if (distinct <= k) {
                    mask |= binary;
                } else {
                    ++splits;
                    mask = binary;
                    distinct = 1;
                }
            }
            suffix[i - 1][0] = splits;
            suffix[i - 1][1] = mask;
            suffix[i - 1][2] = distinct;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cur_splits = prefix[i][0] + suffix[i][0] + 2;
            int cur_mask = prefix[i][1] | suffix[i][1];
            int cur_distinct = 0;
            while (cur_mask) {
                cur_mask = cur_mask & (cur_mask - 1);
                ++cur_distinct;
            }
            if (prefix[i][2] == k && suffix[i][2] == k && cur_distinct < 26) {
                ++cur_splits;
            } else if (min(cur_distinct + 1, 26) <= k) {
                --cur_splits;
            }
            ans = max(ans, cur_splits);
        }
        return ans;
    }
};
