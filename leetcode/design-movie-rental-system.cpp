// 1912. Design Movie Rental System
// https://leetcode.com/problems/design-movie-rental-system/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/design-movie-rental-system/solutions/7209446/most-efficient-bineary-search-tree-java-python-c-javascript-beat-100
struct Item {
    int shop, movie, price;
    bool operator < (const Item& candidate) const {
        if (price != candidate.price) {
            return price < candidate.price;
        }
        if (shop != candidate.shop) {
            return shop < candidate.shop;
        }
        return movie < candidate.movie;
    }
};

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const vector<int>& e: entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Item item{shop, movie, price};
            long long key = GetKey(shop, movie);
            shop_movie_to_item[key] = item;
            available[movie].emplace(item);
        }
    }
    
    vector<int> search(int movie) {
        if (available.find(movie) == available.end()) {
            return {};
        }
        vector<int> ans;
        set<Item>& items = available[movie];
        int i = 0;
        for (auto it = items.begin(); it != items.end() && i < 5; ++it, ++i) {
            ans.emplace_back(it->shop);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        long long key = GetKey(shop, movie);
        Item item = shop_movie_to_item[key];
        available[movie].erase(item);
        rented.insert(item);
    }
    
    void drop(int shop, int movie) {
        long long key = GetKey(shop, movie);
        Item item = shop_movie_to_item[key];
        rented.erase(item);
        available[movie].emplace(item);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; ++it, ++i) {
            ans.emplace_back(vector<int>{it->shop, it->movie});
        }
        return ans;
    }

private:
    unordered_map<long long, Item> shop_movie_to_item;
    unordered_map<int, set<Item>> available;
    set<Item> rented;

    long long GetKey (int shop, int movie) {
        return ((long long)shop << 32) ^ movie;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
