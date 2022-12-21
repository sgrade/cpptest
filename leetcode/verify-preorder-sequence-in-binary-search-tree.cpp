// 255. Verify Preorder Sequence in Binary Search Tree
// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;


// Key logic is based on https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/solutions/68138/c-o-n-solution/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        vector<int>::iterator current_it = preorder.begin();
        Traverse(current_it, preorder.end(), numeric_limits<int>::min(), numeric_limits<int>::max());
        return (current_it == preorder.end());
    }
private:
    void Traverse(vector<int>::iterator &current_it, const vector<int>::iterator right, int mn, int mx) {
        if (current_it == right) {
            return;
        }
        int current_val = *current_it;
        if (current_val < mn || current_val > mx) {
            return;
        }
        ++current_it;
        Traverse(current_it, right, mn, current_val);
        Traverse(current_it, right, current_val, mx);
    }
};
