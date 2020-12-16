// A. Local Extrema

#include <iostream>


int main(){

    int n;
    std::cin >> n;

    int a[n];
    for (auto &el: a) std::cin >> el;

    int ans = 0;

    if (n > 2){
        for (int i=1; i < n-1; ++i){
            if (a[i-1] < a[i] && a[i+1] < a[i]) ++ans;
            else if (a[i-1] > a[i] && a[i+1] > a[i]) ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
