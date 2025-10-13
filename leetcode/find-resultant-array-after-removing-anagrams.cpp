// 2273. Find Resultant Array After Removing Anagrams
// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;


class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            int j = i + 1;
            while (j < words.size()) {
                string w1 = words[i], w2 = words[j];
                if (w1.size() != w2.size()) {
                    break;
                }
                sort(w1.begin(), w1.end());
                sort(w2.begin(), w2.end());
                if (w1 == w2) {
                    ++j;
                }
                else {
                    break;
                }
            }
            ans.emplace_back(words[i]);
            i = j;
        }
        return ans;
    }
};
