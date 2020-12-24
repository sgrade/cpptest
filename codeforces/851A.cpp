// A. Arpa and a research in Mexican wave

#include <iostream>
#include <algorithm>


int main(){

    int n, k, t;
    std::cin >> n >> k >> t;

    int ans = std::min(k, t);
    if (t > n){
        ans = (k - (t-n));
    }

    std::cout << ans << std::endl;

    return 0;
}
