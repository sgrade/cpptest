//  A. The Way to Home

#include <iostream>
#include <string>
#include <algorithm>


int main(){

    int n, d;
    std::cin >> n >> d;
    std::string s;
    getline(std::cin >> std::ws, s);

    int a[n];
    for(auto &el: a) std::cin >> el;

    int ans = 0, i = 0;
    while(i < n-1){
        auto x = s.substr(0, i+d+1).find_last_of('1');
        if(x != std::string::npos && x != i){
            i = x;
            ans += 1;
        }
        else {
            ans = -1;
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
