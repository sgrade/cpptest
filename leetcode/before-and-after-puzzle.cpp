// 1181. Before and After Puzzle
// https://leetcode.com/problems/before-and-after-puzzle/

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;


// Based on Editorial's Approach: Hash Table + Sorting
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        vector<pair<string, string>> words;
        for (const string& phrase: phrases) {
            size_t pos = phrase.find(' ');
            string first = phrase.substr(0, pos);
            pos = phrase.find_last_of(' ');
            string last = pos == string::npos? phrase : phrase.substr(pos + 1);
            words.emplace_back(first, last);
        }
        
        unordered_set<string> output;
        for (int i = 0; i < phrases.size(); ++i) {
            for (int j = 0; j < phrases.size(); ++j) {
                if (i == j) continue;
                if (words[i].first == words[j].second) {
                    size_t pos = words[i].first.size();
                    string current = phrases[j] + phrases[i].substr(pos);
                    output.emplace(current);
                }
            }
        }

        vector<string> ans(output.begin(), output.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
