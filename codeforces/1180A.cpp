// A. Alex and a Rhombus

#include <stdio.h>
#include <algorithm>


int dp(int n){
    
    // to ease indexing, i=n, thus array length is n+1;
    int a[n+1];
    std::fill(a, a+n+1, 0);
    a[1] = 1;
    a[2] = 5;

    if (a[n]!=0) return a[n];

    else {
        for (int i=3; i<n+1; ++i){
            // prevous: a[i-1]
            // poles: 4
            // non-poles: (a[i-1] - a[i-2])
            a[i] = a[i-1] + 4 + (a[i-1] - a[i-2]);
        }
    }
    return a[n];
}

int main(){

    int n;
    scanf("%d\n", &n);

    printf("%d\n", dp(n));

    return 0;
}