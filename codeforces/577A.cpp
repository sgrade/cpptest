// A. Multiplication Table

#include <iostream>


int main(){

    int n, x;
    std::cin >> n >> x;

    int output = 0;

    // Editorial - https://codeforces.com/blog/entry/20226
    for (int i=1; i<n+1; ++i){
        if (x%i ==0 && x/i <= n){
            output += 1;
        }
    }

    std::cout << output << std::endl;

    return 0;
}
