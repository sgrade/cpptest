// A. Free Ice Cream

#include <stdio.h>


int main(){

    int n;
    long long x;
    scanf("%d %lld\n", &n, &x);

    int chInDistress = 0;
    while (n--){

        char plusMin;
        int quantity;
        scanf("%c %d\n", &plusMin, &quantity);

        if (plusMin == '+')
            x += quantity;
        else {
            if (x-quantity < 0) 
            {
            chInDistress += 1;
            }
            else x -= quantity;
        }

    }

    printf("%lld %d\n", x, chInDistress);

    return 0;
}
