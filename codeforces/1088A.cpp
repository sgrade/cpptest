// A. Ehab and another construction problem

#include <stdio.h>


int main(){

    int x;
    scanf("%d\n", &x);

    bool found = false;

    for (int b = x; b > 0; --b){
        for (int a = b; !found && a > 0; --a){
            if (b % a == 0 && a * b > x && a / b < x){
                printf("%d %d\n", a, b);
                found = true;
                break;
            }
        }
    }

    if (!found) printf("-1\n");

    return 0;
}
