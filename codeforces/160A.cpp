// A. Twins

#include <iostream>     // std::cout
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include <numeric>      // std::accumulate


int main(){

    int n;
    scanf("%d\n", &n);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d", &(a[i]));
    }

    int half = std::accumulate(a, a+n, 0) / 2;
    std::sort(a, a+n, std::greater<int>());

    int coins = 0;
    int myMoney = 0;
    for(int i=0; i<n; ++i){
        myMoney += a[i];
        coins ++;
        if (myMoney > half) break;
    }

    printf("%d\n", coins);

    return 0;
}