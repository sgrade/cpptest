// B. Maximum Product

#include <iostream>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);
        int a[n];

        for (int i=0; i<n; ++i){
            scanf("%d", &(a[i]));
        }
        scanf("\n");

        std::sort(a, a+n);

        int numOfNegatives = 0;
        int factors[5];
        std::fill(factors, factors+5, 1);

        int forwIt=0;
        int backIt=n-1;
        // first 4
        for (int i=0; i<4; ++i){

            factors[i] = std::max(abs(a[forwIt]), abs(a[backIt]));
            if (factors[i] == abs(a[forwIt])){
                factors[i] = a[forwIt];
                ++forwIt;
            }
            else {
                factors[i] = a[backIt];
                --backIt;
            }
            if (factors[i] < 0) ++numOfNegatives;
        }

        if (numOfNegatives%2 != 0){
            factors[4] = a[forwIt];
        }
        else factors[4] = a[backIt];

        long long output=1;
        for (auto it: factors){
            output *= (long long)it;
        }

        std::cout << output << std::endl;

    }

    return 0;
}