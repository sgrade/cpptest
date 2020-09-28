// A. Floor Number

#include <stdio.h>

int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n, x;
        scanf("%d %d\n", &n, &x);

        int output = 1;
        if (n>2){
            n -= 2;

            output += n/x;
            if (n%x != 0) ++output;
        }

        printf("%d\n", output);

    }

    return 0;
}