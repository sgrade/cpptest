// B. Multiply by 2, divide by 6

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        int output=0;
        if (n==1) output = 0;
        else {
            while (n != 1){
                if (n%3 != 0){
                    output = -1;
                    break;
                }   
                else if (n%6==0) n /= 6;
                else n *= 2;
                ++output;
            }
        }

        printf("%d\n", output);
    }

    return 0;
}
