// A. Declined Finalists

#include <iostream>
#include <algorithm>

int main(){

    int k;
    std::cin >> k;

    int r[k];
    for (auto &el: r) std::cin >> el;

    std::sort(r, r+k);

    std::cout << std::max(0, r[k-1] - 25) << std::endl;

    return 0;
}
