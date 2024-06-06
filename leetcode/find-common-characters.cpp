// 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> reference(26);
        for (int i = 0; i < words[0].size(); ++i) {
            const char& ch = words[0][i];
            ++reference[ch - 'a'];
        }

        for (int i = 1; i < n; ++i) {
            vector<int> current(26);
            for (int j = 0; j < words[i].size(); ++j) {
                const char& ch = words[i][j];
                ++current[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i)
                reference[i] = min(reference[i], current[i]);
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            if (reference[i] > 0) {
                int ascii_value = 97 + i;
                string s = string(1, ascii_value);
                cout << s << endl;
                for (int j = 0; j < reference[i]; ++j)
                    ans.emplace_back(s);
            }
        }
        return ans;
    }
};
