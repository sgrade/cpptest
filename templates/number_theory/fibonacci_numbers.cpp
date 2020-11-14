// List of Fibonacci numbers up to n
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include <stdio.h>
#include <vector>


std::vector<unsigned long long> fibNumbers(unsigned long long n){
    std::vector<unsigned long long> f = {0};
    if (n == 0) return f;
    f.push_back(1);
    for (unsigned long long i = 2; i < n + 1; ++i){
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return f;
}


int main(){

    unsigned long long n = 6;
    std::vector<unsigned long long> f = fibNumbers(n);
    for(auto el: f){
        printf("%llu ", el);
    }
    printf("\n");

    return 0;
}
