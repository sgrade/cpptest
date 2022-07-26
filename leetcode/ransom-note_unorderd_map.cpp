// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need, have;
        for (int i = 0; i < ransomNote.size(); ++i) {
            ++need[ransomNote[i]];
        }
        for (int i = 0; i < magazine.size(); ++i) {
            ++have[magazine[i]];
        }
        bool ans = true;
        for (auto &[ch, count]: need) {
            if (have[ch] < count) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
