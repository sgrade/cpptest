// A. A pile of stones

#include <iostream>
#include <algorithm>
#include <string>

int main(){

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int ans = 0;
    for (auto el: s){
        if (el == '+') ++ans;
        else ans = std::max(0, --ans);
    }

    std::cout << ans << std::endl;

    return 0;
}
