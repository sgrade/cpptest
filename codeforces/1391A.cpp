// A. Suborrays

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        int i=1;
        for (; i<n; ++i) printf("%d ", i);
        printf("%d\n", i);

    }

    return 0;
}