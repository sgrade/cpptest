// A. Lucky Division

#include <stdio.h>

int main(){

    int lucky[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    int n;
    scanf("%d\n", &n);

    for (int i=0; i<14; ++i){
        if (n % lucky[i] ==0){
            printf("YES\n");
            break;
        }
        else if (n < lucky[i] || i==13) {
            printf("NO\n");
            break;
        }
    }

    return 0;
}