// B. Team Composition: Programmers and Mathematicians

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int a, b;
        std::cin >> a >> b;

        // Editorial - https://codeforces.com/blog/entry/97288

        // Teams of 1 + 3
        int ans = std::min(a, b);
        
        // Teams of 2 + 2
        ans = std::min(ans, (a + b) / 4);

        std::cout << ans << std::endl;
    }

    return 0;
}
