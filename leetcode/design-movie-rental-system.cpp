// 1912. Design Movie Rental System
// https://leetcode.com/problems/design-movie-rental-system/

#include <bits/stdc++.h>

using namespace std;


// Does not work!
class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        total_shops = n;
        for (const vector<int>& e: entries) {
            int shop = e[0], movie = e[1], price = e[1];
            movie_to_price_shop[movie].emplace(price, shop);
            available[movie][shop] = price;
        }
    }
    
    vector<int> search(int movie) {
        unordered_map<int, multiset<pair<int, int>>>::iterator m_it = movie_to_price_shop.find(movie);
        if (m_it == movie_to_price_shop.end()) {
            return {};
        }  
        multiset<pair<int, int>>::iterator ps_it = m_it->second.begin();
        vector<int> shops;
        int i = 0;
        while (i < 5 && ps_it != m_it->second.end()) {
            auto [price, shop] = *ps_it;
            shops.emplace_back(shop);
            ++ps_it;
            ++i;
        }
        return shops;
    }

    void rent(int shop, int movie) {
        int price = available[movie][shop];
        available[movie].erase(shop);
        rented[movie][shop] = price;
        movie_to_price_shop[movie].erase({price, shop});
        AddToReport(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
        int price = rented[movie][shop];
        rented[movie].erase(shop);
        available[movie][shop] = price;
        movie_to_price_shop[movie].emplace(price, shop);
        RemoveFromReport(price, shop, movie);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> r;
        priority_queue<pair<int, pair<int, int>>> tmp;
        while (!rep.empty()) {
            pair<int, pair<int, int>> top = rep.top();
            int shop = top.second.first, movie = top.second.second;
            r.emplace_back(vector<int>{shop, movie});
            tmp.emplace(top);
        }
        rep = tmp;
        return r;
    }

private:
    int total_shops;
    // movie -> [price, shop]
    unordered_map<int, multiset<pair<int, int>>> movie_to_price_shop;
    // movie -> shop -> price
    unordered_map<int, unordered_map<int, int>> available;
    unordered_map<int, unordered_map<int, int>> rented;
    // price -> [shop, movie];
    priority_queue<pair<int, pair<int, int>>> rep;

    void AddToReport (int price, int shop, int movie) {
        if (rep.size() < 5) {
            rep.emplace(price, pair<int, int>(shop, movie));
            return;
        }
        int top_price = rep.top().first;
        
        if (top_price > price) {
            rep.pop();
            rep.emplace(price, pair<int, int>(shop, movie));
            return;
        }

        // if (top_price == price)
        vector<pair<int, int>> tmp;
        tmp.emplace_back(shop, movie);
        while (!rep.empty() && rep.top().first == price) {
            tmp.emplace_back(rep.top().second);
            rep.pop();
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size() - 1; ++i) {
            rep.emplace(price, pair<int, int>(tmp[i].first, tmp[i].second));
        }
    }

    void RemoveFromReport (int price, int shop, int movie) {
        priority_queue<pair<int, pair<int, int>>> tmp;
        bool need_replacement = false;
        while (!rep.empty()) {
            pair<int, pair<int, int>> top = rep.top();
            int pr = top.first;
            int sh = top.second.first;
            int mv = top.second.second;
            if (price == pr && shop == sh && movie == mv) {
                need_replacement = true;
                continue;
            }
            tmp.emplace(top);
        }
        if (need_replacement) {
                if (!rented.empty()) {
                int pr = rented.begin()->first;
                int sh = rented.begin()->second.first;
                int mv = rented.begin()->second.second;
                tmp.emplace(pr, pair<int, int>(sh, mv));
            }
        }
        rep = tmp;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        total_shops = n;
        for (const vector<int>& e: entries) {
            int shop = e[0], movie = e[1], price = e[1];
            movie_to_price_shop[movie].emplace(price, shop);
            available[movie][shop] = price;
        }
    }
    
    vector<int> search(int movie) {
        unordered_map<int, multiset<pair<int, int>>>::iterator m_it = movie_to_price_shop.find(movie);
        if (m_it == movie_to_price_shop.end()) {
            return {};
        }  
        multiset<pair<int, int>>::iterator ps_it = m_it->second.begin();
        vector<int> shops;
        int i = 0;
        while (i < 5 && ps_it != m_it->second.end()) {
            auto [price, shop] = *ps_it;
            shops.emplace_back(shop);
            ++ps_it;
            ++i;
        }
        return shops;
    }

    void rent(int shop, int movie) {
        int price = available[movie][shop];
        available[movie].erase(shop);
        rented[movie][shop] = price;
        movie_to_price_shop[movie].erase({price, shop});
        AddToReport(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
        int price = rented[movie][shop];
        rented[movie].erase(shop);
        available[movie][shop] = price;
        movie_to_price_shop[movie].emplace(price, shop);
        RemoveFromReport(price, shop, movie);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> r;
        priority_queue<pair<int, pair<int, int>>> tmp;
        while (!rep.empty()) {
            pair<int, pair<int, int>> top = rep.top();
            int shop = top.second.first, movie = top.second.second;
            r.emplace_back(vector<int>{shop, movie});
            tmp.emplace(top);
        }
        rep = tmp;
        return r;
    }

private:
    int total_shops;
    // movie -> [price, shop]
    unordered_map<int, multiset<pair<int, int>>> movie_to_price_shop;
    // movie -> shop -> price
    unordered_map<int, unordered_map<int, int>> available;
    unordered_map<int, unordered_map<int, int>> rented;
    // price -> [shop, movie];
    priority_queue<pair<int, pair<int, int>>> rep;

    void AddToReport (int price, int shop, int movie) {
        if (rep.size() < 5) {
            rep.emplace(price, pair<int, int>(shop, movie));
            return;
        }
        int top_price = rep.top().first;
        
        if (top_price > price) {
            rep.pop();
            rep.emplace(price, pair<int, int>(shop, movie));
            return;
        }

        // if (top_price == price)
        vector<pair<int, int>> tmp;
        tmp.emplace_back(shop, movie);
        while (!rep.empty() && rep.top().first == price) {
            tmp.emplace_back(rep.top().second);
            rep.pop();
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size() - 1; ++i) {
            rep.emplace(price, pair<int, int>(tmp[i].first, tmp[i].second));
        }
    }

    void RemoveFromReport (int price, int shop, int movie) {
        priority_queue<pair<int, pair<int, int>>> tmp;
        bool need_replacement = false;
        while (!rep.empty()) {
            pair<int, pair<int, int>> top = rep.top();
            int pr = top.first;
            int sh = top.second.first;
            int mv = top.second.second;
            if (price == pr && shop == sh && movie == mv) {
                need_replacement = true;
                continue;
            }
            tmp.emplace(top);
        }
        if (need_replacement) {
                if (!rented.empty()) {
                int pr = rented.begin()->first;
                int sh = rented.begin()->second.first;
                int mv = rented.begin()->second.second;
                tmp.emplace(pr, pair<int, int>(sh, mv));
            }
        }
        rep = tmp;
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
