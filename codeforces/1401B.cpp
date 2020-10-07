// B. Ternary Sequence

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int zeros1, ones1, twos1, zeros2, ones2, twos2;
        scanf("%d %d %d\n", &zeros1, &ones1, &twos1);
        scanf("%d %d %d\n", &zeros2, &ones2, &twos2);

        int ans = 0;

        // maximize "+"
        if (twos1 >= ones2) {
            ans += ones2 * 2;
            twos1 -= ones2;
            ones2 = 0;
            
        }
        else {
            ans += twos1 * 2;
            ones2 -= twos1;
            twos1 = 0;
        }
        
        // minimize chance for "-" to occur
        if (ones1 >= zeros2){
            ones1 -= zeros2;
            zeros2 = 0;
        }
        else {
            zeros2 -= ones1;
            ones1 = 0;
        }

        if (ones1 >= ones2){
            ones1 -= ones2;
            ones2 = 0;
        }
        else {
            ones2 -= ones1;
            ones1 = 0;
        }


        if (zeros1 >= twos2){
            zeros1 -= twos2;
            twos2 = 0;
        }
        else {
            twos2 -= zeros1;
            zeros1 = 0;
        }

        if (twos1 >= twos2){
            twos1 -= twos2;
            twos2 = 0;
        }
        else {
            twos2 -= twos1;
            twos1 = 0;
        }

        ans -+ ones1 * twos2;
        
        printf("%d\n", ans);

    }

    return 0;
}