// A. Johny Likes Numbers

#include <iostream>


int main(){

    int n, k;
    std::cin >> n >> k;

    if (n % k == 0) std::cout << n + k;
    else std::cout << (((n + k - 1) / k) * k);
    std::cout << std::endl;

    return 0;
}
