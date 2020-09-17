// B. Interesting drink

#include <stdio.h>
#include <map>

using namespace std;


int main(){

    int n;
    scanf("%d\n", &n);

    // key: value   is  
    // price: number of shops with the same price
    map<int, long long> mp;
    int price;
    for (int i=0; i<n; ++i){
        scanf("%d", &price);
        ++mp[price];
    }
    scanf("\n");

    // summarizing the shops only once, so
    // key: value    is
    // price: number of shops with the same or lower price
    long long tmpShops = 0;
    for (auto it: mp){
        tmpShops += it.second;
        mp[it.first] = tmpShops;
    }

    // iterating through the days
    int q;
    scanf("%d\n", &q);
    long long shops=0;
    int coins;
    for (int i=0; i<q; ++i){
        scanf("%d\n", &coins);
        // it will have price "greater than" coins, so we know for sure that the shops are in -1 from the it;
        // NOTE: if I used lower_bound, it would give "not less then", 
        // so we would need additional comparison "if equal" (current it) or less (-1 from the it);
        auto it = mp.upper_bound(coins);
        if (it == mp.begin()){
            shops = 0;
        }
        else {
            --it;
            shops = it -> second;
        }
        printf("%lld\n", shops);
    }

    return 0;
}