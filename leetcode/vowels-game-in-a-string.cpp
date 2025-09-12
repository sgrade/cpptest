// 3227. Vowels Game in a String
// https://leetcode.com/problems/vowels-game-in-a-string/

#include <string>

using std::string;


class Solution {
public:
    bool doesAliceWin(string s) {
        return s.find_first_of("aeiou") != string::npos;
    }
};
