// A. Young Physicist

#include <stdio.h>


int main(){

    int n;
    scanf("%d\n", &n);

    int x=0, y=0, z=0;

    int tmpX=0, tmpY=0, tmpZ=0;
    while(n--){
        scanf("%d %d %d\n", &tmpX, &tmpY, &tmpZ);
        x += tmpX;
        y += tmpY;
        z += tmpZ;
    }

    if (x==0 && y==0 && z==0) printf("YES\n");
    else printf("NO\n");

    return 0;
}