// 717. 1-bit and 2-bit Characters
// https://leetcode.com/problems/1-bit-and-2-bit-characters/

#include <bits/stdc++.h>

using namespace std;


// The idea is from https://leetcode.com/problems/1-bit-and-2-bit-characters/solutions/3424317/solution-in-c/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1)
            return true;
        if (bits[bits.size() - 2] == 0)
            return true;
        return distance(find(bits.rbegin() + 1, bits.rend(), 0), bits.rbegin()) % 2;
    }
};
