// 1935. Maximum Number of Words You Can Type
// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

#include <string>
#include <sstream>

using std::string;
using std::istringstream;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        string word;
        istringstream iss(text);
        while (iss >> word) {
            if (word.find_first_of(brokenLetters) == string::npos) {
                ++ans;
            }
        }
        return ans;
    }
};
