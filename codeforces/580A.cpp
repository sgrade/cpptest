// A. Kefa and First Steps

#include <stdio.h>


int main(){

    int n;
    scanf("%d\n", &n);
    
    int maxLen = 1;

    int prev, cur=0;
    scanf("%d", &prev);
        
    int len = 1;
    for (int i=1; i<n; ++i){
        scanf("%d", &cur);
        if (cur>=prev){
            len +=1;
        }
        if (cur<prev || i==n-1){
            if (len > maxLen) {
                maxLen = len;
            }
            len = 1;
        }
        prev = cur;
    }

    printf("%d\n", maxLen);

    return 0;
}