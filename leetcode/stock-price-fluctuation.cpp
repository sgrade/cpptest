// 2034. Stock Price Fluctuation 
// https://leetcode.com/problems/stock-price-fluctuation/

#include <bits/stdc++.h>

using namespace std;


// Not finished (Leetcode debugger doesn't work at the moments)
class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        auto it = ts_to_price.find(timestamp);
        if (it != ts_to_price.end()) {
            price_to_ts.erase(pair<int, int>(it->second, it->first));
            price_to_ts.emplace(price, timestamp);
        }
        ts_to_price[timestamp] = price;
        current_price = price;
    }
    
    int current() {
        return current_price;
    }
    
    int maximum() {
        return price_to_ts.rbegin()->first;
    }
    
    int minimum() {
        return price_to_ts.begin()->first;
    }

private:
    unordered_map<int, int> ts_to_price;
    set<pair<int, int>> price_to_ts;
    int current_price = numeric_limits<int>::max();
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
