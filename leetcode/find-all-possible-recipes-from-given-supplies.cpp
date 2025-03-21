// 2115. Find All Possible Recipes from Given Supplies
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Topological Sort (Kahn's Algorithm)
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_set<string> available_supplies;
            for (const string& s: supplies)
                available_supplies.emplace(s);

            unordered_map<string, int> recipe_to_idx;
            for (int i = 0; i < recipes.size(); ++i)
                recipe_to_idx[recipes[i]] = i;

            unordered_map<string, vector<string>> deps;
            vector<int> indegree(recipes.size());
            for (int i = 0; i < recipes.size(); ++i) {
                for (const string& ingredient: ingredients[i]) {
                    if (available_supplies.find(ingredient) == available_supplies.end()) {
                        deps[ingredient].emplace_back(recipes[i]);
                        ++indegree[i];
                    }
                }
            }

            queue<int> q;
            for (int i = 0; i < recipes.size(); ++i) {
                if (indegree[i] == 0)
                    q.emplace(i);
            }

            vector<string> ans;
            while (!q.empty()) {
                int recipe_idx = q.front();
                q.pop();
                string recipe = recipes[recipe_idx];
                ans.emplace_back(recipe);
                if (deps.find(recipe) == deps.end())
                    continue;
                for (const string& dep: deps[recipe]) {
                    if (--indegree[recipe_to_idx[dep]] == 0)
                        q.emplace(recipe_to_idx[dep]);
                }
            }
            return ans;
        }
    };
