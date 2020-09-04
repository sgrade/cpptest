// A. System of Equations

#include <stdio.h>


int main(){

    int n, m;
    scanf("%d %d\n", &n, &m);


    int pairs = 0;

    bool first = false;
    bool second = false;

    for (int a=0; a<=n; ++a){
        for (int b=0; b<=m; ++b){
            first = true ? a*a+b==n : false;
            second = true ? a+b*b==m : false;
            if (first && second) ++pairs;
        }
    }

    printf("%d\n", pairs);

    return 0;
}