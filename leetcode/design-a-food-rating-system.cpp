// 2353. Design a Food Rating System
// https://leetcode.com/problems/design-a-food-rating-system/

#include <bits/stdc++.h>

using namespace std;


// Used ideas from Editorial's Approach 1: Hash Maps and Priority Queue
struct sComp {
    bool operator() (const pair<int, string>& left, const pair<int, string>& right)
    {
        if (left.first == right.first)
            return left.second > right.second;
        return left.first < right.first;
    }
};

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for (int i = 0; i < n; ++i) {
            f[foods[i]] = pair<string, int>(cuisines[i], ratings[i]);
            c[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        f[food].second = newRating;
        string cuisine = f[food].first;
        c[cuisine].emplace(newRating, food);
    }

    string highestRated(string cuisine) {
        int rating = c[cuisine].top().first;
        string food = c[cuisine].top().second;
        while (rating != f[food].second) {
            c[cuisine].pop();
            rating = c[cuisine].top().first;
            food = c[cuisine].top().second;
        }
        return food;
    }

private:
    int n;
    // food: <cuisine, rating>
    unordered_map<string, pair<string, int>> f;
    // cuisines: <rating, food>
    unordered_map<string, priority_queue< pair<int, string>, vector<pair<int, string>>, sComp>> c;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
