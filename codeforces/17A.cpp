// A. Noldbach problem

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>


int isPrime(int n){
    if (n == 0 || n == 1) return false;
    for (int i = 2; i<=sqrt(n); ++i){
        if (n % i == 0) return false;
    }
    return true;
}


int main(){

    int n, k;
    scanf("%d %d\n", &n, &k);

    bool ans = false;

    if (k == 0) ans = true;
    else{

        std::vector<int> primes;
        for (int i = 2; i < n+1; ++i){
            if (isPrime(i)) primes.push_back(i);
        }
        
        if (primes.size() > 2){
            sort (primes.begin(), primes.end(), std::greater<int>());

            auto found = std::find(primes.begin(), primes.end(), n);
            int i;
            if (found == primes.end()) i = 0;
            else i = distance(primes.begin(), found);
            for (; i < primes.size() - 2; ++i){
                for (int j = i+1; j < primes.size()-1; ++j){
                    if (primes[i] == 1 + primes[j] + primes[j+1]){
                    --k;
                    }
                }
                if (k <= 0){
                    ans = true;
                    break;
                }
            }
        }
    }

    printf("%s\n", (ans ? "YES" : "NO"));

    return 0;
}
