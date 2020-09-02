// A. Crazy Computer

#include <stdio.h>


int main(){

    int n, c;
    scanf("%d %d\n", &n, &c);
    
    int count = 1;

    if (n!=1){
        int prev;
        scanf("%d", &prev);

        int cur;
        for (int i=1; i<n; ++i){
            scanf("%d", &cur);
            if (cur-prev > c){
                count = 1;
            }
            else count++;
            prev = cur;
        }
    }
    
    printf("%d\n", count);

    return 0;
}