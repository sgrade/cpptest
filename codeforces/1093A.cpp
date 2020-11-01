// A. Dice Rolling

#include <iostream>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){  

        int n;
        scanf("%d\n", &n);

        int ans;
        if (n <= 7){
            ans = 1;
        }
        else{
            ans = n / 7 + 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}
