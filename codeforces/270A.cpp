// A. Fancy Fence

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int a;
        scanf("%d\n", &a);

        // https://en.wikipedia.org/wiki/Regular_polygon#Angles
        if (360%(180-a)==0){
            printf("YES\n");
        }
        else printf("NO\n");

    }

    return 0;
}