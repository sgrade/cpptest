// A. The number of positions

#include <iostream>
#include <algorithm>


int main(){

    int n, a, b;
    std::cin >> n >> a >> b;

    // Solution from https://codeforces.com/blog/entry/3047?#comment-226570
    std::cout << std::min(n - a, b + 1) << std::endl;

    return 0;
}
