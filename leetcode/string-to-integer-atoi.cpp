// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int MX = numeric_limits<int>::max();
    int MN = numeric_limits<int>::min();
    
    int myAtoi(string s) {
        
        string::iterator leftIt = find_if_not(s.begin(), s.end(), [](char ch){
            return ch == ' ';
        });
        
        bool negative = *leftIt == '-' ? true : false;
        if (negative || *leftIt == '+') ++leftIt;
        leftIt = find_if_not(leftIt, s.end(), [](char ch){
            return ch == '0';
        });
        if (!isdigit(*leftIt)) return 0;
        int left = distance(s.begin(), leftIt);
        
        string::iterator rightIt = find_if_not(leftIt + 1, s.end(), [](char ch){
            return isdigit(ch);
        });
        int right = distance(s.begin(), rightIt);
        
        long ans = 0;
        long x = 1;
        
        int n = s.size();
        for (int i = left; i < right; ++i) {
            ans = ans * 10 + (s[i] - 48) ;
            if (ans > MX) {
                if (negative) return MN;
                else return MX;
            }
        }
        
        if (negative) ans = -ans;
            
        return ans;
    }
};
