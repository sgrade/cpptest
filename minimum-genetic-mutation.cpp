// 433. Minimum Genetic Mutation
// https://leetcode.com/problems/minimum-genetic-mutation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: BFS (Breadth-First Search)
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> visited;
        q.emplace(startGene);
        visited.emplace(startGene);

        int steps = 0;
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; ++i) {
                string node = q.front();
                q.pop();
                if (node == endGene)
                    return steps;
                
                for (char ch: "ACGT") {
                    for (int j = 0; j < node.size(); ++j) {
                        string candidate = node;
                        candidate[j] = ch;
                        if (visited.find(candidate) == visited.end() && 
                            find(bank.begin(), bank.end(), candidate) != bank.end()
                            ) {
                                q.emplace(candidate);
                                visited.emplace(candidate);
                            }
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
