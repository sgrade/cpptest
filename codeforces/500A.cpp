// A. New Year Transportation

#include <stdio.h>


int main(){

    int n, t;
    scanf("%d %d\n", &n, &t);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d\n", &(a[i]));
    }

    bool iCan = false;
    int i=1;
    while(true){
        if (i==t){
            iCan = true;
            break;
        }
        else if (i>t){
            break;
        }
        else{
            i+=a[i-1];
        }
    }

    printf("%s\n", (iCan ? "YES" : "NO"));

    return 0;
}