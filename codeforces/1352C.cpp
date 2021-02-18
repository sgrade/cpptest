// C. K-th Not Divisible by n

#include <iostream>


int main(){

    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        // Key ideas from https://www.youtube.com/watch?v=sV7_NlVMLE0
        int x = k / (n - 1);
        int remain = k - x * (n - 1);
        if (remain == 0) std::cout << n * x - 1 << std::endl;
        else std::cout << n * x + remain << std::endl;
    }

    return 0;
}
