// 942. DI String Match
// https://leetcode.com/problems/di-string-match/

#include <vector>
#include <string>

using std::vector;
using std::string;


// Based on Editorial's Approach 1: Ad-Hoc
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(), left = 0, right = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[i] = left++;
            }
            else {
                ans[i] = right--;
            }
        }
        ans[n] = left;
        return ans;
    }
};
