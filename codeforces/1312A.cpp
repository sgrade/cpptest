// A. Two Regular Polygons

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int n, m;
        scanf("%d %d\n", &n, &m);

        if (n%m == 0) printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}