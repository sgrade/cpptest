// A. Non-zero

#include <stdio.h>
#include <algorithm>
#include <numeric>


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

        std::sort(a, a+n);

        int steps=0;
        
        int sum = std::accumulate(a, a+n, 0);
        // The product will be not zero if there is no zeros in the array
        int numOfZeros = std::count(a, a+n, 0);
        
        if (numOfZeros!=0){
            steps += numOfZeros;
            sum += numOfZeros;
        }

        if (sum==0){
            steps += 1;
        }

        printf("%d\n", steps);

    }

    return 0;
}