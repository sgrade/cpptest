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

        // https://www.yaklass.ru/p/algebra/9-klass/progressii-9139/geometricheskaia-progressiia-9142/re-1cea80c1-2bde-4270-a473-6b6d81ad228d
        // Check sum of first n members of geometric progression
        // Changed n to k in the formula (to avoid confusion with our task)
        // Sn = b1 * (q^k -1) / q-1
        // Sn = 1 * (2^k - 1) / 2-1
        // Sn = 2^k - 1
        // 
        // So, in our task:
        // n = x* (2^k - 1)
        // k is max, when x = 1
        // n = 2^kMax - 1
        // n+1 = 2^kMax
        int kMax = (int)log2(n+1);
        // printf("n: %d, LOG: %d\n", n, kMax);

        for(int k=2; k<kMax+1; ++k){
            int sum = (int)pow(2,k) - 1;
            //std::cout << sum << std::endl;
            if (n % sum == 0){
                x = n/sum;
                break;
            }
        }
        

        std::cout << x << std::endl;

    }
    return 0;
}