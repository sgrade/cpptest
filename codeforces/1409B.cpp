// B. Minimum Product

#include <stdio.h>
#include <algorithm>
#include <limits>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        long long a, b, x, y, n;
        scanf("%lld %lld %lld %lld %lld\n", &a, &b, &x, &y, &n);        

        // Editorial - https://codeforces.com/blog/entry/82284
        long long int product = std::numeric_limits<long long int>::max();

        int i=2;
        while (i--){

            long long aDiff = std::min(n, a-x);        
            long long bDiff = std::min(n-aDiff, b-y);
            long long product1 = (a-aDiff) * (b-bDiff);

            product = std::min(product, product1);

            std::swap(a, b);
            std::swap(x, y);

        }
            
        printf("%lld\n", product);

    }

    return 0;
}