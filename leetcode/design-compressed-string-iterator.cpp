// 604. Design Compressed String Iterator
// https://leetcode.com/problems/design-compressed-string-iterator/

#include <bits/stdc++.h>

using namespace std;


class StringIterator {
public:
    StringIterator(string compressedString) {
        s = compressedString;
    }
    
    char next() {
        if (cnt > 0) {
            --cnt;
            return s[idx];
        }
        if  (next_idx == s.size())
            return ' ';
        cnt = 0;
        idx = next_idx;
        ++next_idx;
        while (isdigit(s[next_idx]))
            cnt = cnt * 10 + (s[next_idx++] - '0');
        --cnt;
        return s[idx];
    }
    
    bool hasNext() {
        return cnt > 0 || next_idx < s.size();
    }

private:
    string s;
    int idx = 0, cnt = 0, next_idx = 0;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 