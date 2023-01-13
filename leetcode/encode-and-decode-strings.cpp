// 271. Encode and Decode Strings
// https://leetcode.com/problems/encode-and-decode-strings/

#include <bits/stdc++.h>

using namespace std;


// The idea is from Leetcode's Approach 2: Chunked Transfer Encoding
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded, len;
        for (const string& s: strs) {
            len = to_string(s.size());
            for (int i = 0; i < 4 - len.size(); ++i) {
                encoded += '0';
            }
            encoded += len;
            encoded += s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int idx = 0, len;
        while (idx < s.size()) {
            len = stoi(s.substr(idx, 4));
            ans.emplace_back(s.substr(idx + 4, len));
            idx += 4 + len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
