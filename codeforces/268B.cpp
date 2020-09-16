// B. Buttons

#include <stdio.h>


int main(){

    int n;
    scanf("%d\n", &n);

    int output = 0;
    // Editorial - https://codeforces.com/blog/entry/6545
    for (int i=1; i<=n; ++i){
        output += (n-i)*i;
    }
    output += n;
    
    printf("%d\n", output);

    return 0;
}