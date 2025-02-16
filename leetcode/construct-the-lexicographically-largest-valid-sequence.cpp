// 1718. Construct the Lexicographically Largest Valid Sequence
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Backtracking
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        this->n = n, sz = n * 2 - 1;
        ans.resize(sz), used.resize(n + 1);
        getSequence(0);
        return ans;
    }

private:
    int n, sz;
    vector<int> ans;
    vector<bool> used;
    bool getSequence(int i) {
        if (i == sz)
            return true;
        if (ans[i] != 0)
            return getSequence(i + 1);
        for (int num = n; num >= 1; --num) {
            if (used[num])
                continue;
            used[num] = true;
            ans[i] = num;
            if (num == 1) {
                if (getSequence(i + 1))
                    return true;
            }
            else if (i + num < sz && ans[i + num] == 0) {
                ans[i + num] = num;
                if (getSequence(i + 1))
                    return true;
                // backtrack
                ans[i + num] = 0;
            }

            // backtrack
            ans[i] = 0;
            used[num] = false;
        }
        
        return false;
    }
};
