// 966. Vowel Spellchecker
// https://leetcode.com/problems/vowel-spellchecker/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::transform;
using std::tolower;


class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (const string word: wordlist) {
            words.emplace(word);

            string low = GetLow(word);
            if (cap.find(low) == cap.end()) {
                cap[low] = word;
            }

            string wildcarded = WildcardVowels(low);
            if (vow.find(wildcarded) == vow.end()) {
                vow[wildcarded] = word;
            }
        }

        int q = queries.size();
        vector<string> ans(q);
        for (int i = 0; i < q; ++i) {
            ans[i] = GetWord(queries[i]);
        }
        return ans;
    }

private: 
    unordered_set<string> words;
    unordered_map<string, string> cap, vow;
    
    string GetWord(string s) {
        if (words.count(s)) {
            return s;
        }

        string low = GetLow(s);
        if (cap.count(low)) {
            return cap[low];
        }

        string wildcarded = WildcardVowels(low);
        if (vow.count(wildcarded)) {
            return vow[wildcarded];
        }

        return "";
    }

    string GetLow(string s) {
        std::transform(s.begin(), s.end(), s.begin(), 
            [](unsigned char ch){
                return std::tolower(ch);
            }
        );
        return s;
    }

    string WildcardVowels(string s) {
        string wildcarded;
        for (const char ch: s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||  ch == 'o' || ch == 'u') {
                wildcarded += '*';
            } else {
                wildcarded += ch;
            }
        }
        return wildcarded;
    }
};
