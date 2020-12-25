// A. Duff and Meat

#include <iostream>


int main(){

    int n;
    std::cin >> n;

    int ans = 0; 
    int currentMin = 100;

    int ai, pi;
    while(n--){
        std::cin >> ai >> pi;
        if (pi < currentMin) currentMin = pi;
        ans += currentMin * ai;
    }

    std::cout << ans << std::endl;

    return 0;
}
