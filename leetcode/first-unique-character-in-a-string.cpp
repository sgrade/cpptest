// https://leetcode.com/problems/first-unique-character-in-a-string/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (char &ch: s) {
            ++mp[ch];
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (mp[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};


int main() {

  Solution sol;
  
  string s;
  cin >> s;

  int ans = sol.firstUniqChar(s);

  cout << ans << endl;

}
