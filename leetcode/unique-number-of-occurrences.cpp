// 1207. Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (const int& el: arr)
            ++counter[el];
        unordered_set<int> num_of_occurences;
        for (auto& [_, cnt]: counter)
            num_of_occurences.emplace(cnt);
        return counter.size() == num_of_occurences.size();
    }
};
