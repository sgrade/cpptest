// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> need(26);
        for (int i = 0; i < ransomNote.size(); ++i) {
            ++need[ransomNote[i] - 97];
        }
        for (int i = 0; i < magazine.size(); ++i) {
            --need[magazine[i] - 97];
        }
        bool ans = true;
        for (int i = 0; i < 26; ++i) {
            if (need[i] > 0) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};

