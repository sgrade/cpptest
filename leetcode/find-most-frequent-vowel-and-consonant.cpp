// 3541. Find Most Frequent Vowel and Consonant
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/

#include <vector>
#include <set>
#include <string>
#include <algorithm>

using std::vector;
using std::set;
using std::string;
using std::max;


class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> counter(26);
        for (const char ch: s) {
            ++counter[ch - 'a'];
        }
        int vowel_freq = 0, consonant_freq = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 26; ++i) {
            if (vowels.count('a' + i)) {
                vowel_freq = max(vowel_freq, counter[i]);
            } else {
                consonant_freq = max(consonant_freq, counter[i]);
            }
        }
        return vowel_freq + consonant_freq;
    }
};
