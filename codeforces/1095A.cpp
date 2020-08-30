// A. Repeating Cipher

#include <stdio.h>


int main(){

    int n;
    char ch;
    scanf("%d\n", &n);

    int count = 0;
    while (n--){
        
        scanf("%c", &ch);

        for (int i=0; i<count; ++i)
            scanf("%c", &ch);

        count++;

        printf("%c", ch);
    }
    
    return 0;
}