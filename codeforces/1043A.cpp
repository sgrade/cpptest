// A. Elections

#include <iostream>
#include <algorithm>
#include <numeric>


int main(){

    int n;
    std::cin >> n;

    int a[n];
    for (auto &el: a) std::cin >> el;

    int votesOpponent = std::accumulate(a, a+n, 0);
    int k = *(std::max_element(a, a+n));

    while(true){
        int votesAwruk = 0;
        for (auto el: a) votesAwruk += k - el;
        if (votesAwruk > votesOpponent) break;
        else ++k;
    }

    std::cout << k << std::endl;

    return 0;
}
