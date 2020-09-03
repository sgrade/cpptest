// A. Choose Two Numbers

#include <stdio.h>
#include <algorithm>


int main(){

    int n;
    scanf("%d\n", &n);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d", &(a[i]));
    }

    int m;
    scanf("%d\n", &m);

    int b[m];
    for (int i=0; i<m; ++i){
        scanf("%d", &(b[i]));
    }

    std::sort(a, a+n);
    std::sort(b, b+m);

    printf("%d %d\n", a[n-1], b[m-1]);

    return 0;
}
