// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int n;
    vector<string> ans;
    map<char, string> letters = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                                     {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
                                     {'8', "tuv"}, {'9', "wxyz"}
                                    };
    
    vector<string> letterCombinations(string digits) {
        
        n = digits.size();
        ans.clear();
        
        if (n == 0) {
            return ans;
        }
        
        string combination;
        backtrack(digits, 0, combination);
        
        return ans;
    }
    
    void backtrack(const string& digits, int idx, string& combination) {
        // The combination is complete
        if (combination.size() == n) {
            ans.push_back(combination);
            return;
        }
                          
        string next_letters = letters[digits[idx]];
        for (int i = 0; i < next_letters.size(); ++i) {
            combination += next_letters[i];
            backtrack (digits, idx + 1, combination);
            // Remove the letter before backtracking
            combination.pop_back();
        }
    }
};


int main() {

    return 0;
}
