// A. Vasya and Socks

#include <iostream>


int main(){

    int n, m;
    std::cin >> n >> m;

    int days = n;
    while (n/m >= 1) {
        days += n/m;
        n = n/m + n%m;
    }
    std::cout << days << std::endl;

    return 0;
}