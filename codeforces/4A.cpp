// Watermelon

#include <stdio.h>

int main(){
    int w;
    scanf("%d", &w);

    // Base cases
    if (w==0 || w==2){
        printf("NO");
        return 0;
    }
    
    // Sum of any even number is always even
    if (w %2 == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}
