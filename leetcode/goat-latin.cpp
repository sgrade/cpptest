// 824. Goat Latin
// https://leetcode.com/problems/goat-latin/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        unordered_set<char> vowels = {'a','A','e','E','i','I','o','O','u','U'};
        
        stringstream sstream(sentence);
        string word;
        int i = 1;
        while (sstream >> word) {
            string tmp;
            if (word.size() == 1) {
                tmp += word;
            }
            else {
                if (vowels.find(word[0]) == vowels.end()) {
                    tmp += word.substr(1, word.size() - 1);
                    tmp += word[0];
                }
                else {
                    tmp += word;
                }
            }
            tmp += "ma";
            for (int j = 0; j < i; ++j) {
                tmp += 'a';
            }
            ++i;
            tmp += ' ';
            ans += tmp;
        }
        ans.pop_back();
        return ans;
    }
};


int main() {

    Solution sol;
    string s;
    
    s = "I speak Goat Latin";
    string ans = sol.toGoatLatin(s);
    cout << ans << endl;
    assert(("Test 1: ", ans == "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"));
    
    s = "The quick brown fox jumped over the lazy dog";
    ans = sol.toGoatLatin(s);
    cout << ans << endl;
    assert(ans == "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa");

    return 0;
}
