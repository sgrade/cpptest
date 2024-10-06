// 1813. Sentence Similarity III
// https://leetcode.com/problems/sentence-similarity-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Two Pointers
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string tmp;
        vector<string> v1, v2;

        stringstream iss(sentence1);
        while (iss >> tmp)
            v1.emplace_back(tmp);
        iss.clear();
        iss.str(sentence2);
        while (iss >> tmp)
            v2.emplace_back(tmp);

        int n1 = v1.size(), n2 = v2.size();
        if (n1 > n2) {
            swap(v1, v2);
            swap(n1, n2);
        }

        int left1 = 0, right1 = n1 - 1;
        int left2 = 0, right2 = n2 - 1;
        while (left1 < n1 && v1[left1] == v2[left2]) {
            ++left1;
            ++left2;
        }
        while (right1 >= 0 && v1[right1] == v2[right2]) {
            --right1;
            --right2;
        }
        return left1 > right1;
    }
};
