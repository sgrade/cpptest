// A. Book Reading

#include <iostream>


int main(){

    int n, t;
    std::cin >> n >> t;

    int ans = 0;
    
    int a[n];
    for(auto &el: a) {
        std::cin >> el;
        t -= 86400 - el;
        ans += 1;
        if (t <=0 ) break;
    }

    std::cout << ans;

    return 0;
}
