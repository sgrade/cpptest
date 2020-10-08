// A. Orac and Factors

#include <iostream>
#include <math.h>

using namespace std;


// Smallest divisor
// http://codewordblog.blogspot.com/2011/08/algorithm-to-find-smallest-divisor-of.html
// https://www.geeksforgeeks.org/smallest-prime-divisor-of-a-number/

int smallestDivisor (int a){  
    
    // We skip a=1, because it is not allowed in the task
    for (int i=2; i*i<=a; ++i){
        if (a % i == 0) {
            return  i;
        }
    }
    return a;
}

int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n, k;
        scanf("%d %d\n", &n, &k);

        // https://codeforces.com/blog/entry/77284
        if (n%2 == 0){
            n += 2*k;
        }
        else {
            n += smallestDivisor(n) + 2*(k-1);
        }

        printf("%d\n", n);
    }

    return 0;
}



/* 
//Time limit exceeded

int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){
        int n, k;
        scanf("%d %d\n", &n, &k);

        while(k--){
            n += smallestDivisor(n);
        }

        printf("%d\n", n);
    }

    return 0;
}
*/

