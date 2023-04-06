// 1656. Design an Ordered Stream
// https://leetcode.com/problems/design-an-ordered-stream/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from Leetcode's Sample 90 ms submission
class OrderedStream {
public:
    OrderedStream(int n) {
        chunks.resize(n + 1);
        idx = 1;
    }
    vector<string> insert(int idKey, string value) {
        chunks[idKey] = value;
        vector<string> largest;
        while (idx < chunks.size() && !chunks[idx].empty())
            largest.emplace_back(chunks[idx++]);
        return largest;
    }
private:
    vector<string> chunks;
    int idx;
};
