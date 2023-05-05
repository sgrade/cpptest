// 2034. Stock Price Fluctuation 
// https://leetcode.com/problems/stock-price-fluctuation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Hashmap and Heaps
class StockPrice {
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        ts_to_price[timestamp] = price;
        if (timestamp >= current_timestamp) {
            current_price = price;
            current_timestamp = timestamp;
        }
        max_heap.emplace(price, timestamp);
        min_heap.emplace(price, timestamp);
    }
    
    int current() {
        return current_price;
    }
    
    int maximum() {
        auto& [price, timestamp] = max_heap.top();
        while (ts_to_price[timestamp] != price) {
            max_heap.pop();
            auto& [price, timestamp] = max_heap.top();
        }
        return price;
    }
    
    int minimum() {
        auto& [price, timestamp] = min_heap.top();
        while (ts_to_price[timestamp] != price) {
            min_heap.pop();
            auto& [price, timestamp] = min_heap.top();
        }
        return price;
    }

private:
    unordered_map<int, int> ts_to_price;
    // pair<timestamp, price>
    priority_queue<pair<int, int>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    int current_price = numeric_limits<int>::max();
    int current_timestamp = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */