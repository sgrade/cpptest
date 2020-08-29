// A. Maximum Increase

#include <iostream>


int main(){

    int n;
    scanf("%d\n", &n);

    if (n==1){
        printf("1\n");
        exit(0);
    }

    int arr[n], tmp;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    int MaxLen=1, curMaxLen=1;
    for (int i=1; i<n; ++i){
        if (arr[i-1] < arr[i]){
            curMaxLen += 1;
        }
        else {
            if (curMaxLen > MaxLen) MaxLen = curMaxLen;
            curMaxLen = 1;
        }
    }

    if (curMaxLen > MaxLen) MaxLen = curMaxLen;
    printf("%d\n", MaxLen);

    return 0;
}