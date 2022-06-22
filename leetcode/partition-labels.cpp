// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i]] = i;
        }
        int j = 0, anchor = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            j = max(j, last[s[i]]);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};
