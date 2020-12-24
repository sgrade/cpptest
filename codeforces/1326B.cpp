// B. Maximums

#include <iostream>
#include <vector>


int main(){

    int n;
    std::cin >> n;

    std::vector<long long> b(n), a(n);
    for (auto &el: b) std::cin >> el;

    a[0] = b[0];
    long long curMax = b[0];

    for (int i = 1; i < n; ++i){
        a[i] = b[i] + curMax;
        if (a[i] > curMax) curMax = a[i];
    }

    for (auto el: a) std::cout << el << ' ';
    std::cout << std::endl;

    return 0;
}
