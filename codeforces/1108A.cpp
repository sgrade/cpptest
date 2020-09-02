// A. Two distinct points

#include <stdio.h>


int main(){

    int q;
    scanf("%d\n", &q);

    while (q--){

        int l1, r1, l2, r2;
        scanf("%d %d %d %d\n", &l1, &r1, &l2, &r2);

        if (l1!=r2) printf("%d %d\n", l1, r2);
        else printf("%d %d\n", r1, l2);

    }

    return 0;
}
