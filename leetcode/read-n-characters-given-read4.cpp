// 157. Read N Characters Given Read4
// https://leetcode.com/problems/read-n-characters-given-read4/

#include <bits/stdc++.h>

using namespace std;


// The read4 API is defined in the parent class Reader4.
int read4(char *buf4);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total_chars = 0;
        int read_chars = 4;
        int remaining_chars = n;
        
        while (remaining_chars >= 4 && read_chars == 4) {
            read_chars = read4(buf + total_chars);
            total_chars += read_chars;
        }
        
        if (remaining_chars && read_chars) {
            char buf4[4];
            read_chars = read4(buf4);
            for (int i = 0; i < min(remaining_chars, read_chars); ++i) {
                buf[total_chars++] = buf4[i];
            }
        }
        
        return min(n, total_chars);
    }
};
