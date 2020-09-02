// B. Teams Forming

#include <stdio.h>
#include <algorithm>


int main(){

    int n;
    scanf ("%d\n", &n);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d", &(a[i]));
    }

    std::sort(a, a+n);

    int problems = 0;
    for (int i=1; i<n; i+=2){
        problems += abs(a[i]-a[i-1]);
    }

    printf("%d\n", problems);

    return 0;
}