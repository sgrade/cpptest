// 1668. Maximum Repeating Substring
// https://leetcode.com/problems/maximum-repeating-substring/

#include <string>


class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {
        int ans = 0;
        int n = sequence.size(), w = word.size();
        for (int i = 0; i <= n - w; ++i) {
            int current_ans = 0;
            int pos = i;
            while (pos + w <= n && sequence.substr(pos, w) == word) {
                ++current_ans;
                pos += w;
            }
            ans = std::max(ans, current_ans);
        }
        return ans;
    }
};
