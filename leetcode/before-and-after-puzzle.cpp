// 1181. Before and After Puzzle
// https://leetcode.com/problems/before-and-after-puzzle/


#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>



// Based on Editorial's Approach: Hash Table + Sorting
class Solution {
 public:
    std::vector<std::string> beforeAndAfterPuzzles(std::vector<std::string>& phrases) {
        int n = phrases.size();
        std::vector<std::string> first_words(n), last_words(n);
        std::unordered_multimap<std::string, int> last_to_idx;
        for (int i = 0; i < n; ++i) {
            const std::string& phrase = phrases[i];
            size_t pos_first = phrase.find(' ');
            first_words[i] = phrase.substr(0, pos_first);
            size_t pos_last = phrase.find_last_of(' ');
            last_words[i] = (pos_last == std::string::npos) ? phrase : phrase.substr(pos_last + 1);
            last_to_idx.emplace(last_words[i], i);
        }

        std::unordered_set<std::string> output;
        for (int i = 0; i < n; ++i) {
            auto range = last_to_idx.equal_range(first_words[i]);
            for (auto it = range.first; it != range.second; ++it) {
                int j = it->second;
                if (i == j) continue;
                size_t pos = first_words[i].size();
                std::string current = phrases[j] + phrases[i].substr(pos);
                output.emplace(current);
            }
        }

        std::vector<std::string> ans(output.begin(), output.end());
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};
