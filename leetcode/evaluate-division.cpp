// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Path Search in Graph
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> equation = equations[i];
            string dividend = equation[0], divisor = equation[1];
            double quotient = values[i];

            if (graph.find(dividend) == graph.end())
                graph.emplace(dividend, unordered_map<string, double>());
            if (graph.find(divisor) == graph.end())
                graph.emplace(divisor, unordered_map<string, double>());
            
            graph[dividend].emplace(divisor, quotient);
            graph[divisor].emplace(dividend, 1 / quotient);
        }

        // Process the queries
        int q = queries.size();
        vector<double> ans(q);
        for (int i = 0; i < queries.size(); ++i) {
            vector<string>& query = queries[i];
            string dividend = query[0], divisor = query[1];

            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()) 
                ans[i] = -1.0;
            else if (dividend == divisor)
                ans[i] = 1.0;
            else {
                unordered_set<string> visited;
                ans[i] = backtrack(dividend, divisor, 1, visited);
            }
        }

        return ans;
    }

private:
    unordered_map<std::string, unordered_map<string, double>> graph;

    double backtrack(std::string current_node, string target_node, double product, unordered_set<string>& visited) {
        visited.emplace(current_node);
        double current_ans = -1.0;

        unordered_map<std::string, double>& neighbors = graph[current_node];
        if (neighbors.find(target_node) != neighbors.end())
            current_ans = product * neighbors[target_node];
        else {
            for (auto& [next_node, value] : neighbors) {
                if (visited.find(next_node) != visited.end())
                    continue;
                current_ans = backtrack(next_node, target_node, product * value, visited);
                if (current_ans != -1.0)
                    break;
            }
        }

        visited.erase(current_node);
        return current_ans;
    }
};
