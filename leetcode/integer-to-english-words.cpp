// https://leetcode.com/problems/integer-to-english-words/


#include <bits/stdc++.h>

using namespace std;


class Solution {
    
public:
    
    vector<string> ans;
    
    map<int, string> m1 = {{0, "zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};

    map<int, string> m10 = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};

    map<int, string> m100 = {{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
    
    string numberToWords(int num) { 
                               
        if (num == 0) return "Zero";

        int x = num;
        
        if (x / 1000000000 > 0) {
            parseTriple(x / 1000000000);
            ans.push_back("Billion");
        }
        x %= 1000000000;
               
        if (x / 1000000 > 0) {
            parseTriple(x / 1000000);
            ans.push_back("Million");
        }
        x %= 1000000;
        
        if (x / 1000 > 0) {
            parseTriple(x / 1000);
            ans.push_back("Thousand");
        }
        x %= 1000;
        
        parseTriple(x);
        
        string output;
        for (int i = 0; i < ans.size() - 1; ++i) {
            output += ans[i] + ' ';
        }
        output += *ans.rbegin();
        return output;
    }
    
    void parseTriple(int x) {
        
        if (x / 100 > 0) {
            pushNumber(x / 100);
            ans.push_back("Hundred");
        }
        x %= 100;
        
        if (x > 19) {
            pushNumber(x - x % 10);
            x %= 10;
        }
        
        pushNumber(x);
        
    }
    
    void pushNumber(const int &rem) {
        
        if (0 < rem && rem < 10) {
            ans.push_back(m1[rem]);
        }
        else if (9 < rem && rem < 20) {
            ans.push_back(m10[rem]);
        }
        else if (19 < rem && rem < 100) {
            ans.push_back(m100[rem]);
        }
        return;
    }
};


int main() {

  Solution sol;
  
  int n;
  cin >> n;

  string s = sol.numberToWords(n);

  cout << s << endl;

}
