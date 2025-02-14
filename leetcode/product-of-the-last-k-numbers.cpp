// 1352. Product of the Last K Numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach: Prefix Product
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        prefix_product.emplace_back(1);
    }
    
    void add(int num) {
        if (num == 0)
            prefix_product.resize(1, 1);
        else
            prefix_product.emplace_back(prefix_product.back() * num);
    }
    
    int getProduct(int k) {
        if (k > prefix_product.size() - 1)
            return 0;
        return prefix_product.back() / prefix_product[prefix_product.size() - 1 - k];
    }

private:
    vector<int> prefix_product;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
