// A. Devu, the Singer and Churu, the Joker

#include <iostream>
#include <numeric>


int main(){

    int n, d;
    std::cin >> n >> d;

    int t[n];
    for (auto &el: t) std::cin >> el;

    int ans = -1;

    int songs = std::accumulate(t, t+n, 0);
    int rest = (n - 1) * 10;

    if (songs + rest <= d){
        ans = (d - songs) / 5;
    }
    
    std::cout << ans << std::endl;

    return 0;
}
