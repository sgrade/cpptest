// A. Candies

#include <iostream>
#include <math.h>
#include <numeric>


int main(){

    int t;
    std::cin >> t;

    while (t--){

        int n;
        std::cin >> n;

        int x=0;
        // x*(1+2+4+...) = n
        // x*sum = n;
        
        bool found = false;
        int k = (int)log2(n+1);
        // printf("n: %d, LOG: %d\n", n, kMax);
        while (k--){
            ++x;
            if (n/(pow(2,k)-1) == x){

            }
        }
        

        std::cout << x << std::endl;

    }
    return 0;
}