// A. Little Artem and Presents

#include <iostream>


int main(){

    int n;
    std::cin >> n;

    int ans = (n / 3) * 2;
    if (n % 3 != 0) ans += 1;

    std::cout << ans << std::endl;

    return 0;
}
